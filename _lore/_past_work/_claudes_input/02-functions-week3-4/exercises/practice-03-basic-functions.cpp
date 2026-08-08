/*
    Practice 03: Basic Functions
    CSC 134 - Module 02
    
    Learning Goals:
    - Create your first void functions
    - Use function prototypes
    - Understand the flow of control
    
    Your Task:
    Build a simple restaurant greeting system with separate functions
    for each part of the customer interaction.
    
    Remember: Every expert was once a beginner. If this feels weird,
    that's normal! Soon you'll be writing functions as naturally as
    texting a friend.
*/

#include <iostream>
#include <string>
using namespace std;

// TODO: Create these function prototypes
// Hint: They all return void and take no parameters
// Example: void functionName();

// YOUR PROTOTYPES HERE:



int main()
{
    cout << "=== Restaurant System Starting ===" << endl;
    cout << endl;
    
    // TODO: Call your functions in the right order
    // 1. Display welcome message
    // 2. Display menu
    // 3. Get one menu choice (for now, just input)
    // 4. Display goodbye message
    
    // YOUR FUNCTION CALLS HERE:
    
    
    
    // Temporary - remove this when you add your functions
    cout << "[Your restaurant functions will go here]" << endl;
    
    return 0;
}

// TODO: Write your function definitions below
// Each function should do ONE thing well

// Function 1: Display a creative welcome message
// Make it match YOUR restaurant theme!
// Ideas: ASCII art, borders, catchy slogan
void displayWelcome()
{
    // YOUR CODE HERE
    // Example structure:
    // cout << "==================================" << endl;
    // cout << "   WELCOME TO [YOUR NAME]'S CAFE  " << endl;
    // cout << "==================================" << endl;
}

// Function 2: Display your menu
// Should show at least 3 items with prices
void displayMenu()
{
    // YOUR CODE HERE
    // Example:
    // cout << "--- MENU ---" << endl;
    // cout << "1. Pizza  ($12.99)" << endl;
    // Add more items!
}

// Function 3: Display a goodbye message
// Thank the customer for visiting
void displayGoodbye()
{
    // YOUR CODE HERE
}

/* 
   COMPLETE SOLUTION (Don't peek until you try!)
   =============================================
   
   Prototypes:
   void displayWelcome();
   void displayMenu();
   void displayGoodbye();
   
   In main():
   displayWelcome();
   displayMenu();
   
   int choice;
   cout << "Enter your choice (1-3): ";
   cin >> choice;
   cout << "You ordered item #" << choice << endl;
   
   displayGoodbye();
   
   Function definitions:
   void displayWelcome()
   {
       cout << "==================================" << endl;
       cout << "   WELCOME TO BYTE BURGER BARN   " << endl;
       cout << "   Where Every Byte is Delicious! " << endl;
       cout << "==================================" << endl;
       cout << endl;
   }
   
   void displayMenu()
   {
       cout << "--- TODAY'S MENU ---" << endl;
       cout << "1. Classic Burger  ($8.99)" << endl;
       cout << "2. Veggie Wrap     ($7.99)" << endl;
       cout << "3. Fish & Chips    ($10.99)" << endl;
       cout << endl;
   }
   
   void displayGoodbye()
   {
       cout << endl;
       cout << "Thank you for visiting!" << endl;
       cout << "Come back soon! 🍔" << endl;
   }
   
   Expected Output:
   ==================================
      WELCOME TO BYTE BURGER BARN   
      Where Every Byte is Delicious! 
   ==================================
   
   --- TODAY'S MENU ---
   1. Classic Burger  ($8.99)
   2. Veggie Wrap     ($7.99)
   3. Fish & Chips    ($10.99)
   
   Enter your choice (1-3): 2
   You ordered item #2
   
   Thank you for visiting!
   Come back soon! 🍔
*/