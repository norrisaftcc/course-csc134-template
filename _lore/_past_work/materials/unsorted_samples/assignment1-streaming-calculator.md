# Assignment 1: Your First C++ Program - Streaming Revenue Calculator

## Introduction

Welcome to C++! Today you're going to build something real - a tool that calculates how much money content creators make from streaming. Whether it's Spotify plays, YouTube views, or Twitch subscriptions, you'll create a calculator that shows the actual dollars behind the numbers.

## What You'll Learn

- Basic input and output in C++
- Working with variables and data types
- Simple arithmetic operations
- Formatting output to look professional

## The Challenge

Create a program that calculates streaming revenue from different platforms. Here's what creators actually earn per stream/view:

- Spotify: $0.003 - $0.004 per stream
- YouTube: $0.01 - $0.03 per 1000 views (varies by ad engagement)
- Twitch: Streamers keep 50% of $4.99 subscriptions

## Starter Program

Let's begin with the absolute basics - calculating Spotify revenue:

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "🎵 SPOTIFY REVENUE CALCULATOR 🎵" << endl;
    cout << "================================" << endl;
    
    // Step 1: Ask for the artist name
    cout << "Enter artist name: ";
    string artist_name;
    getline(cin, artist_name);
    
    // Step 2: Ask for number of streams
    cout << "Enter total streams: ";
    int streams;
    cin >> streams;
    
    // Step 3: Calculate revenue (using average rate)
    double rate_per_stream = 0.0035;  // $0.0035 per stream
    double total_revenue = streams * rate_per_stream;
    
    // Step 4: Display results
    cout << "\n💰 REVENUE REPORT 💰" << endl;
    cout << "Artist: " << artist_name << endl;
    cout << "Streams: " << streams << endl;
    cout << "Revenue: $" << total_revenue << endl;
    
    return 0;
}
```

**Sample Output:**
```
🎵 SPOTIFY REVENUE CALCULATOR 🎵
================================
Enter artist name: Bedroom Producer
Enter total streams: 100000

💰 REVENUE REPORT 💰
Artist: Bedroom Producer
Streams: 100000
Revenue: $350
```

## Your Assignment

Expand this program to create a "Multi-Platform Revenue Calculator" that:

### Level 1: Basic Requirements
1. Calculate revenue for at least 3 platforms (Spotify, YouTube, Twitch)
2. Show total combined revenue
3. Display which platform generates the most income

### Level 2: Intermediate Features
Add these features to make it more realistic:

```cpp
// Hint for formatting money properly
#include <iomanip>
cout << fixed << setprecision(2);
cout << "$" << amount << endl;

// Hint for comparing values
if (spotify_revenue > youtube_revenue)
{
    cout << "Spotify is your biggest earner!" << endl;
}
```

### Level 3: Advanced Challenge
1. Add Apple Music ($0.01 per stream) and TikTok Creator Fund ($0.02-$0.04 per 1000 views)
2. Calculate how many streams needed to earn $1000
3. Show monthly projections based on daily averages

## Complete Solution Template

```cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Header
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║   CREATOR REVENUE CALCULATOR v1.0      ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    
    // Get creator info
    string creator_name;
    cout << "\nEnter your creator/artist name: ";
    getline(cin, creator_name);
    
    // Spotify section
    cout << "\n🎵 SPOTIFY" << endl;
    cout << "Enter monthly streams: ";
    int spotify_streams;
    cin >> spotify_streams;
    double spotify_rate = 0.0035;
    double spotify_revenue = spotify_streams * spotify_rate;
    
    // YouTube section
    cout << "\n📺 YOUTUBE" << endl;
    cout << "Enter monthly views: ";
    int youtube_views;
    cin >> youtube_views;
    double youtube_rate = 0.02;  // $0.02 per 1000 views
    double youtube_revenue = (youtube_views / 1000.0) * youtube_rate;
    
    // Twitch section
    cout << "\n🎮 TWITCH" << endl;
    cout << "Enter number of subscribers: ";
    int twitch_subs;
    cin >> twitch_subs;
    double sub_price = 4.99;
    double creator_share = 0.5;  // Creators get 50%
    double twitch_revenue = twitch_subs * sub_price * creator_share;
    
    // Calculate totals
    double total_revenue = spotify_revenue + youtube_revenue + twitch_revenue;
    
    // Display report
    cout << fixed << setprecision(2);
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║           REVENUE REPORT               ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    
    cout << "\nCreator: " << creator_name << endl;
    cout << "\nPlatform Breakdown:" << endl;
    cout << "  Spotify:  $" << setw(10) << spotify_revenue 
         << " (" << spotify_streams << " streams)" << endl;
    cout << "  YouTube:  $" << setw(10) << youtube_revenue 
         << " (" << youtube_views << " views)" << endl;
    cout << "  Twitch:   $" << setw(10) << twitch_revenue 
         << " (" << twitch_subs << " subs)" << endl;
    cout << "  ─────────────────────────" << endl;
    cout << "  TOTAL:    $" << setw(10) << total_revenue << endl;
    
    // Find best platform
    cout << "\n💡 INSIGHTS:" << endl;
    if (spotify_revenue > youtube_revenue && spotify_revenue > twitch_revenue)
        cout << "✓ Spotify is your biggest revenue source!" << endl;
    else if (youtube_revenue > twitch_revenue)
        cout << "✓ YouTube is your biggest revenue source!" << endl;
    else
        cout << "✓ Twitch is your biggest revenue source!" << endl;
    
    // Goal calculator
    double goal = 1000.0;
    cout << "\n🎯 To earn $" << goal << " per month:" << endl;
    cout << "  Need " << (int)(goal / spotify_rate) << " Spotify streams OR" << endl;
    cout << "  Need " << (int)(goal / youtube_rate * 1000) << " YouTube views OR" << endl;
    cout << "  Need " << (int)(goal / (sub_price * creator_share)) << " Twitch subs" << endl;
    
    return 0;
}
```

## Common Mistakes to Avoid

1. **Integer Division Problem**
```cpp
// WRONG - This gives 0 for views under 1000!
double revenue = youtube_views / 1000 * rate;

// RIGHT - Use 1000.0 to force decimal division
double revenue = youtube_views / 1000.0 * rate;
```

2. **Missing String Spaces**
```cpp
// If using cin >> name, "Cool Creator" becomes just "Cool"
// Always use getline() for names with spaces!
```

3. **Money Display Issues**
```cpp
// Without formatting: $350.5 (looks unprofessional)
// With setprecision(2): $350.50 (much better!)
```

## Extension Ideas

Once you complete the basic calculator, try adding:
- A "months to goal" calculator (how long to reach $5000?)
- Platform comparison chart using ASCII art
- Save results to a file
- Add more platforms (Patreon, Ko-fi, etc.)

## Why This Matters

This isn't just an exercise - creators use tools like this every day! Services like Social Blade and Creator Wizard charge monthly fees for similar calculators. You're building the foundation of a real business tool.

Remember: Every line of code you write is a step toward building something amazing. Even if this seems simple now, you're learning the exact skills used to build the apps millions of people use daily!

**Debugging Tip**: If your output looks weird, check if you're doing integer division by accident. In C++, 5/2 equals 2, but 5.0/2 equals 2.5. Those decimal points matter!