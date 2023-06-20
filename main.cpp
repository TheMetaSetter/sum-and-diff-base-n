//Test the difference function
#include "difference.hpp"

int main() {
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
    
    return 0;
}