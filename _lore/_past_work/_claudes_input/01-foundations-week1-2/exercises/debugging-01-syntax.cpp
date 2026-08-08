// Debugging Exercise 1: The Broken Calculator
// Bug Count: 3 bugs
// Objective: Find and fix all bugs to make the calculator work correctly
//
// This program should calculate the total cost of items with tax
// Expected behavior:
// - Calculate subtotal (price * quantity)
// - Calculate tax (subtotal * tax rate)
// - Calculate and display total (subtotal + tax)

#include <iostream>
using namespace std;

int main()
{
    // This program should calculate the total cost of items with tax
    
    double price = 19.99
    int quantity = 3;
    double taxRate = 0.08;  // 8% tax
    
    double subtotal = price + quantity;  
    double tax = subtotal * taxRate;
    double total = subtotal + tax;
    
    cout << "Price per item: $" << price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Total: $" << Total << endl;
    
    return 0;
}

/* EXPECTED OUTPUT (when fixed):
Price per item: $19.99
Quantity: 3
Subtotal: $59.97
Tax: $4.80
Total: $64.77
*/

// HINTS:
// 1. Check your semicolons
// 2. Math operations - are you doing the right calculation?
// 3. C++ is case-sensitive

// LEARNING OBJECTIVES:
// - Identify missing semicolons
// - Fix incorrect mathematical operations
// - Understand case sensitivity in variable names

// After fixing, answer these questions:
// 1. What was bug #1 and why did it cause an error?
// 2. What was bug #2 and how did it affect the calculation?
// 3. What was bug #3 and what error message did it produce?
