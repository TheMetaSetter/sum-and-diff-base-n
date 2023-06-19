//Test the difference function
#include "difference.h"

int main() {
    string a, b;
    int base;
    
    cout << "Input base: ";
    cin >> base;
    cout << "Input number a: ";
    cin >> a;
    cout << "Input number b: ";
    cin >> b;
    
    cout << "(|a - b|)_" << base << " = " << difference(a, b, base) << "_" << base << endl;
    
    return 0;
}