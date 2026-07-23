// M3LAB2 — Taco Receipt (C tier reference solution)
// Taqueria La Terminal: order in, receipt out.
// Build: g++ -std=c++17 -Wall -Wextra -o m3lab2 m3lab2_taco_c.cpp

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // --- Menu prices (cents matter: these are dollars in a double) ---
    const double PRICE_PASTOR   = 3.29;   // taco al pastor
    const double PRICE_CARNITAS = 3.79;   // taco de carnitas
    const double PRICE_CHIPS    = 2.85;   // chips & salsa verde
    const double PRICE_HORCHATA = 2.60;   // horchata (large)
    const double TAX_RATE       = 0.07;   // 7% sales tax (Cumberland County, NC)

    // --- Input ---
    string customerName;
    cout << "Welcome to Taqueria La Terminal!" << endl;
    cout << "Name for the order: ";
    getline(cin, customerName);   // full name, spaces welcome

    int qtyPastor, qtyCarnitas, qtyChips, qtyHorchata;
    cout << "Tacos al pastor ($3.29 each): ";
    cin >> qtyPastor;
    cout << "Tacos de carnitas ($3.79 each): ";
    cin >> qtyCarnitas;
    cout << "Chips & salsa verde ($2.85 each): ";
    cin >> qtyChips;
    cout << "Horchata, large ($2.60 each): ";
    cin >> qtyHorchata;

    // --- Processing ---
    double subtotal = qtyPastor   * PRICE_PASTOR
                    + qtyCarnitas * PRICE_CARNITAS
                    + qtyChips    * PRICE_CHIPS
                    + qtyHorchata * PRICE_HORCHATA;
    double tax   = subtotal * TAX_RATE;
    double total = subtotal + tax;

    // --- Output: the receipt ---
    cout << fixed << setprecision(2);   // money displays with exactly 2 decimals
    cout << endl;
    cout << "------ TAQUERIA LA TERMINAL ------" << endl;
    cout << "Order for: " << customerName << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax (7%): $" << tax << endl;
    cout << "Total:    $" << total << endl;
    cout << "Gracias, come again!" << endl;
    return 0;
}
