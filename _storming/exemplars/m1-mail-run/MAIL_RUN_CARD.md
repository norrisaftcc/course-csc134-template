# The Mail Run — how work leaves your machine

*M1 reference card. Keep it open until this is muscle memory.*

Turning in work is a three-step errand, the same every time. Think of returning a package:

```text
   PULL                 COMMIT                    PUSH
   check the mailbox →  box it + write the label →  hand it to the carrier
```

## 1. Pull — check the mailbox first

```bash
git pull
```

Before you send anything, see what's arrived. Maybe the instructor updated the starter
files; maybe future-you on the lab computer pushed something last Tuesday. Sending without
checking is how packages collide. **Pull first, every time, even when you're sure there's
nothing.** (Especially then.)

## 2. Commit — box it up and write the label

```bash
git add m1lab1.md
git commit -m "M1 Lab 1: add README with project sections"
```

`add` puts your file in the box. `commit` seals it — and the `-m` message is the
**shipping label.** A label tells the person receiving the box what's inside without
opening it.

**Label formula:** what you did + what it applies to. Start with a verb: Add, Fix,
Update, Remove.

| Label | Verdict |
|---|---|
| `"M1 Lab 1: add README with project sections"` | You'll know what this is in December |
| `"fix typo in setup instructions"` | Fine — small box, honest label |
| `"stuff"` | A box labeled "stuff." Would you accept that package? |
| `"asdfjkl"` | The carrier is now suspicious of you |

The test: **would you understand this label in six months?** If not, rewrite it.

## 3. Push — hand it to the carrier, then check the tracking

```bash
git push
```

The box leaves your machine. Now **check the tracking**: open your repo on github.com
and confirm your file is there. If you can't see it on the website, it was never
mailed — and your instructor can't grade a package that's still on your desk.

## The whole run, one breath

```bash
git pull
git add <your files>
git commit -m "<a real label>"
git push
# then: verify on github.com
```

> **Looking ahead:** professionals run a bigger version of this errand — with branches,
> pull requests, and reviews, like a mailroom with sign-offs. You'll grow into it later
> in this course and the next one. The Mail Run is the core of it, and it never changes:
> check what's arrived, label honestly, confirm delivery.
