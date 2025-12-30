/*
    Hello, Real World! - A Budget Tracker
    
    Problem: You get $50 weekly allowance. How much is left after expenses?
    
    This program demonstrates:
    - Output to screen (cout)
    - Input from user (cin)
    - Variables and data types
    - Basic arithmetic
    - Real-world problem solving
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "==================================" << endl;
    cout << "    Weekly Budget Calculator 💰   " << endl;
    cout << "==================================" << endl;
    
    double weeklyAllowance = 50.00;
    double totalSpent = 0.0;
    
    cout << "Starting budget: $" << fixed << setprecision(2) << weeklyAllowance << endl;
    cout << "\nLet's track your expenses for the week." << endl;
    
    cout << "\nHow much did you spend on food? $";
    double foodExpense;
    cin >> foodExpense;
    totalSpent += foodExpense;
    
    cout << "How much did you spend on entertainment? $";
    double entertainmentExpense;
    cin >> entertainmentExpense;
    totalSpent += entertainmentExpense;
    
    cout << "How much did you spend on transportation? $";
    double transportExpense;
    cin >> transportExpense;
    totalSpent += transportExpense;
    
    cout << "Any other expenses? $";
    double otherExpense;
    cin >> otherExpense;
    totalSpent += otherExpense;
    
    double remainingBudget = weeklyAllowance - totalSpent;
    
    cout << "\n==================================" << endl;
    cout << "         Weekly Summary          " << endl;
    cout << "==================================" << endl;
    cout << "Starting budget:    $" << weeklyAllowance << endl;
    cout << "Total spent:        $" << totalSpent << endl;
    cout << "----------------------------------" << endl;
    
    if (remainingBudget >= 0) {
        cout << "Remaining:          $" << remainingBudget << endl;
        cout << "\n✅ Great job! You stayed within budget!" << endl;
        
        if (remainingBudget > 10) {
            cout << "💡 Tip: Consider saving some for next week!" << endl;
        }
    } else {
        cout << "Over budget by:     $" << -remainingBudget << endl;
        cout << "\n⚠️  Oops! You went over budget." << endl;
        cout << "💡 Tip: Try to reduce expenses next week." << endl;
    }
    
    cout << "==================================" << endl;
    
    return 0;
}