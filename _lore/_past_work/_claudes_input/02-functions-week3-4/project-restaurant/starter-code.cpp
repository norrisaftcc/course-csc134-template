/*
    Project: Restaurant Management System
    CSC 134 - Module 02 (Weeks 3-4)
    
    Build a professional restaurant ordering system using functions!
    
    This starter code gives you the structure - you add the creativity!
    Feel free to change the restaurant theme to match your interests:
    - K-Pop Fusion Burger
    - Viking Feast Hall  
    - Cyberpunk Noodle Bar
    - Grandma's Kitchen
    - Whatever excites you!
    
    Requirements:
    ✅ At least 6 meaningful functions
    ✅ Use of parameters (both value and reference)
    ✅ Professional-looking output
    ✅ Handle multiple orders
    ✅ Calculate totals with tax
    ✅ Apply discounts or special offers
    
    Flash can help you brainstorm creative themes and menu items!
*/

#include <iostream>
#include <string>
#include <iomanip>  // For formatting prices
using namespace std;

// ============================================
// CONSTANTS - Customize these for your restaurant!
// ============================================
const double TAX_RATE = 0.08;           // 8% tax
const double STUDENT_DISCOUNT = 0.10;   // 10% student discount
const double COMBO_DISCOUNT = 0.15;     // 15% off combos

// Menu prices - change these to match your theme!
const double ITEM1_PRICE = 12.99;  // e.g., "Bulgogi Burger"
const double ITEM2_PRICE = 8.99;   // e.g., "Kimchi Fries"
const double ITEM3_PRICE = 5.99;   // e.g., "Taro Boba"
const double ITEM4_PRICE = 14.99;  // e.g., "Special Combo"

// ============================================
// FUNCTION PROTOTYPES
// ============================================
void displayWelcome();
void displayMenu();
void displayGoodbye();
int getValidChoice(int min, int max);
void processOrder(int choice, int quantity, double &subtotal);
void checkForDiscounts(double &subtotal);
void applyStudentDiscount(double &amount);
void calculateTax(double subtotal, double &tax);
void calculateTotal(double subtotal, double tax, double &total);
void displayReceipt(double subtotal, double discount, double tax, double total);

// ============================================
// MAIN FUNCTION
// ============================================
int main()
{
    // Set up price formatting
    cout << fixed << setprecision(2);
    
    double runningSubtotal = 0.0;
    double totalDiscount = 0.0;
    double tax = 0.0;
    double finalTotal = 0.0;
    char orderMore = 'y';
    
    // Welcome the customer
    displayWelcome();
    
    // Main ordering loop
    while (orderMore == 'y' || orderMore == 'Y')
    {
        displayMenu();
        
        // Get and validate menu choice
        cout << "Enter item number: ";
        int choice = getValidChoice(1, 4);
        
        // Get quantity
        cout << "How many would you like? ";
        int quantity;
        cin >> quantity;
        
        // Process this order
        processOrder(choice, quantity, runningSubtotal);
        
        cout << "\nCurrent subtotal: $" << runningSubtotal << endl;
        cout << "Would you like to order more? (y/n): ";
        cin >> orderMore;
        cout << endl;
    }
    
    // Check for and apply discounts
    double originalSubtotal = runningSubtotal;
    checkForDiscounts(runningSubtotal);
    totalDiscount = originalSubtotal - runningSubtotal;
    
    // Calculate tax and total
    calculateTax(runningSubtotal, tax);
    calculateTotal(runningSubtotal, tax, finalTotal);
    
    // Display final receipt
    displayReceipt(originalSubtotal, totalDiscount, tax, finalTotal);
    
    // Say goodbye
    displayGoodbye();
    
    return 0;
}

// ============================================
// FUNCTION DEFINITIONS
// ============================================

void displayWelcome()
{
    // TODO: Make this match YOUR restaurant theme!
    // Add ASCII art, colors (if you know how), personality!
    
    cout << "================================================" << endl;
    cout << "     WELCOME TO [YOUR RESTAURANT NAME]         " << endl;
    cout << "         [Your Catchy Slogan Here]             " << endl;
    cout << "================================================" << endl;
    cout << endl;
    
    // Example of themed welcome:
    // cout << "🍔 ================================== 🍟" << endl;
    // cout << "    WELCOME TO K-POP FUSION BURGER      " << endl;
    // cout << "    Where Seoul Meets Your Soul Food!    " << endl;
    // cout << "🥤 ================================== 🍜" << endl;
}

void displayMenu()
{
    cout << "============== TODAY'S MENU ==============" << endl;
    
    // TODO: Customize these items for your restaurant!
    cout << "1. [Item 1 Name]            $" << ITEM1_PRICE << endl;
    cout << "   [Description]" << endl;
    
    cout << "2. [Item 2 Name]            $" << ITEM2_PRICE << endl;
    cout << "   [Description]" << endl;
    
    cout << "3. [Item 3 Name]            $" << ITEM3_PRICE << endl;
    cout << "   [Description]" << endl;
    
    cout << "4. [Special Combo]          $" << ITEM4_PRICE << endl;
    cout << "   [What's included]" << endl;
    
    cout << "=========================================" << endl;
    
    // Example of themed menu:
    // cout << "1. Bulgogi Burger           $12.99" << endl;
    // cout << "   Korean BBQ beef with kimchi slaw" << endl;
}

int getValidChoice(int min, int max)
{
    int choice;
    
    // TODO: Add input validation
    // Make sure choice is between min and max
    // Keep asking until valid input is received
    
    cin >> choice;
    
    // Basic validation (expand this!)
    while (choice < min || choice > max)
    {
        cout << "Invalid choice. Please enter " << min << "-" << max << ": ";
        cin >> choice;
    }
    
    return choice;
}

void processOrder(int choice, int quantity, double &subtotal)
{
    double itemPrice = 0.0;
    string itemName = "";
    
    // TODO: Set price and name based on choice
    switch(choice)
    {
        case 1:
            itemPrice = ITEM1_PRICE;
            itemName = "[Item 1 Name]";  // Replace with your item
            break;
        case 2:
            itemPrice = ITEM2_PRICE;
            itemName = "[Item 2 Name]";
            break;
        case 3:
            itemPrice = ITEM3_PRICE;
            itemName = "[Item 3 Name]";
            break;
        case 4:
            itemPrice = ITEM4_PRICE;
            itemName = "[Special Combo]";
            cout << "Great choice! Combo includes 15% discount!" << endl;
            break;
    }
    
    double orderTotal = itemPrice * quantity;
    subtotal += orderTotal;
    
    cout << "\n✓ Added " << quantity << " x " << itemName 
         << " ($" << orderTotal << ")" << endl;
}

void checkForDiscounts(double &subtotal)
{
    char isStudent;
    cout << "\nAre you a student? (y/n): ";
    cin >> isStudent;
    
    if (isStudent == 'y' || isStudent == 'Y')
    {
        applyStudentDiscount(subtotal);
        cout << "Student discount applied!" << endl;
    }
    
    // TODO: Add other discount conditions
    // Happy hour? Senior discount? Loyalty program?
}

void applyStudentDiscount(double &amount)
{
    double discount = amount * STUDENT_DISCOUNT;
    amount = amount - discount;
}

void calculateTax(double subtotal, double &tax)
{
    tax = subtotal * TAX_RATE;
}

void calculateTotal(double subtotal, double tax, double &total)
{
    total = subtotal + tax;
}

void displayReceipt(double subtotal, double discount, double tax, double total)
{
    cout << "\n\n";
    cout << "==================== RECEIPT ====================" << endl;
    cout << "[Your Restaurant Name]" << endl;
    cout << "=================================================" << endl;
    
    cout << "Subtotal:                      $" << setw(8) << subtotal << endl;
    
    if (discount > 0)
    {
        cout << "Discount:                     -$" << setw(8) << discount << endl;
        cout << "After discount:                $" << setw(8) << (subtotal - discount) << endl;
    }
    
    cout << "Tax (" << (TAX_RATE * 100) << "%):                   $" << setw(8) << tax << endl;
    cout << "=================================================" << endl;
    cout << "TOTAL:                         $" << setw(8) << total << endl;
    cout << "=================================================" << endl;
    
    // TODO: Add fun receipt footer
    // Order number? Estimated wait time? Thank you message?
}

void displayGoodbye()
{
    cout << "\n";
    cout << "================================================" << endl;
    cout << "         THANK YOU FOR YOUR ORDER!             " << endl;
    cout << "          [Add a fun goodbye message]          " << endl;
    cout << "================================================" << endl;
    
    // Example themed goodbye:
    // cout << "   Annyeong! See you next time! 안녕!    " << endl;
    // cout << "      Follow us @KPopBurger 🍔          " << endl;
}

/*
    CREATIVITY CHALLENGES:
    =====================
    
    1. Add ASCII art to your welcome/goodbye messages
    2. Create a "daily special" that changes based on the day
    3. Implement a loyalty points system
    4. Add wait time estimates based on order size
    5. Create custom messages for large orders
    6. Add emoji to make output more fun (if your terminal supports it)
    7. Implement happy hour pricing (time-based discounts)
    8. Add order confirmation with order number
    
    TESTING CHECKLIST:
    ==================
    □ Order single item
    □ Order multiple items
    □ Test student discount
    □ Test invalid menu choices
    □ Order quantity of 0 or negative
    □ Calculate tax correctly
    □ Format prices to 2 decimal places
    □ All functions work together smoothly
    
    GRADING RUBRIC TARGETS:
    =======================
    Function Organization (25 pts): ✓ 10+ functions, each with clear purpose
    Parameter Usage (25 pts): ✓ Multiple reference parameters used correctly
    Code Runs (20 pts): ✓ No crashes, handles edge cases
    User Experience (15 pts): ✓ Clear, themed, professional output
    Code Quality (10 pts): ✓ Well-commented, good variable names
    Flash Log (5 pts): ✓ Show your creative development process
    
    Remember: Have fun with this! The best projects show personality!
*/