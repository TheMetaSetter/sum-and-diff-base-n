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

char convertDecimalToBaseNDigit(int dec, int base) {
    //If the decimal value is larger than the base, then we return the NULL value of char.
    if (dec >= base) {
        cout << "Function 'convertDigitToBaseNDigit': " << endl;
        cout << "Error: Cannot convert decimal value to base-n digit since the decimal value is larger than the target base." << endl;
        return 0;
    }
    else {
        if (dec >= 0 && dec <= 9) {
            return (char)(dec + 48);
        }
        //If the decimal value 
        else if (dec >= 10 && dec <= 35) {
            return (char)(dec + 55);
        }
        //If the decimal value is invalid
        else {
            cout << "Function 'convertDigitToBaseNDigit': " << endl;
            cout << "Error: Cannot convert decimal value to base-n digit since the decimal value is invalid - less than 0 or larger than 35." << endl;
            return 0;
        }
    }
}

ll convertValueToDecimal(string n, int base) {
    ll dec = 0;
    int power = 0;
    
    //Loop from the last digit to the first digit
    for (long long i(n.length() - 1); i >= 0; --i) {
        //Get the value of the current digit in decimal
        ll curr_digit_val = convertBaseNDigitToDigit(n[i], base);
        
        //If the first value is the '-' sign
        if (i == 0 && curr_digit_val == 45) {
            return -dec;
        }
        
        //If the value of d is larger than or equal to the original base, then the input is invalid.
        if (curr_digit_val == -1) {
            cout << "Function 'convertValueToDecimal':" << endl;
            cout << "Error: Cannot convert to decimal since the input is invalid." << endl;
            return -1;
        }
        
        //For each digit, we multiply it to the base to the power and add the total value to the dec variable.
        dec += (ll)(curr_digit_val * pow(base, power));
        
        //Increase the power
        ++power;
    }
    
    return dec;
}

string convertDecimalToBaseN(ll dec, int base) {
    //Create the result string
    string result = "";
    //Create the remainder variable
    ll temp = abs(dec);
    int remainder = base;
    
    //If temp is 0
    if (temp == 0) return "0";
    
    while (temp != 0) {
        //Calculate the remainder
        remainder = temp % base;
        
        //Convert the remainder to the appropriate base
        char remainder_char = convertDecimalToBaseNDigit(remainder, base);
        if (remainder_char == 0) {
            cout << "Function 'convertDecimalToBaseN':" << endl;
            cout << "Error: Cannot convert decimal value to base-n value since the decimal value is invalid." << endl;
            return 0;
        }

        //Add the remainder_char to the result string
        result = remainder_char + result;
        
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
    diff = a.dec - b.dec;
    
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