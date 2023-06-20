//Test the difference and sum function
#include "difference.hpp"
#include "sum.hpp"

int main() {
    int stop = 0;
    cout << "BASIC SUM AND DIFFERENCE CALCULATOR IN BASE B" << endl;
    while (stop == 0) {
        cout << "Choose one of the functions below:" << endl;
        cout << "1 - Sum of base-b numbers" << endl;
        cout << "2 - Difference of base-b numbers" << endl;

        int func = 0;
        cout << "Choose function number: ";
        cin >> func;

        // if (cin.rdstate() > 0) {
        //     cin.clear();
        // }

        switch (func) {
            case 1:
            {
                int base = 0; // 2<= base <= 10
                long x = 0;
                long y = 0;

                cout << "Enter the base: ";
                cin >> base;

                cout << "Enter two numbers: ";
                cin >> x >> y;

                stack<long> s = sumofBase(x,y,base);

                printStack(s);

                cout << "Stop? (1 - YES, 0 - NO): ";
                cin >> stop;
                break;
            }
            case 2:
            {
                string a, b;
                int base;
                
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

                cout << "Stop? (1 - YES, 0 - NO): ";
                cin >> stop;
                break;
            }
            default:
            {
                cout << "Function doesn't exist." << endl;

                cout << "Stop? (1 - YES, 0 - NO): ";
                cin >> stop;
                break;
            }
        }
    }
}