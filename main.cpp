//Test the difference function
#include "difference.hpp"
#include "sum.hpp"

int main() {
    string a, b;
    int x, y;
    int base;
    int lc = 0;

    while(true)
    {
        cout << "-----------------------MENU------------------------\n";
        cout << "1. Sum of Two Integers of Optional Base.(2 <= base <= 10)\n";
        cout << "2. Difference of Two Integers of Optional Base.\n";
        cout << "---------------------------------------------------\n";
        cin >> lc;

        if(lc == 1)
        {
            cout << "Enter the base: ";
            cin >> base;

            cout << "Enter the 1st number: ";
            cin >> x;
            cout << "Enter the 2nd number: ";
            cin >> y;

            stack<long> s = sumofBase(x,y,base);
            
            cout << "Result: ";
            printStack(s);
        }
        else if(lc == 2)
        {
            cout << "Input base: ";
            cin >> base;
            cout << "Input number a: ";
            cin >> a;
            cout << "Input number b: ";
            cin >> b;
            
            string result = difference(a, b, base);
            if (result == "NaN") {
                cout << "Function 'difference':" << endl;
                cout << "Error: Cannot find the difference since the input is invalid." << endl;
                return 0;
            }
            else {
                cout << "(|a - b|)_" << base << " = " << result << "_" << base << endl;
            }
        }
        else 
        {
            break;
        }
    }
   
    return 0;
}