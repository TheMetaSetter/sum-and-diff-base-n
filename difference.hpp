#ifndef difference_hpp
#define difference_hpp

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll; //Define long long as ll

//Create 'Value' datatype containing the string of the input and its decimal value
struct Value {
    string str;
    ll dec;
    Value(string str) : str(str), dec(ll(NAN)) {}
    Value(string str, ll dec) : str(str), dec(dec) {}
};

ll convertBaseNDigitToDigit(char d, int base);
ll convertValueToDecimal(string n, int base);
string convertDecimalToBaseN(ll dec, int base);
string difference(string x, string y, int base);

#endif
