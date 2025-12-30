/*
    Practice 04: Functions with Parameters
    CSC 134 - Module 02
    
    Learning Goals:
    - Pass information TO functions using parameters
    - Work with multiple parameters
    - Understand how parameters make functions flexible
    
    Your Task:
    Extend your restaurant system to process specific orders
    using functions that accept parameters.
    
    Pro Tip: Parameters are like ingredients you give to a recipe.
    The function uses them to create something specific!
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototypes with parameters
void greetCustomerByName(string customerName);
void processOrder(int itemNumber, int quantity);
void calculatePrice(int itemNumber, int quantity);
void printReceipt(string itemName, double totalPrice);

int main()
{
    // Get customer name
    string name;
    cout << "Welcome! What's your name? ";
    getline(cin, name);
    
    // Use the function with the customer's name
    greetCustomerByName(name);
    
    // Get order details
    int item, qty;
    cout << "\nWhat item number would you like? (1-3): ";
    cin >> item;
    cout << "How many would you like? ";
    cin >> qty;
    
    // Process the order with parameters
    processOrder(item, qty);
    calculatePrice(item, qty);
    
    return 0;
}

// Function that accepts ONE parameter
void greetCustomerByName(string customerName)
{
    cout << "\n==================================" << endl;
    cout << "  Hello, " << customerName << "!" << endl;
    cout << "  Welcome to C++ Cafe!" << endl;
    cout << "==================================" << endl;
}

// Function that accepts TWO parameters
void processOrder(int itemNumber, int quantity)
{
    cout << "\nProcessing your order..." << endl;
    cout << "Item #" << itemNumber << " x " << quantity << endl;
    
    // TODO: Add a switch statement to show item names
    // switch(itemNumber)
    // {
    //     case 1:
    //         cout << "Pizza(s) coming up!" << endl;
    //         break;
    //     // Add more cases
    // }
}

// Function to calculate and display price
void calculatePrice(int itemNumber, int quantity)
{
    double price = 0.0;
    string itemName = "";
    
    // Determine price based on item number
    switch(itemNumber)
    {
        case 1:
            price = 12.99;
            itemName = "Pizza";
            break;
        case 2:
            price = 8.99;
            itemName = "Burger";
            break;
        case 3:
            price = 6.99;
            itemName = "Salad";
            break;
        default:
            cout << "Invalid item number!" << endl;
            return;  // Exit the function early
    }
    
    double total = price * quantity;
    
    // Call another function with our calculated values
    printReceipt(itemName, total);
}

// Function that formats and prints a receipt
void printReceipt(string itemName, double totalPrice)
{
    cout << "\n--- RECEIPT ---" << endl;
    cout << "Item: " << itemName << endl;
    cout << "Total: $" << totalPrice << endl;
    cout << "Thank you!" << endl;
    cout << "---------------" << endl;
}

/*
   PRACTICE CHALLENGES:
   ===================
   
   1. Easy: Add a function that accepts a discount percentage
      void applyDiscount(double price, double discountPercent);
   
   2. Medium: Create a function that accepts a day of week
      and returns different specials
      void showDailySpecial(string dayOfWeek);
   
   3. Hard: Make a function that processes multiple items
      void processMultipleOrders(int item1, int qty1, int item2, int qty2);
   
   4. Creative: Add a function that creates ASCII art with the customer's name
      void createPersonalizedBanner(string name);
   
   COMMON MISTAKES TO AVOID:
   ========================
   
   ❌ Forgetting to match parameter types:
      void greet(string name);  // Expects string
      greet(123);               // ERROR! Sending int
   
   ❌ Wrong number of parameters:
      void calculate(int a, int b);  // Expects 2
      calculate(5);                   // ERROR! Only sending 1
   
   ❌ Parameters in wrong order:
      void order(int item, int qty);
      order(3, 1);  // Correct: item 3, quantity 1
      order(1, 3);  // Different! item 1, quantity 3
   
   REMEMBER:
   ========
   Parameters make your functions flexible and reusable.
   Instead of writing 10 different greeting functions,
   write ONE that accepts a name parameter!
   
   Expected Sample Output:
   ======================
   Welcome! What's your name? Alice
   
   ==================================
     Hello, Alice!
     Welcome to C++ Cafe!
   ==================================
   
   What item number would you like? (1-3): 1
   How many would you like? 2
   
   Processing your order...
   Item #1 x 2
   
   --- RECEIPT ---
   Item: Pizza
   Total: $25.98
   Thank you!
   ---------------
*/