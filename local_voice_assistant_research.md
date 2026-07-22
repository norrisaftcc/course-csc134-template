# Building a Local Siri-Style Voice Assistant in Flask/Python: A CSC-114 Capstone Planning Guide (Intel vs. Apple Silicon)

## TL;DR
- **A fully local STT→LLM→TTS voice assistant is realistic for a multi-week CSC-114 capstone**, and the most reliable cross-platform stack for a mixed class of 8–16GB Intel Windows laptops and Apple Silicon MacBooks is: **browser front-end (mic capture + audio playback) → Flask backend → faster-whisper (STT) → Ollama serving Llama 3.2 3B (LLM) → Piper (TTS)**. Ollama exposes an OpenAI-compatible endpoint, so students hit it with a two-line code change.
- **Architecture matters more than any single component.** Apple Silicon's unified memory + Metal gives Macs a large, "free" GPU advantage (Llama 3.2 3B ~30–80 tok/s; Whisper small ~10× real-time), while Intel laptops without a discrete GPU run CPU-only and are 3–10× slower (7–15 tok/s on an 8B model). The reliable common denominator is small models (1–3B LLMs, Whisper base/small) plus a browser Web Speech API fallback for students whose machines struggle.
- **Recommended phasing:** build a text-only "walking skeleton" (browser ↔ Flask ↔ Ollama) first, then bolt on TTS, then STT, then optional wake-word. Keep cloud/browser fallbacks (Web Speech API for STT/TTS) as an explicit, allowed escape hatch so installation friction never blocks a student from finishing.

## Key Findings

1. **Ollama is the clear LLM runtime choice for students.** It installs in one step on Windows/macOS/Linux, auto-detects Metal on Apple Silicon and CUDA on NVIDIA with zero configuration, and — per Ollama's official "OpenAI compatibility" documentation — exposes a built-in OpenAI Chat Completions–compatible REST endpoint at `http://localhost:11434/v1`. Students point the standard `openai` Python SDK at it by setting `base_url='http://localhost:11434/v1'` and `api_key='ollama'` (required by the SDK but ignored by Ollama). LM Studio and GPT4All are friendlier GUIs, but Ollama's API-first design fits a Flask app best.

2. **Llama 3.2 3B at Q4_K_M is the right default model** for an 8–16GB class. It needs ~2GB RAM, leaves headroom for the OS, browser, and the STT/TTS models, and produces good conversational quality. Phi-4-mini (3.8B, ~2.5GB) and Gemma 2/3 2B are strong alternates; 7–8B models (Mistral 7B, Llama 3.1 8B) are viable on 16GB machines but tight on 8GB.

3. **faster-whisper (base or small model) is the best local STT for this project**, but with a critical architecture caveat: its CTranslate2 backend supports **CPU and NVIDIA CUDA only — there is no Metal/MPS GPU support on Apple Silicon**, so on a Mac it runs CPU-only (and throws `ValueError: unsupported device mps` if you try). whisper.cpp is the better Mac choice because it uses Metal. Both are fast enough at the base/small size for interactive use on either platform. Per the SYSTRAN/faster-whisper README, faster-whisper is "up to 4 times faster than openai/whisper for the same accuracy while using less memory," further improvable "with 8-bit quantization on both CPU and GPU."

4. **Piper is the best local TTS for students**: one-line `pip install piper-tts`, tiny CPU-only ONNX voices, roughly 5× faster than real-time, natural-sounding, with cross-platform wheels (the PyPI `piper-tts` 1.4.2 release ships both `macosx_11_0_arm64` and `macosx_10_9_x86_64` wheels alongside Windows/Linux). Kokoro-82M is a higher-quality 2024/2025 alternative that still runs on CPU. pyttsx3/espeak-ng are trivially easy but sound robotic. Coqui/XTTS sound great but are too heavy/slow for real-time on these laptops.

5. **The browser Web Speech API is the single biggest friction-reducer.** `speechSynthesis` (TTS) works offline using OS voices in Chrome/Edge/Safari; `SpeechRecognition` (STT) works in Chrome/Edge but sends audio to the cloud (Google) and is not offline. Using it as a fallback lets any student get a working demo even if native STT/TTS installs fail.

6. **Wake-word detection ("Hey Assistant") is a stretch goal, not core.** openWakeWord (Apache-2.0 code; note pre-trained models are CC BY-NC-SA 4.0) and Picovoice Porcupine (free tier, needs an access key) both work, but add complexity. For a capstone, a push-to-talk button in the browser is simpler and more reliable.

## Details

### 1. Local LLM Options (2025–2026)

**Model recommendations by RAM tier (all Q4_K_M unless noted):**

| Model | Params | RAM (approx) | Best for |
|---|---|---|---|
| Llama 3.2 1B | 1B | ~1GB | Fallback on weakest 8GB Intel laptops |
| **Llama 3.2 3B** | 3B | ~2GB | **Default recommendation** — good quality, fits everywhere |
| Gemma 2/3 2B | 2B | ~1.6GB | Fastest small model, 40–60 tok/s on CPU |
| Phi-4-mini | 3.8B | ~2.5GB | Best small reasoner; ~12 tok/s on modern Intel CPU |
| Qwen 2.5 3B | 3B | ~2GB | Strong multilingual/coding alternate |
| Mistral 7B / Llama 3.1 8B | 7–8B | ~4.5–5GB | 16GB machines only; better quality, slower |

**Realistic token-generation speeds (Q4_K_M):**
- **Apple Silicon:** Llama 3.2 3B runs roughly 30–80 tok/s depending on chip (base M1/M2 at the lower end, Pro/Max at the higher end). Llama 3.1 8B runs ~12–28 tok/s on base chips, faster on Max/Ultra. Metal acceleration is automatic with zero config. On 8GB Macs, keep to 3B; an 8B model fits but leaves razor-thin headroom.
- **Intel laptop, CPU-only (no discrete GPU):** 8B models run ~7–15 tok/s; 3B models run faster (roughly 15–30 tok/s on modern CPUs, but thinner/older laptops with low memory bandwidth land ~7–12 tok/s). Memory bandwidth, not core count, is the binding constraint. On an 8GB Intel laptop with integrated graphics, "every megabyte is a struggle" — close heavy browser tabs and set `OLLAMA_MAX_LOADED_MODELS=1`.
- **Intel with integrated Arc GPU (Core Ultra):** Ollama's standard build runs CPU-only by default; the iGPU needs `OLLAMA_IGPU_ENABLE=1` or Intel's IPEX-LLM fork to be used, and even then gains are modest (roughly 30% over CPU on a Core Ultra 5 125H). Not worth the setup complexity for a class.
- **Intel Macs:** CPU-only (no Metal for LLM work), roughly 4–6 tok/s on a 7B model — treat like a slow Intel laptop and stick to 1–3B models.

**Runtime/serving options compared:**
- **Ollama** — CLI + background service, OpenAI-compatible API at `:11434/v1` (plus its native `/api/generate` and `/api/chat`), one-command model pulls (`ollama pull llama3.2:3b`). Best for a Flask app. **Recommended.**
- **LM Studio** — polished GUI, model browser (any GGUF from Hugging Face), also exposes an OpenAI-compatible server on port 1234. Good for students who want to see/tune models visually.
- **GPT4All** — simplest one-click desktop app, but no function calling and weakest for programmatic/API use.
- **llama.cpp** — the engine under all of the above; maximal control, but too low-level for most students.

All four use llama.cpp under the hood, so raw speed differs by only single-digit percentages — model choice matters far more than runtime choice.

**Quantization teaching point (GGUF, Q4_K_M):** GGUF is the model file format; the `Q4_K_M` suffix means 4-bit quantization (medium variant). Going from FP16 to Q4_K_M cuts model size roughly 72–75% (an 8B model drops from ~16GB to ~5GB) with under ~5% quality loss on most tasks. **Q4_K_M is the standard sweet spot** — teach students that a bigger model at Q4 almost always beats a smaller model at Q8, and that going below Q4 (e.g. Q2) degrades quality sharply.

### 2. Speech-to-Text Options

**Whisper model sizes (the accuracy/speed knob):**

| Model | Params | Disk | RAM | WER (English) | Notes |
|---|---|---|---|---|---|
| tiny | 39M | ~75MB | ~1GB | ~7.6% | Fastest; wake-word/short commands |
| base | 74M | ~142MB | ~1GB | ~5.0% | Good speed/accuracy balance |
| small | 244M | ~466MB | ~2GB | ~3.4% | Best default for accuracy |
| large-v3-turbo | 809M | ~1.6GB | ~3–4GB | ~2% | Overkill for a laptop assistant |

For a voice assistant, **base or small is the sweet spot** — you rarely need large.

**Local STT engines:**
- **faster-whisper (CTranslate2)** — up to 4× faster than vanilla Whisper, int8 quantization, low memory. **CPU + NVIDIA CUDA only — no Metal/MPS on Apple Silicon**, where it silently falls back to CPU. Best for Intel/NVIDIA. On CPU with int8, whisper-small runs at a real-time factor of ~0.08 (roughly 0.8s to transcribe a 10s clip) in controlled academic tests; real-world per-utterance latency is often 1–3s including overhead.
- **whisper.cpp** — runs on Metal (Apple Silicon), CUDA, Vulkan, and CPU. **The right choice on Macs**: base model ~RTF 0.04 (~0.4s for a 10s clip), small ~RTF 0.08 on an M2 with Metal. On a base M1 the small model processes a 30s dictation in ~3s. Metal gives roughly a 4× speedup over CPU-only on the same Mac.
- **Vosk** — lightweight Kaldi-based, true streaming, very low latency, runs on any CPU, but lower accuracy than Whisper on entity-heavy speech. Good for a low-resource fallback.

**Browser and cloud STT:**
- **Web Speech API `SpeechRecognition`** — trivial to use in Chrome/Edge, but sends audio to Google's cloud (not offline, not private) and is unreliable/unsupported on Firefox/Brave/Safari-as-webview. Fine as an easy on-ramp or fallback.
- **Cloud STT (Google, AssemblyAI, Deepgram, OpenAI Whisper API)** — higher accuracy, but defeats the "local" learning goal; use only as an explicit fallback.

**Microphone capture in Flask/Python — two patterns:**
1. **Browser MediaRecorder → POST to Flask (recommended).** JavaScript uses `navigator.mediaDevices.getUserMedia` to record, then POSTs a WAV/webm blob to a Flask endpoint that runs STT. This is the most portable approach — no native audio-library install pain, works identically on every student's machine, and the browser handles the mic permission prompt.
2. **Server-side capture with sounddevice or PyAudio.** Simpler conceptually for a Python-native app, but **PyAudio is a notorious install headache** (needs PortAudio; frequent "portaudio.h not found" / "Failed building wheel" errors on Windows and macOS). `sounddevice` (also PortAudio-based, records to NumPy arrays) is generally easier. Only use this path in a fully Python-native desktop build.

**Wake-word detection:** openWakeWord (Apache-2.0 code, ONNX; per its GitHub README, "a single core of a Raspberry Pi 3 can run 15-20 openWakeWord models simultaneously in real-time"; note its *pre-trained models* are CC BY-NC-SA 4.0, so check licensing if redistributing) or Porcupine (Apache-2.0 SDK, requires a free Picovoice access key, higher accuracy, ships "Hey Siri"/"Jarvis" built-ins). **Recommendation: skip for the core project; use a push-to-talk button.** Offer wake-word as a stretch goal for advanced students.

### 3. Text-to-Speech Options

| Engine | Quality | Speed | Setup | Architecture notes |
|---|---|---|---|---|
| **Piper** | Natural (neural VITS/ONNX) | ~5× real-time on CPU | `pip install piper-tts` | Cross-platform wheels incl. macOS arm64 + x86_64; CPU-only, no GPU needed |
| Kokoro-82M | Excellent (SOTA small) | Real-time+ on CPU | `pip install kokoro soundfile` + espeak-ng | Apache-2.0; 82M params; ~327MB weights; 54 voices/8 languages; needs Python 3.10–3.12 |
| pyttsx3 | Robotic | Instant | `pip install pyttsx3` | Uses OS voices (SAPI5/NSSpeech/espeak); fully offline, no models |
| espeak-ng | Robotic | Instant | system package | Tiny, 100+ languages; good for alerts |
| Coqui/XTTS v2 | Excellent + cloning | Slow (10–30s/paragraph on CPU) | Heavy | Company shut down Jan 2024; community fork `coqui-tts`; XTTS's GPT module alone is ~443M params (vs Kokoro's 82M) — needs a GPU for real-time |

**Recommendation: Piper as the default local TTS** (best quality-per-setup ratio), with **pyttsx3 as the zero-friction fallback** and the browser **Web Speech API `speechSynthesis`** as the easiest path of all (works offline with OS voices in Chrome/Edge/Safari). Note the Chrome quirk: `speechSynthesis` cancels utterances longer than ~15s / ~200–250 characters, so split long text into sentence-sized chunks (which also helps streaming). Piper's license moved from MIT (archived `rhasspy/piper`, Oct 2025) to GPL-3.0 (active `OHF-Voice/piper1-gpl`, current v1.4.2, April 2026) — fine for a student project, worth a mention when teaching licensing.

**Tradeoff to teach:** natural neural voices (Piper, Kokoro) cost more setup and compute; robotic voices (pyttsx3, espeak) are instant and dependency-free. For a demo that impresses, Piper wins; for guaranteed "it works on my machine," pyttsx3 or the browser API wins.

### 4. Architecture & Integration (Flask/Python)

**Recommended architecture — browser front-end + Flask orchestrator:**

```
Browser (mic capture via MediaRecorder, audio playback)
   │  POST audio blob
   ▼
Flask backend  ── orchestrates ──►  STT (faster-whisper / whisper.cpp)
                                     │ transcript
                                     ▼
                                   LLM (Ollama :11434/v1, OpenAI SDK)
                                     │ response text (streamed)
                                     ▼
                                   TTS (Piper) ──► audio file/stream
   ◄── audio response ──────────────┘
```

**Why browser + Flask beats fully-Python-native for teaching:**
- No native audio-library (PyAudio) install pain — the browser handles mic/speaker.
- Clean separation of concerns (front-end vs. orchestration vs. models) — a good software-engineering lesson.
- The same code runs on every student's machine regardless of OS.
- Easy to swap the Web Speech API in as a fallback for STT/TTS.

A fully Python-native desktop approach (sounddevice/PyAudio + Tkinter/CLI) is viable and avoids browser/JS, but the audio-device and PortAudio headaches make it less reliable across a mixed class.

**Keeping the UI responsive:**
- **Stream the LLM response** token-by-token (Ollama supports `stream=True`) via Server-Sent Events or WebSockets so the user sees text immediately.
- **Sentence-level TTS streaming is the single biggest latency win:** as each sentence finishes generating, send it to Piper and start playing it while the LLM keeps generating. This turns a 6–8s perceived wait into ~1–2s.
- Run heavy work off the request thread; Ollama already runs as its own service, so the Flask app is mostly I/O-bound and can use threading or async.

**Realistic end-to-end latency (end of speech → first spoken word), with streaming:**
- **Apple Silicon MacBook (Whisper small + 3B/8B + Piper):** ~1–1.5s.
- **Intel CPU-only laptop:** a naive (non-streaming) build takes ~3–5s; with VAD + LLM token streaming + sentence-level TTS this can be pulled toward ~2s. (Published cascade latencies mostly assume a GPU or Apple Silicon; the Intel-CPU figure is an informed estimate from component timings.)

**Minimal viable architecture (MVP):** Browser push-to-talk button → records audio → POST to Flask → faster-whisper base → Ollama Llama 3.2 3B (non-streaming) → Piper → return WAV → browser plays it. One round-trip, no streaming, no wake word.

**Stretch architecture:** Streaming LLM tokens over WebSocket, sentence-level TTS streaming, wake-word detection, conversation memory/history, a system prompt that keeps responses short (voice UIs punish rambling), and a model-selector so students can benchmark different LLMs.

### 5. Intel vs. Apple Silicon — Consolidated Comparison

| Dimension | Apple Silicon (M1–M4, macOS) | Intel (x86-64, Windows/Linux) |
|---|---|---|
| **LLM speed (3B Q4)** | ~30–80 tok/s (Metal, automatic) | ~7–30 tok/s (CPU-only) |
| **LLM setup** | Install Ollama, done — Metal auto-detected | Install Ollama, done — CPU by default; iGPU/Arc needs extra work |
| **Memory model** | Unified memory: GPU shares all RAM, no copy overhead — a 16GB Mac punches above its weight | Separate RAM/VRAM pools; 8GB integrated-graphics laptop struggles |
| **STT** | Use **whisper.cpp** (Metal); faster-whisper falls back to CPU (no MPS) | Use **faster-whisper** (CPU int8) or whisper.cpp; NVIDIA laptops get CUDA |
| **TTS (Piper)** | CPU-only, works great, arm64 wheels | CPU-only, works great |
| **GPU acceleration reality** | Metal/MPS: automatic for Ollama & whisper.cpp; MPS NOT supported by faster-whisper | NVIDIA CUDA (best, auto-detected by Ollama) > Intel Arc iGPU (needs IPEX-LLM/flag) > CPU fallback |
| **Install friction** | Lowest — Homebrew or one-line installer; Gatekeeper prompt on first launch | Higher — PyAudio/PortAudio issues; NVIDIA driver checks; Arc setup complex |
| **Intel Macs** | CPU-only (~4–6 tok/s on 7B); treat like a slow Intel laptop | — |

**GPU acceleration realities:**
- **Apple Metal/MPS:** Ollama and whisper.cpp use it automatically. But faster-whisper (CTranslate2) does *not* support MPS — a key gotcha. Also, Ollama's MLX backend (v0.19+, roughly 2× faster) currently requires 32GB+ unified memory, so 8/16GB student Macs stay on the Metal backend.
- **NVIDIA CUDA (Windows/Linux laptops with a discrete GPU):** the fastest and simplest accelerated path; Ollama auto-detects. faster-whisper also gets big gains here.
- **Intel integrated graphics / Arc:** possible via Ollama's Vulkan backend (needs `OLLAMA_IGPU_ENABLE=1`) or Intel's IPEX-LLM fork, but modest gains and real setup complexity — not recommended for a class.
- **CPU-only fallback:** always works, 3–10× slower. Perfectly usable with 1–3B models.

**Most reliable common-denominator setup for a mixed class:**
- **Ollama + Llama 3.2 3B (Q4_K_M)** as the LLM everywhere.
- **STT:** faster-whisper `base` on Intel/NVIDIA, whisper.cpp `base` on Mac — OR the browser Web Speech API as a universal fallback.
- **TTS:** Piper everywhere, with pyttsx3 / browser `speechSynthesis` as fallbacks.
- **Front-end:** browser MediaRecorder → Flask, so no PyAudio required.
- Give every student a working **cloud/browser fallback** so a failed native install never blocks completion.

### 6. Teaching / Planning Considerations

**Suggested phased build order (walking skeleton first):**
1. **Phase 0 — Environment:** Install Ollama, `ollama pull llama3.2:3b`, verify `curl http://localhost:11434`. Set up a Python venv and a bare Flask "hello world."
2. **Phase 1 — Text chat skeleton:** Browser text box → Flask → Ollama (OpenAI SDK, `base_url="http://localhost:11434/v1"`) → display reply. This is the walking skeleton — everything else hangs off it.
3. **Phase 2 — Add TTS:** Feed the LLM reply to Piper (or browser `speechSynthesis`) and play audio. Now it talks.
4. **Phase 3 — Add STT:** Browser MediaRecorder → POST audio → faster-whisper/whisper.cpp → transcript into the Phase 1 pipeline. Now it listens. Push-to-talk button.
5. **Phase 4 — Polish:** Stream LLM tokens, sentence-level TTS streaming, conversation history, short-answer system prompt, error handling.
6. **Phase 5 — Stretch:** Wake-word (openWakeWord), model benchmarking, multi-turn memory, voice selection.

**Common pitfalls / install gotchas per platform:**
- **PyAudio everywhere:** avoid it by using browser capture; if required, install PortAudio first (`brew install portaudio` on Mac, `portaudio19-dev` on Debian/Ubuntu, prebuilt wheels on Windows). Use Python 3.12 or earlier (3.13 wheels lag for several audio libs).
- **faster-whisper on Mac:** don't set `device="mps"` — it throws `ValueError: unsupported device mps`. Use `device="cpu"` on Mac, or use whisper.cpp instead.
- **Ollama running out of memory / swapping:** on 8GB machines set `OLLAMA_MAX_LOADED_MODELS=1`, run `ollama stop` before switching models, keep context small (`num_ctx`), and close browsers/Slack/Spotify.
- **Ollama CPU-only when a GPU exists:** check with `OLLAMA_DEBUG=1`; on Windows AMD/Intel GPUs, acceleration is immature — expect CPU.
- **Web Speech API:** `SpeechRecognition` needs internet (Chrome→Google) and is Chromium-only; Brave blocks it. `speechSynthesis` cuts off long utterances (~200 chars) — chunk the text.
- **Python version churn:** Kokoro needs Python 3.10–3.12; several libs don't have 3.13 wheels yet. Standardize the class on Python 3.11 or 3.12.
- **First-run model downloads** (Ollama models, Whisper weights, Piper voices) are large and silent — warn students they aren't frozen; do these on good WiFi before class.

**Where cloud fallbacks are reasonable (without abandoning the "local" goal):**
- **STT:** browser Web Speech API or a cloud API when a student's laptop can't run Whisper fast enough — keep the local path as the graded/primary implementation and cloud as a documented fallback.
- **TTS:** browser `speechSynthesis` is effectively a free, offline OS-level service and is a legitimate primary choice, not just a fallback.
- **LLM:** should stay local (that's the core learning objective); if truly necessary, an OpenAI/Anthropic key can be a swap-in via the same OpenAI SDK interface — a nice teaching moment about the OpenAI-compatible abstraction.

**Free/student-friendly throughout:** Ollama, faster-whisper, whisper.cpp, Vosk, Piper, Kokoro, pyttsx3, espeak-ng, openWakeWord, Flask, and the browser APIs are all free and open-source. The only thing requiring an account is Porcupine (free tier) — which is why it's optional.

## Recommendations

**For the instructor, staged and concrete:**

1. **Standardize the baseline stack now:** Python 3.11/3.12 venv + Flask + Ollama + Llama 3.2 3B + faster-whisper (base) / whisper.cpp on Mac + Piper, with browser MediaRecorder capture. Provide a `requirements.txt` and a one-page per-OS setup sheet (Windows, macOS-Apple-Silicon, macOS-Intel, Linux).
2. **Require the walking skeleton (Phase 1) as an early graded checkpoint** — browser ↔ Flask ↔ Ollama text chat. This de-risks the project: if a student can hit Ollama from Flask by week 2, the rest is incremental.
3. **Make cloud/browser fallbacks explicitly allowed and documented,** but grade the local implementation as the primary deliverable. This keeps the "local AI" learning goal intact while ensuring no one is blocked by a hardware or install failure.
4. **Give Apple Silicon students the "faster-whisper→whisper.cpp" swap up front** so they don't waste hours on the `mps` error. Give Intel students realistic latency expectations (a few seconds per turn is normal, CPU-only) and the small-model guidance.
5. **Teach the three tradeoff dials as core concepts:** model size vs. speed (LLM params), Whisper model size vs. accuracy, and neural vs. robotic TTS. Quantization (Q4_K_M) is the natural vehicle for the model-size lesson.

**Benchmarks/thresholds that should change the plan:**
- If a student's Intel laptop gets **< ~5 tok/s on Llama 3.2 3B**, drop to Llama 3.2 1B or route the LLM to the browser fallback path.
- If **native STT install fails or transcription takes > ~5s per utterance**, switch that student to the Web Speech API for STT.
- If **8GB machines swap/thrash**, enforce `OLLAMA_MAX_LOADED_MODELS=1`, 1–3B models only, and closing background apps.
- If the class is **majority Apple Silicon**, you can safely raise the default LLM to a 7–8B model on 16GB Macs for better quality; keep 3B as the floor.

## Caveats
- **Many performance numbers come from vendor/SEO blogs** and are "illustrative ranges," not tightly controlled benchmarks. The most reliable figures cited here trace to GitHub repos (llama.cpp, faster-whisper), arXiv papers, and Intel's own docs. Treat all tok/s and latency figures as directional; real numbers vary with laptop model, thermal state (battery vs. plugged-in throttles Macs 30–50%), context length, and background load.
- **The Intel-CPU-only end-to-end latency (~2–5s) is an informed estimate**, not a directly published laptop-CPU cascade measurement — most published cascade latencies assume a GPU or Apple Silicon.
- **The local-AI landscape moves fast.** Model names/versions (Llama 3.2, Phi-4-mini, Gemma 2/3, Ollama versions) and tool releases (Piper's GPL relicense, Ollama MLX backend) are current as of mid-2026 but will shift; verify versions at build time.
- **faster-whisper's lack of Apple Silicon GPU support** is the most common architecture-specific trap in this stack — double-check it hasn't changed before writing student materials.
- **Licensing nuance for redistribution:** openWakeWord's code is Apache-2.0 but its pre-trained wake-word models are CC BY-NC-SA 4.0 (non-commercial); Piper is now GPL-3.0; Kokoro and Porcupine's SDK are permissive. This matters only if students publish/redistribute — for a classroom demo all are fine.
- **Wake-word accuracy** varies a lot by environment and reported benchmarks are often vendor-run; don't promise Alexa-grade reliability from openWakeWord/Porcupine in a noisy classroom.