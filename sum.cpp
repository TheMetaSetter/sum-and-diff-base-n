#include "sum.hpp"

//check if whether the input of x and y is valid following the base
bool checkValid(long x, long y, int base)
{
    int digit = 0;

    while(x != 0 && y != 0)
    {
        digit = x % 10;

        if(digit >= base)
        {
            return true;
        }
        
        digit = y % 10;

        if(digit >= base)
        {
            return true;
        }

        x/= 10;
        y/= 10; 
    }
    return false;
}

stack<long> sumofBase(long x, long y, int base)
{   
    stack<long> sumRes;

    int c1 = 0; 
    int c2 = 0;
    int res = 0; //result of the division with the base
    long sum = 0; //sum of two digits
    bool returnYet = false; //check whether the calculation has returned excess value

    //Loop through every digit of the two numbers to do calculation
    while(x != 0 || y != 0)
    {
        c1 = x % 10;
        c2 = y % 10;

        //Check if the remaining of the divisons has been taken to calculate
        if(returnYet)
        {
            sum = c1 + c2 + res;
            returnYet = false;
        }
        else
        {
            sum = c1 + c2;
        }

        //Compare the sum of the digits with the base
        if(sum < base)
        {
            sumRes.push(sum);
        }
        else
        {
            sumRes.push(sum % base);
            res = sum / base;
            returnYet = true;
        }

        x /= 10;
        y /= 10;
    }
    
    //if the remaining of the division has not been calculated pushed to the result
    if(returnYet)
    {
        if(x == 0 && y == 0 && res != 0)
        {
            sumRes.push(res);
        }
    }
    return sumRes;
}

void printStack(const stack<long>& s) {
    for (auto it = s; !it.empty(); it.pop()) {
        cout << it.top();  // Print the top element
    }
    cout << endl;
}