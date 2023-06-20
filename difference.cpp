#include "difference.hpp"

ll convertBaseNDigitToDigit(char d, int base) {
    ll result = NAN;
    //If d is from '0' to '9' in ASCII
    if (d >= 48 && d <= 57) {
        result = (ll)(d - 48);
    }
    //If d is from 'A' to 'Z' in ASCII
    else if (d >= 65 && d <= 90) {
        result = (ll)(d - 55);
    }
    //If d is from 'a' to 'z' in ASCII
    else if (d >= 97 && d <= 122) {
        result = (ll)(d - 87);
    }
    //If d is the '-' character
    else if (d == 45) {
        return 45;
    }
    //If d is not from any range listed above
    else result = LLONG_MAX;
    
    //If the value of d is larger than or equal to the original base, then the input is invalid.
    if (result >= base) {
        cout << "Function 'convertBaseNDigitToDigit':" << endl;
        cout << "Error: Invalid input since " << d << " is out of the base " << base << " set." << endl;
        return -1;
    }
    else {
        return result;
    }
}

ll convertValueToDecimal(string n, int base) {
    ll dec = 0;
    int power = 0;
    
    //Loop from the last digit to the first digit
    for (long long i(n.length() - 1); i >= 0; --i) {
        //Get the value of the current digit in decimal
        ll curr_digit_dec = convertBaseNDigitToDigit(n[i], base);
        
        //If the first value is the '-' sign
        if (i == 0 && curr_digit_dec == 45) {
            return -dec;
        }
        
        //If the value of d is larger than or equal to the original base, then the input is invalid.
        if (curr_digit_dec == -1) {
            cout << "Function 'convertValueToDecimal' function:" << endl;
            cout << "Error: Cannot convert to decimal since the input is invalid." << endl;
            return -1;
        }
        
        //For each digit, we multiply it to the base to the power and add the total value to the dec variable.
        dec += (ll)(curr_digit_dec * pow(base, power));
        
        //Increase the power
        ++power;
    }
    
    return dec;
}

string convertDecimalToBaseN(ll dec, int base) {
    //Create the result string
    string result = "";
    //Create the remainder variable
    ll temp = sqrt(dec * dec);
    int remainder = base;
    
    //If temp is 0
    if (temp == 0) return "0";
    
    while (temp != 0) {
        //Calculate the remainder
        remainder = temp % base;
        
        //Add the remainder to the string
        result = to_string(remainder) + result;
        
        //Update the temp variable
        temp /= base;
    }
    
    if (dec < 0) {
        result = "-" + result;
    }
    
    return result;
}

string difference(string x, string y, int base) {
    Value a(x), b(y);
    ll diff;

    //Step 1: Calculate a.dec and b.dec base on a.str and b.str
    a.dec = convertValueToDecimal(a.str, base);
    b.dec = convertValueToDecimal(b.str, base);
    
    //Step 2: If a and b is invalid
    if (a.dec == -1 || b.dec == - 1) {
        return "NaN";
    }

    //Step 3: Calculate the diff
    diff = abs(a.dec - b.dec);
    
    return convertDecimalToBaseN(diff, base);
}

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