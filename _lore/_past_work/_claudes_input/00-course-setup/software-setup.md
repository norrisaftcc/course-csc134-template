# Development Environment Setup Guide

## Required Software

### Option 1: Visual Studio Community (Recommended for Windows)
1. Download from: https://visualstudio.microsoft.com/downloads/
2. During installation, select:
   - "Desktop development with C++"
   - Windows 10 SDK
3. Total download: ~7GB
4. **Pros**: Professional IDE, excellent debugger, IntelliSense
5. **Cons**: Windows only, large installation

### Option 2: Code::Blocks (Cross-Platform)
1. Download from: http://www.codeblocks.org/downloads
2. Choose the version WITH MinGW compiler
3. Total download: ~150MB
4. **Pros**: Lightweight, works on all platforms
5. **Cons**: Less sophisticated than VS

### Option 3: Online - Replit (No Installation!)
1. Go to: https://replit.com
2. Create free account
3. Click "Create Repl" → Choose C++
4. **Pros**: Nothing to install, works anywhere, collaboration features
5. **Cons**: Requires internet, limited debugging

### Option 4: Dev-C++ (Lightweight Windows)
1. Download from: https://sourceforge.net/projects/orwelldevcpp/
2. Includes compiler, ready to go
3. Total download: ~50MB
4. **Pros**: Very lightweight, simple interface
5. **Cons**: Windows only, older interface

## First Program Test

Once installed, test with this program:

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, C++ World!" << endl;
    cout << "My setup works! 🎉" << endl;
    return 0;
}
```

Expected output:
```
Hello, C++ World!
My setup works! 🎉
```

## Troubleshooting Common Issues

### "Cannot find compiler"
- **Solution**: Reinstall and ensure you select the compiler option
- For Code::Blocks: Download the version that says "with MinGW"
- For VS: Run the installer again and add "Desktop development with C++"

### "iostream not found"
- **Solution**: You're likely using a C compiler, not C++
- Check file extension is `.cpp` not `.c`
- In project settings, ensure C++ is selected

### Program window closes immediately
- **Solution**: Add before `return 0;`:
```cpp
system("pause");  // Windows
// OR
cin.get();        // Cross-platform
```

### Can't see output (especially in VS)
- **Solution**: Run with Ctrl+F5 instead of F5
- This runs without debugger and keeps window open

## Recommended Extensions & Settings

### For Visual Studio
1. Change font size: Tools → Options → Environment → Fonts → Size: 12+
2. Enable line numbers: Tools → Options → Text Editor → C++ → Line numbers
3. Auto-format: Edit → Advanced → Format Document (Ctrl+K, Ctrl+D)

### For Visual Studio Code (if using)
Install extensions:
1. C/C++ by Microsoft
2. Code Runner
3. C++ Intellisense

### For All IDEs
1. **Enable auto-save** if available
2. **Set tab size to 4 spaces**
3. **Enable bracket matching**
4. **Turn on syntax highlighting**

## Creating Your First Project

### Visual Studio
1. File → New → Project
2. Choose "Console App"
3. Name: "CSC134_Week1"
4. Location: Create a "CSC134" folder
5. Check "Place solution and project in same directory"

### Code::Blocks
1. File → New → Project
2. Choose "Console Application"
3. Select C++
4. Project title: "CSC134_Week1"
5. Folder: Create "CSC134" folder

### Replit
1. Click "Create Repl"
2. Choose C++
3. Name: "CSC134-Week1"
4. It's ready to code!

## File Organization

Create this folder structure:
```
CSC134/
├── Week01/
│   ├── hello.cpp
│   ├── practice1.cpp
│   └── lab1.cpp
├── Week02/
│   └── ...
├── Projects/
│   ├── Project1/
│   ├── Project2/
│   └── ...
└── Portfolio/
```

## Backup Strategy

### Option 1: GitHub (Recommended)
1. Create account at github.com
2. Download GitHub Desktop
3. Create repository "CSC134"
4. Commit after each session

### Option 2: Cloud Storage
1. Save projects to OneDrive/Google Drive/Dropbox
2. Automatic sync protects your work

### Option 3: USB Drive
1. Copy entire CSC134 folder weekly
2. Keep two USBs, alternate them

## Getting Help

### Quick Resources
- **Compiler Errors**: Copy exact error into Google
- **Syntax Help**: cppreference.com
- **Quick Answers**: stackoverflow.com
- **Video Help**: YouTube "C++ [your topic]"

### Class Resources
- Discord server: [instructor will provide]
- Office hours: [see syllabus]
- Email: [instructor email]

### When Asking for Help
Always provide:
1. Your code (or screenshot)
2. Exact error message
3. What you've tried
4. What you expected to happen

## Ready Checklist

Before starting Week 1:
- [ ] IDE installed and tested
- [ ] Hello World program runs
- [ ] Folder structure created
- [ ] Backup method chosen
- [ ] Joined class Discord/forum
- [ ] Bookmarked help resources

## Pro Tips

1. **Compile often** - After every few lines
2. **Save before running** - Always Ctrl+S
3. **Read errors from top** - First error often causes others
4. **Keep old versions** - Comment out, don't delete
5. **Use meaningful names** - `pizzaPrice` not `p`

## Accessibility Options

### For Visual Difficulties
- Increase font size (see settings above)
- High contrast theme: Most IDEs have dark/light modes
- Screen reader compatible: Visual Studio with NVDA/JAWS

### For Motor Difficulties
- Sticky keys: Windows/Mac accessibility settings
- Voice coding: Talon Voice, Dragon NaturallySpeaking
- Reduced typing: Use IDE autocomplete features

### For Learning Differences
- Replit: Simplest interface
- Color coding: Bracket pair colorizers
- Step-through debugging: Available in VS and Code::Blocks

## You're Ready!

Once your Hello World runs, you're ready for Week 1. Don't worry if everything doesn't make sense yet - that's what the course is for!

Remember: **Every professional programmer started by struggling with their first Hello World program.**
