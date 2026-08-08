/*
    Practice 05: Scope and Pass by Reference
    CSC 134 - Module 02
    
    Learning Goals:
    - Understand variable scope (what happens in functions, stays in functions)
    - Use pass by reference with & to modify original values
    - Know when to use pass by value vs pass by reference
    
    The Big Idea:
    By default, functions get COPIES of values (pass by value).
    With &, functions get PORTALS to the originals (pass by reference).
    
    🎯 This is where functions get POWERFUL!
*/

#include <iostream>
using namespace std;

// Function prototypes - notice the & symbols!
void demonstrateScope();
void tryToModify(double price);           // No & = pass by value (copy)
void actuallyModify(double &price);       // With & = pass by reference (portal)
void applyTax(double &amount);
void applyDiscount(double &amount, double discountPercent);
void calculateTotals(double subtotal, double &tax, double &total);

int main()
{
    cout << "=== UNDERSTANDING SCOPE ===" << endl;
    demonstrateScope();
    
    cout << "\n=== PASS BY VALUE vs REFERENCE ===" << endl;
    
    double itemPrice = 20.00;
    cout << "Starting price: $" << itemPrice << endl;
    
    // This WON'T change itemPrice
    cout << "\nTrying to modify (pass by value):" << endl;
    tryToModify(itemPrice);
    cout << "Price in main after tryToModify: $" << itemPrice << endl;
    
    // This WILL change itemPrice
    cout << "\nActually modifying (pass by reference):" << endl;
    actuallyModify(itemPrice);
    cout << "Price in main after actuallyModify: $" << itemPrice << endl;
    
    // Real-world example: Shopping cart
    cout << "\n=== SHOPPING CART EXAMPLE ===" << endl;
    double cartTotal = 50.00;
    double taxAmount = 0.0;
    double finalTotal = 0.0;
    
    cout << "Cart subtotal: $" << cartTotal << endl;
    
    // Apply 20% discount
    applyDiscount(cartTotal, 20.0);
    cout << "After discount: $" << cartTotal << endl;
    
    // Calculate tax and total (modifies multiple values!)
    calculateTotals(cartTotal, taxAmount, finalTotal);
    
    cout << "\nFinal Receipt:" << endl;
    cout << "Subtotal: $" << cartTotal << endl;
    cout << "Tax: $" << taxAmount << endl;
    cout << "Total: $" << finalTotal << endl;
    
    return 0;
}

// Demonstrates that variables in functions are separate
void demonstrateScope()
{
    int myNumber = 100;  // This is LOCAL to demonstrateScope
    cout << "Inside demonstrateScope: myNumber = " << myNumber << endl;
    
    // This myNumber is completely separate from any other myNumber
    // in other functions. It's like having the same name in
    // different classrooms - they're different people!
}

// Pass by VALUE - gets a COPY
void tryToModify(double price)  // No & means COPY
{
    cout << "  Inside tryToModify: price starts at $" << price << endl;
    price = price * 2;  // This only changes the COPY
    cout << "  Inside tryToModify: price changed to $" << price << endl;
    // When function ends, the copy disappears!
}

// Pass by REFERENCE - gets a PORTAL to original
void actuallyModify(double &price)  // & means PORTAL
{
    cout << "  Inside actuallyModify: price starts at $" << price << endl;
    price = price * 2;  // This changes the ORIGINAL
    cout << "  Inside actuallyModify: price changed to $" << price << endl;
    // Changes persist because we modified the original!
}

// Practical function: Apply tax
void applyTax(double &amount)
{
    double tax = amount * 0.08;  // 8% tax
    amount = amount + tax;
}

// Practical function: Apply discount
void applyDiscount(double &amount, double discountPercent)
{
    double discount = amount * (discountPercent / 100.0);
    amount = amount - discount;
}

// Function that modifies MULTIPLE values using references
void calculateTotals(double subtotal, double &tax, double &total)
{
    // subtotal is pass by value (we don't change it)
    // tax and total are pass by reference (we DO change them)
    
    tax = subtotal * 0.08;      // Calculate 8% tax
    total = subtotal + tax;     // Calculate final total
}

/*
   VISUAL EXPLANATION:
   ==================
   
   Pass by Value (Default):
   main: price[10.00] ──copy──> function: price[10.00]
                                          ↓ (changes)
                                         price[20.00]
                                          ↓ (function ends)
                                         [disappears]
   main: price[10.00] (unchanged!)
   
   Pass by Reference (with &):
   main: price[10.00] ←──portal──→ function: &price
                      ↓ (changes through portal)
                    price[20.00]
   main: price[20.00] (changed!)
   
   PRACTICE CHALLENGES:
   ===================
   
   1. Create a function that swaps two values:
      void swap(int &a, int &b);
      
   2. Make a function that converts temperature and returns via reference:
      void convertTemp(double celsius, double &fahrenheit);
      
   3. Build a function that validates and modifies user input:
      void validateAge(int &age);  // Ensures age is 0-120
   
   COMMON MISTAKES:
   ===============
   
   ❌ Forgetting the & when you need to modify:
      void addTip(double bill)     // Won't work!
      void addTip(double &bill)    // Will work!
   
   ❌ Using & when you shouldn't:
      void display(double &value)  // Don't need & just to display
      void display(double value)   // Better - no need to modify
   
   ❌ Trying to return multiple values without &:
      void calculate(double a, double b, double sum, double diff)  // Won't work!
      void calculate(double a, double b, double &sum, double &diff) // Will work!
   
   REMEMBER:
   ========
   - No & = Function gets a COPY (safe but can't modify original)
   - With & = Function gets a PORTAL (can modify original)
   - Use & when you NEED to change the original value
   - Use & to "return" multiple values from a function
   
   Expected Output:
   ===============
   === UNDERSTANDING SCOPE ===
   Inside demonstrateScope: myNumber = 100
   
   === PASS BY VALUE vs REFERENCE ===
   Starting price: $20
   
   Trying to modify (pass by value):
     Inside tryToModify: price starts at $20
     Inside tryToModify: price changed to $40
   Price in main after tryToModify: $20
   
   Actually modifying (pass by reference):
     Inside actuallyModify: price starts at $20
     Inside actuallyModify: price changed to $40
   Price in main after actuallyModify: $40
   
   === SHOPPING CART EXAMPLE ===
   Cart subtotal: $50
   After discount: $40
   
   Final Receipt:
   Subtotal: $40
   Tax: $3.2
   Total: $43.2
*/