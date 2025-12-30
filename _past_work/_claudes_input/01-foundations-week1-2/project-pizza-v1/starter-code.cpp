// Pizza Order Calculator - Starter Code
// Project 1: Build a complete pizza ordering system
// 
// Requirements:
// 1. Display welcome message and menu
// 2. Get customer name (full name with spaces)
// 3. Get pizza size choice (1=Small, 2=Medium, 3=Large)
// 4. Get number of toppings
// 5. Calculate costs with tax
// 6. Display formatted receipt

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Constants for prices (DO NOT CHANGE THESE)
    const double SMALL_PRICE = 8.99;
    const double MEDIUM_PRICE = 12.99;
    const double LARGE_PRICE = 16.99;
    const double TOPPING_PRICE = 1.50;
    const double TAX_RATE = 0.0825;  // 8.25% tax
    
    // TODO: Declare variables for:
    // - Customer name (string)
    // - Pizza size choice (int)
    // - Number of toppings (int)
    // - Base price (double)
    // - Toppings cost (double)
    // - Subtotal (double)
    // - Tax amount (double)
    // - Total (double)
    
    // TODO: Display welcome message
    cout << "==================================" << endl;
    cout << "   WELCOME TO C++ PIZZA PALACE   " << endl;
    cout << "==================================" << endl;
    
    // TODO: Display menu with prices
    // Hint: Show all three sizes with their prices
    
    // TODO: Get customer name
    // IMPORTANT: Use getline() to handle full names with spaces!
    
    // TODO: Get pizza size choice (1, 2, or 3)
    
    // TODO: Get number of toppings
    
    // TODO: Calculate base price based on size choice
    // Hint: Use if-else statements
    
    // TODO: Calculate toppings cost
    // Formula: number of toppings * TOPPING_PRICE
    
    // TODO: Calculate subtotal
    // Formula: base price + toppings cost
    
    // TODO: Calculate tax
    // Formula: subtotal * TAX_RATE
    
    // TODO: Calculate total
    // Formula: subtotal + tax
    
    // TODO: Display receipt
    cout << "\n==================================" << endl;
    cout << "         YOUR RECEIPT            " << endl;
    cout << "==================================" << endl;
    // Display customer name
    // Display pizza size (as text: Small, Medium, or Large)
    // Display base price
    // Display number of toppings and toppings cost
    // Display subtotal
    // Display tax
    // Display total
    cout << "==================================" << endl;
    cout << "    Thank you for your order!    " << endl;
    cout << "==================================" << endl;
    
    return 0;
}

/* SAMPLE RUN:
==================================
   WELCOME TO C++ PIZZA PALACE   
==================================
Our Pizza Sizes:
1. Small - $8.99
2. Medium - $12.99
3. Large - $16.99

Enter your full name: Maria Garcia
Enter pizza size (1-3): 2
How many toppings? 3

==================================
         YOUR RECEIPT            
==================================
Customer: Maria Garcia
Size: Medium
Base Price: $12.99
Toppings (3): $4.50
----------------------------------
Subtotal: $17.49
Tax: $1.44
==================================
TOTAL: $18.93
==================================
    Thank you for your order!    
==================================
*/

// GRADING RUBRIC:
// Functionality (40 points)
// - [ ] Program compiles and runs (10)
// - [ ] Correctly calculates all values (10)
// - [ ] Handles full names with spaces (10)
// - [ ] All requirements met (10)
//
// Code Quality (30 points)
// - [ ] Proper variable names (10)
// - [ ] Constants used appropriately (10)
// - [ ] Code is organized and readable (10)
//
// Output Format (20 points)
// - [ ] Professional looking receipt (10)
// - [ ] All information displayed clearly (10)
//
// Documentation (10 points)
// - [ ] Comments explain logic (5)
// - [ ] Complex calculations explained (5)
