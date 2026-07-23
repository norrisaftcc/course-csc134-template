// M3LAB2 — Taco Receipt (A tier reference solution)
// Taqueria La Terminal: order in, receipt out, machine X-ray at the end.
// Build: g++ -std=c++17 -Wall -Wextra -o m3lab2 m3lab2_taco_a.cpp
//
// A-TIER QUESTION (answer in your own words, 3-5 sentences):
// The X-ray shows the SAME variables as the receipt, but the digits differ.
// Which one is the "real" value? Answer: the X-ray is closer to the truth.
// A double stores the nearest binary fraction to your number -- most prices
// (like 3.29) cannot be stored exactly, so the machine keeps a value that is
// very close but not equal. The receipt doesn't show the value; it shows a
// ROUNDED PICTURE of the value, painted by fixed + setprecision(2).
// Representation is what the variable holds. Display is what you choose to
// show. They are not the same thing -- and the missing penny proves it.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // --- Menu prices ---
    const double PRICE_PASTOR   = 3.29;
    const double PRICE_CARNITAS = 3.79;
    const double PRICE_CHIPS    = 2.85;
    const double PRICE_HORCHATA = 2.60;
    const double TAX_RATE       = 0.07;   // 7% sales tax (Cumberland County, NC)
    const int    ORDER_NUMBER   = 42;

    // --- Input ---
    string customerName;
    cout << "Welcome to Taqueria La Terminal!" << endl;
    cout << "Name for the order: ";
    getline(cin, customerName);

    int qtyPastor, qtyCarnitas, qtyChips, qtyHorchata;
    double tipPercent;
    cout << "Tacos al pastor ($3.29 each): ";
    cin >> qtyPastor;
    cout << "Tacos de carnitas ($3.79 each): ";
    cin >> qtyCarnitas;
    cout << "Chips & salsa verde ($2.85 each): ";
    cin >> qtyChips;
    cout << "Horchata, large ($2.60 each): ";
    cin >> qtyHorchata;
    cout << "Tip percent (like 15): ";
    cin >> tipPercent;

    // --- Processing ---
    double linePastor   = qtyPastor   * PRICE_PASTOR;
    double lineCarnitas = qtyCarnitas * PRICE_CARNITAS;
    double lineChips    = qtyChips    * PRICE_CHIPS;
    double lineHorchata = qtyHorchata * PRICE_HORCHATA;
    double subtotal = linePastor + lineCarnitas + lineChips + lineHorchata;
    double tax      = subtotal * TAX_RATE;
    double tip      = subtotal * (tipPercent / 100.0);   // tip on subtotal, before tax
    double total    = subtotal + tax + tip;

    // --- Output: the receipt ---
    cout << fixed << setprecision(2);
    cout << endl;
    cout << "======================================" << endl;
    cout << "       TAQUERIA LA TERMINAL" << endl;
    cout << "   Order #" << ORDER_NUMBER << "  for  " << customerName << endl;
    cout << "======================================" << endl;
    cout << left  << setw(22) << "ITEM"
         << right << setw(4)  << "QTY"
         << setw(10) << "AMOUNT" << endl;
    cout << "--------------------------------------" << endl;
    cout << left  << setw(22) << "Taco al pastor"
         << right << setw(4)  << qtyPastor
         << setw(9)  << linePastor << endl;
    cout << left  << setw(22) << "Taco de carnitas"
         << right << setw(4)  << qtyCarnitas
         << setw(9)  << lineCarnitas << endl;
    cout << left  << setw(22) << "Chips & salsa verde"
         << right << setw(4)  << qtyChips
         << setw(9)  << lineChips << endl;
    cout << left  << setw(22) << "Horchata (large)"
         << right << setw(4)  << qtyHorchata
         << setw(9)  << lineHorchata << endl;
    cout << "--------------------------------------" << endl;
    cout << left  << setw(26) << "Subtotal"   << right << setw(9) << subtotal << endl;
    cout << left  << setw(26) << "Tax (7%)"   << right << setw(9) << tax      << endl;
    cout << left  << setw(26) << "Tip"        << right << setw(9) << tip      << endl;
    cout << left  << setw(26) << "TOTAL"      << right << setw(9) << total    << endl;
    cout << "======================================" << endl;
    cout << "        Gracias, come again!" << endl;

    // --- The X-ray: same variables, different display ---
    cout << endl;
    cout << "---------- MACHINE X-RAY ----------" << endl;
    cout << "(the same variables, shown with setprecision(17))" << endl;
    cout << setprecision(17);
    cout << "subtotal = " << subtotal << endl;
    cout << "tax      = " << tax      << endl;
    cout << "tip      = " << tip      << endl;
    cout << "total    = " << total    << endl;
    cout << "-----------------------------------" << endl;
    return 0;
}
