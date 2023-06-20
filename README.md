## How to compile multiple C++ file in Visual Studio Code?
- **Step 1:** Open terminal using Ctrl + J or Cmd + J
- **Step 2**: Use the cd command to move to the directory containing the files
- **Step 3:** Enter 'g++ main.cpp difference.cpp -o main
- **Step 4:** Enter ./main and and start using
- **NOTES**: To re-compile, you just need to do the step 3 again if you're still at the directory as before.

## SAMPLE OF 'main.cpp' FILE

```
//Test the sum and difference functions
#include "difference.hpp"
#include "sum.hpp"

int main() {
    int stop = 0;
    while(stop == 0)
    {
        int option;
        cout << "-----------------------MENU------------------------\n";
        cout << "1. Sum of Two Integers of Optional Base.(2 <= base <= 10)\n";
        cout << "2. Difference of Two Integers of Optional Base.\n";
        cout << "---------------------------------------------------\n";
        cout << "Choose option: ";
        cin >> option;

        switch (option) {
            case 1:
            {
                int x, y;
                int base;

                cout << "Enter the base: ";
                cin >> base;

                cout << "Enter the 1st number: ";
                cin >> x;
                cout << "Enter the 2nd number: ";
                cin >> y;

                stack<long> s = sumofBase(x,y,base);
                
                cout << "Result: ";
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
                cout << "This option doesn't exist." << endl;

                cout << "Stop? (1 - YES, 0 - NO): ";
                cin >> stop;
                break;
            }
        }
    }
   
    return 0;
}

```
