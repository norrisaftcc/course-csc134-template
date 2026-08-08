# Assignment 3: Advanced C++ Project - Sponsorship Deal Manager

## Introduction

Now that you can calculate revenue and track analytics, it's time to build something more complex: a tool that manages sponsorship deals! This program will help creators track multiple brand deals, calculate deliverables, and ensure they're meeting their contractual obligations. This is where your C++ skills level up!

## What You'll Learn

- Working with arrays to store multiple items
- Creating and using functions for code organization
- File input/output for data persistence
- Complex business logic with multiple conditions
- Building a menu-driven application

## The Challenge

Create a Sponsorship Deal Manager that helps creators:
1. Track multiple sponsorship deals
2. Monitor deliverable deadlines
3. Calculate total earnings
4. Alert when posts are due
5. Generate professional reports

## Core Concepts: Arrays and Functions

Before diving in, let's understand our new tools:

```cpp
// Arrays let us store multiple values
string brands[5];     // Can store 5 brand names
double payments[5];   // Can store 5 payment amounts
int posts_required[5]; // Can store 5 post requirements

// Functions let us organize code
void displayMenu();   // Shows options to user
double calculateTotal(double payments[], int size); // Adds up payments
void addNewDeal(string brands[], double payments[], int& count); // Adds a deal
```

## Step 1: Basic Deal Tracker

Let's start with a simple version that tracks a few deals:

```cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to display a single deal
void displayDeal(string brand, double payment, int posts_required, int posts_completed)
{
    cout << "\n📋 " << brand << endl;
    cout << "   Payment: $" << fixed << setprecision(2) << payment << endl;
    cout << "   Posts: " << posts_completed << "/" << posts_required;
    
    if (posts_completed < posts_required)
        cout << " ⚠️ " << (posts_required - posts_completed) << " posts due!" << endl;
    else
        cout << " ✅ Complete!" << endl;
}

int main()
{
    // Arrays to store deal information
    const int MAX_DEALS = 10;
    string brands[MAX_DEALS];
    double payments[MAX_DEALS];
    int posts_required[MAX_DEALS];
    int posts_completed[MAX_DEALS];
    int deal_count = 0;
    
    cout << "╔═══════════════════════════════════════╗" << endl;
    cout << "║     SPONSORSHIP DEAL MANAGER v1.0     ║" << endl;
    cout << "╚═══════════════════════════════════════╝" << endl;
    
    // Add some sample deals
    brands[0] = "TechGear Pro";
    payments[0] = 1500;
    posts_required[0] = 3;
    posts_completed[0] = 1;
    deal_count++;
    
    brands[1] = "FashionForward";
    payments[1] = 2000;
    posts_required[1] = 4;
    posts_completed[1] = 4;
    deal_count++;
    
    // Display all deals
    cout << "\n📊 ACTIVE SPONSORSHIPS:" << endl;
    for (int i = 0; i < deal_count; i++)
    {
        displayDeal(brands[i], payments[i], posts_required[i], posts_completed[i]);
    }
    
    // Calculate totals
    double total_earnings = 0;
    int total_posts_due = 0;
    
    for (int i = 0; i < deal_count; i++)
    {
        total_earnings += payments[i];
        int posts_due = posts_required[i] - posts_completed[i];
        if (posts_due > 0)
            total_posts_due += posts_due;
    }
    
    cout << "\n💰 SUMMARY:" << endl;
    cout << "Total Earnings: $" << total_earnings << endl;
    cout << "Posts Still Due: " << total_posts_due << endl;
    
    return 0;
}
```

## Step 2: Full Featured Manager with Menu

Now let's build the complete system with user interaction:

```cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int MAX_DEALS = 50;

// Function prototypes
void displayMenu();
void addDeal(string brands[], double payments[], int posts_req[], 
             int posts_comp[], string deadlines[], int& count);
void viewAllDeals(string brands[], double payments[], int posts_req[], 
                  int posts_comp[], string deadlines[], int count);
void updateProgress(string brands[], int posts_comp[], int posts_req[], int count);
void generateReport(string brands[], double payments[], int posts_req[], 
                   int posts_comp[], string deadlines[], int count);
double calculateEarnings(double payments[], int posts_comp[], int posts_req[], int count);
void saveToFile(string brands[], double payments[], int posts_req[], 
                int posts_comp[], string deadlines[], int count);
void loadFromFile(string brands[], double payments[], int posts_req[], 
                  int posts_comp[], string deadlines[], int& count);

int main()
{
    // Arrays to store sponsorship data
    string brands[MAX_DEALS];
    double payments[MAX_DEALS];
    int posts_required[MAX_DEALS];
    int posts_completed[MAX_DEALS];
    string deadlines[MAX_DEALS];
    int deal_count = 0;
    
    // Load existing data
    loadFromFile(brands, payments, posts_required, posts_completed, deadlines, deal_count);
    
    cout << "╔═══════════════════════════════════════╗" << endl;
    cout << "║     SPONSORSHIP DEAL MANAGER v2.0     ║" << endl;
    cout << "╚═══════════════════════════════════════╝" << endl;
    
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear buffer
        
        switch(choice)
        {
            case 1:
                addDeal(brands, payments, posts_required, posts_completed, 
                       deadlines, deal_count);
                break;
            case 2:
                viewAllDeals(brands, payments, posts_required, posts_completed, 
                            deadlines, deal_count);
                break;
            case 3:
                updateProgress(brands, posts_completed, posts_required, deal_count);
                break;
            case 4:
                generateReport(brands, payments, posts_required, posts_completed, 
                              deadlines, deal_count);
                break;
            case 5:
                saveToFile(brands, payments, posts_required, posts_completed, 
                          deadlines, deal_count);
                cout << "\n✅ Data saved successfully!" << endl;
                break;
            case 0:
                cout << "\nThanks for using Sponsorship Manager! 🚀" << endl;
                break;
            default:
                cout << "\n❌ Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    
    return 0;
}

void displayMenu()
{
    cout << "\n📋 MAIN MENU:" << endl;
    cout << "1. Add New Sponsorship Deal" << endl;
    cout << "2. View All Deals" << endl;
    cout << "3. Update Post Progress" << endl;
    cout << "4. Generate Earnings Report" << endl;
    cout << "5. Save Data" << endl;
    cout << "0. Exit" << endl;
    cout << "\n";
}

void addDeal(string brands[], double payments[], int posts_req[], 
             int posts_comp[], string deadlines[], int& count)
{
    if (count >= MAX_DEALS)
    {
        cout << "\n❌ Maximum deals reached!" << endl;
        return;
    }
    
    cout << "\n➕ ADD NEW SPONSORSHIP DEAL" << endl;
    cout << "Brand name: ";
    getline(cin, brands[count]);
    
    cout << "Total payment: $";
    cin >> payments[count];
    
    cout << "Posts required: ";
    cin >> posts_req[count];
    
    cout << "Posts completed so far: ";
    cin >> posts_comp[count];
    
    cin.ignore(); // Clear buffer
    cout << "Deadline (MM/DD/YYYY): ";
    getline(cin, deadlines[count]);
    
    count++;
    cout << "\n✅ Deal added successfully!" << endl;
}

void viewAllDeals(string brands[], double payments[], int posts_req[], 
                  int posts_comp[], string deadlines[], int count)
{
    if (count == 0)
    {
        cout << "\n📭 No deals to display." << endl;
        return;
    }
    
    cout << "\n📊 ACTIVE SPONSORSHIP DEALS:" << endl;
    cout << "═══════════════════════════════════════════════════════" << endl;
    
    for (int i = 0; i < count; i++)
    {
        cout << "\n" << (i+1) << ". " << brands[i] << endl;
        cout << "   💵 Payment: $" << fixed << setprecision(2) << payments[i] << endl;
        cout << "   📸 Progress: " << posts_comp[i] << "/" << posts_req[i] << " posts";
        
        int remaining = posts_req[i] - posts_comp[i];
        if (remaining > 0)
            cout << " (⚠️ " << remaining << " due)";
        else
            cout << " ✅";
            
        cout << "\n   📅 Deadline: " << deadlines[i] << endl;
        
        // Calculate per-post rate
        double per_post = payments[i] / posts_req[i];
        cout << "   💰 Rate: $" << per_post << " per post" << endl;
    }
}

void updateProgress(string brands[], int posts_comp[], int posts_req[], int count)
{
    if (count == 0)
    {
        cout << "\n📭 No deals to update." << endl;
        return;
    }
    
    cout << "\n📝 UPDATE POST PROGRESS" << endl;
    
    // Show brands with numbers
    for (int i = 0; i < count; i++)
    {
        cout << (i+1) << ". " << brands[i] 
             << " (" << posts_comp[i] << "/" << posts_req[i] << ")" << endl;
    }
    
    cout << "\nSelect deal number to update: ";
    int choice;
    cin >> choice;
    
    if (choice < 1 || choice > count)
    {
        cout << "❌ Invalid selection." << endl;
        return;
    }
    
    int index = choice - 1;
    cout << "Current progress: " << posts_comp[index] << "/" << posts_req[index] << endl;
    cout << "Enter new completed posts: ";
    cin >> posts_comp[index];
    
    if (posts_comp[index] >= posts_req[index])
        cout << "\n🎉 Congratulations! Deal complete!" << endl;
    else
        cout << "\n✅ Progress updated!" << endl;
}

void generateReport(string brands[], double payments[], int posts_req[], 
                   int posts_comp[], string deadlines[], int count)
{
    cout << "\n📊 EARNINGS & PERFORMANCE REPORT" << endl;
    cout << "═══════════════════════════════════════════════════════" << endl;
    
    double total_potential = 0;
    double total_earned = 0;
    int total_posts_done = 0;
    int total_posts_req = 0;
    int deals_complete = 0;
    int deals_pending = 0;
    
    for (int i = 0; i < count; i++)
    {
        total_potential += payments[i];
        total_posts_done += posts_comp[i];
        total_posts_req += posts_req[i];
        
        // Calculate earned based on completion percentage
        double completion_rate = (double)posts_comp[i] / posts_req[i];
        double earned = payments[i] * completion_rate;
        total_earned += earned;
        
        if (posts_comp[i] >= posts_req[i])
            deals_complete++;
        else
            deals_pending++;
    }
    
    cout << fixed << setprecision(2);
    cout << "\n💼 DEAL SUMMARY:" << endl;
    cout << "   Total Deals: " << count << endl;
    cout << "   Completed: " << deals_complete << endl;
    cout << "   In Progress: " << deals_pending << endl;
    
    cout << "\n💰 FINANCIAL SUMMARY:" << endl;
    cout << "   Total Contract Value: $" << total_potential << endl;
    cout << "   Amount Earned: $" << total_earned << endl;
    cout << "   Potential Remaining: $" << (total_potential - total_earned) << endl;
    
    cout << "\n📸 CONTENT SUMMARY:" << endl;
    cout << "   Posts Completed: " << total_posts_done << endl;
    cout << "   Total Posts Required: " << total_posts_req << endl;
    cout << "   Completion Rate: " << ((double)total_posts_done/total_posts_req*100) << "%" << endl;
    
    if (total_posts_done > 0)
    {
        double avg_rate = total_earned / total_posts_done;
        cout << "   Average Per Post: $" << avg_rate << endl;
    }
    
    // Find highest paying deal
    if (count > 0)
    {
        int best_deal = 0;
        double best_rate = payments[0] / posts_req[0];
        
        for (int i = 1; i < count; i++)
        {
            double rate = payments[i] / posts_req[i];
            if (rate > best_rate)
            {
                best_rate = rate;
                best_deal = i;
            }
        }
        
        cout << "\n⭐ BEST DEAL: " << brands[best_deal] 
             << " ($" << best_rate << " per post)" << endl;
    }
}

void saveToFile(string brands[], double payments[], int posts_req[], 
                int posts_comp[], string deadlines[], int count)
{
    ofstream file("sponsorships.txt");
    
    file << count << endl;
    for (int i = 0; i < count; i++)
    {
        file << brands[i] << endl;
        file << payments[i] << endl;
        file << posts_req[i] << endl;
        file << posts_comp[i] << endl;
        file << deadlines[i] << endl;
    }
    
    file.close();
}

void loadFromFile(string brands[], double payments[], int posts_req[], 
                  int posts_comp[], string deadlines[], int& count)
{
    ifstream file("sponsorships.txt");
    
    if (!file)
    {
        count = 0;
        return;
    }
    
    file >> count;
    file.ignore(); // Clear newline
    
    for (int i = 0; i < count; i++)
    {
        getline(file, brands[i]);
        file >> payments[i];
        file >> posts_req[i];
        file >> posts_comp[i];
        file.ignore(); // Clear newline
        getline(file, deadlines[i]);
    }
    
    file.close();
}
```

## Assignment Requirements

### Level 1: Core Features
1. Track at least 5 sponsorship deals using arrays
2. Calculate total earnings and pending posts
3. Display all deals in a formatted list
4. Use at least 3 functions to organize code

### Level 2: Enhanced Features
1. **Payment Tracking**
   - Track partial payments based on completed posts
   - Show amount earned vs. potential earnings
   
2. **Deadline Management**
   - Store deadline dates for each deal
   - Alert when deadlines are approaching
   
3. **Performance Metrics**
   - Calculate average payment per post
   - Find best and worst paying deals
   - Show completion percentage

### Level 3: Professional Features
1. **File Persistence**
   - Save all deals to a file
   - Load deals when program starts
   - Export report to separate file

2. **Advanced Analytics**
   ```cpp
   // Calculate monthly projection
   double monthly_potential = 0;
   for (int i = 0; i < count; i++)
   {
       int days_to_complete = 30; // Assume 30 days
       double daily_rate = payments[i] / days_to_complete;
       monthly_potential += daily_rate * 30;
   }
   ```

3. **Smart Recommendations**
   ```cpp
   // Suggest which posts to prioritize
   cout << "\n💡 RECOMMENDATIONS:" << endl;
   
   // Find deals with best per-post rate that aren't complete
   for (int i = 0; i < count; i++)
   {
       if (posts_comp[i] < posts_req[i])
       {
           double rate = payments[i] / posts_req[i];
           if (rate > 500) // High-value threshold
           {
               cout << "⚡ Prioritize " << brands[i] 
                    << " - $" << rate << " per post!" << endl;
           }
       }
   }
   ```

## Common Mistakes to Avoid

1. **Array Bounds**
```cpp
// WRONG - Can crash if count >= MAX_DEALS
brands[count] = "New Brand";
count++;

// RIGHT - Check first
if (count < MAX_DEALS)
{
    brands[count] = "New Brand";
    count++;
}
```

2. **Function Parameters**
```cpp
// WRONG - Forgetting to pass arrays by reference
void updateCount(int count)  // Won't update original

// RIGHT - Pass by reference for values you want to change
void updateCount(int& count)  // Will update original
```

3. **File Handling**
```cpp
// Always check if file opened successfully
ifstream file("data.txt");
if (!file)
{
    cout << "No saved data found. Starting fresh!" << endl;
    return;
}
```

## Testing Scenarios

Test your program with these real-world scenarios:

1. **Beginner Creator**: 3 deals, $500-1000 each, 2-3 posts per deal
2. **Growing Influencer**: 8 deals, $1000-5000 each, varying deadlines
3. **Established Creator**: 15+ deals, some complete, some pending

## Extension Ideas

1. **Calendar Integration**: Show which posts are due this week
2. **Brand Categories**: Group deals by industry (tech, fashion, food)
3. **Revenue Forecasting**: Project earnings for next 3, 6, 12 months
4. **Contract Templates**: Generate basic contract terms
5. **Multi-Platform**: Track different requirements per platform

## Why This Matters

Professional content creators use tools like AspireIQ, GRIN, and Creator.co that cost $500-2000/month. You've just built the core functionality of these enterprise tools! This project demonstrates:

- **Real data management** using arrays
- **Business logic** with complex calculations  
- **Professional features** like file persistence
- **User interface design** with menus
- **Code organization** with functions

Remember: The difference between a student project and a real product is often just polish and features. You're building the same fundamental systems that power million-dollar businesses!

**Final Tip**: When debugging arrays, print their contents frequently. Array bugs are often just index errors - off by one mistakes that every programmer makes!