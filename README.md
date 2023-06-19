# sum-and-diff-base-n

/*
Compile multiple C++ file in Visual Studio Code
Step 1: Open terminal using Ctrl + J or Cmd + J
Step 2: Use the cd command to move to the directory containing the files
Step 3: Enter 'g++ main.cpp difference.cpp -o main
Step 4: Enter ./main and and start using
NOTES: To re-compile, you just need to do the step 3 again if you're still at the directory as before.
*/

/*
SAMPLE OF 'main.cpp' FILE
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

*/
