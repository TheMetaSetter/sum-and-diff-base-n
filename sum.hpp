#ifndef sum_hpp
#define sum_hpp

#include <iostream>
#include <stack>
#include <math.h>
#include <string>
#include <cctype>

using namespace std;

string upperCase(string s);

stack<long> sumofBase(long x, long y, int base);
stack<char> sumOfBase_36(string A, string B, int base);

int convertToDecimal(string A, int base);
int convertToNumb(char c);
char convertToChar(int n);

void printStack(const stack<long>& s);
void printStack(const stack<char>& s);

bool checkValid(long x, long y, int base);
bool checkValid_36(string A, string B, int base);

#endif