/*
    Debugging Exercise 02: Function Bugs
    CSC 134 - Module 02
    
    🐛 THIS PROGRAM HAS 6 BUGS! 🐛
    
    Your mission: Find and fix all 6 bugs to make the program work correctly.
    
    The program SHOULD:
    - Welcome the user to a restaurant
    - Display a menu
    - Process an order with quantity
    - Apply a discount
    - Calculate and show the final total
    
    Debugging Tips (The Rubber Duck Method 🦆):
    1. Read each error message carefully - start with the FIRST one
    2. Check function names match between prototype, call, and definition
    3. Verify parameters match in type and number
    4. Look for missing & symbols where values need to change
    5. Make sure all functions are defined
    
    Remember: Every expert programmer has seen these errors hundreds of times.
    The difference? They know where to look!
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void displayWelcome();                              // BUG 1: Check this line
void displayMenu();
void processOrder(int itemNumber);                  // BUG 2: Missing parameter?
void applyDiscount(double price, double percent);   // BUG 3: Check the &
void calculateTotal(double price, double tax, double total); // BUG 4: Check the &

int main()
{
    displayWelcome();
    displaymenu();  // BUG 5: Check the function name
    
    int choice, quantity;
    cout << "Enter item number (1-3): ";
    cin >> choice;
    cout << "Enter quantity: ";
    cin >> quantity;
    
    processOrder(choice, quantity);  // Check if this matches prototype
    
    double price = 10.00 * quantity;  // Base price $10
    double discount = 10.0;           // 10% discount
    double taxRate = 0.08;            // 8% tax
    double tax = 0.0;
    double total = 0.0;
    
    cout << "\nOriginal price: $" << price << endl;
    
    applyDiscount(price, discount);
    cout << "After discount: $" << price << endl;
    
    calculateTotal(price, tax, total);
    cout << "Tax amount: $" << tax << endl;
    cout << "Final total: $" << total << endl;
    
    return 0;
}

// Function definitions
void displayWelcom()  // BUG 6: Check the function name
{
    cout << "=======================" << endl;
    cout << " WELCOME TO DEBUG DINER" << endl;
    cout << "=======================" << endl;
    cout << endl;
}

void displayMenu()
{
    cout << "===== MENU =====" << endl;
    cout << "1. Burger" << endl;
    cout << "2. Pizza" << endl;
    cout << "3. Salad" << endl;
    cout << "================" << endl;
    cout << endl;
}

void processOrder(int itemNumber, int quantity)
{
    cout << "\nProcessing order..." << endl;
    cout << "Item #" << itemNumber << " x " << quantity << endl;
}

void applyDiscount(double price, double percent)
{
    // This should modify the original price!
    double discount = price * (percent / 100.0);
    price = price - discount;
}

void calculateTotal(double price, double tax, double total)
{
    // This should modify tax and total!
    tax = price * 0.08;
    total = price + tax;
}

/*
   BUG LOCATIONS AND FIXES:
   =======================
   
   BUG 1 (Line 30): Function prototype doesn't match definition
   - Prototype says: displayWelcome()
   - Definition says: displayWelcom() [missing 'e']
   - FIX: Change line 63 to: void displayWelcome()
   
   BUG 2 (Line 32): processOrder prototype missing second parameter
   - Prototype has: (int itemNumber)
   - Call has: (choice, quantity)
   - Definition has: (int itemNumber, int quantity)
   - FIX: Change line 32 to: void processOrder(int itemNumber, int quantity);
   
   BUG 3 (Line 33): applyDiscount needs & to modify price
   - Currently: void applyDiscount(double price, double percent);
   - FIX: void applyDiscount(double &price, double percent);
   - Also fix line 86: void applyDiscount(double &price, double percent)
   
   BUG 4 (Line 34): calculateTotal needs & for tax and total
   - Currently: void calculateTotal(double price, double tax, double total);
   - FIX: void calculateTotal(double price, double &tax, double &total);
   - Also fix line 93: void calculateTotal(double price, double &tax, double &total)
   
   BUG 5 (Line 39): Wrong function name in call
   - Currently: displaymenu(); [lowercase 'm']
   - FIX: displayMenu(); [capital 'M']
   
   BUG 6 (Line 63): Function name misspelled
   - Currently: void displayWelcom()
   - FIX: void displayWelcome()
   
   CORRECT OUTPUT AFTER FIXING:
   ============================
   =======================
    WELCOME TO DEBUG DINER
   =======================
   
   ===== MENU =====
   1. Burger
   2. Pizza
   3. Salad
   ================
   
   Enter item number (1-3): 2
   Enter quantity: 3
   
   Processing order...
   Item #2 x 3
   
   Original price: $30
   After discount: $27
   Tax amount: $2.16
   Final total: $29.16
   
   LEARNING POINTS:
   ===============
   1. Function names must match EXACTLY (case sensitive!)
   2. Parameters in prototype, call, and definition must match
   3. Use & when you need to modify the original value
   4. Compiler errors tell you the line number - start there!
   5. "was not declared" usually means typo or missing prototype
   6. "too many/few arguments" means parameter count mismatch
   
   Remember: Debugging is a skill that improves with practice.
   Each bug you fix makes you better at spotting the next one!
*/