#ifndef sum_hpp
#define sum_hpp

#include <iostream>
#include <stack>

using namespace std;

stack<long> sumofBase(long x, long y, int base);
void printStack(const stack<long>& s);
bool checkValid(long x, long y, int base);

#endif