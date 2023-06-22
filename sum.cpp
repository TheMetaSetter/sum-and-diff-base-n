#include "sum.hpp"

string upperCase(string s)
{
    for(char& c : s)
    {
        c = toupper(c);
    }
    return s;
}

int convertToNumb(char c)
{
    return (int) c - 55;
}

char convertToChar(int n)
{
    return (char) (n+55);
}

int convertToDecimal(string A, int base)
{
    int expoNent = 0;
    char c;
    int res = 0;

    for(int i = A.length() - 1; i >= 0; i--)
    {
        c = A[i];
        //cout << convertToNumb(c) << " ";
        int temp = c - '0';
        if(0 <= temp && temp <= 9)
        {
            res += temp * pow(base,expoNent);
        }
        else
        {
            res += convertToNumb(c) * pow(base,expoNent);
        }
        
        expoNent++;
    }
    
    return res; 
}

stack<char> sumOfBase_36(string A, string B, int base)
{
    int x = convertToDecimal(A,base);
    int y = convertToDecimal(B,base);
    int remainings = 0;

    int total = x + y;

    stack<char> res;

    while(total != 0)
    {
        remainings = total % base;

        if( 0 <= remainings && remainings <= 9)
        {
            res.push(remainings +'0');
        }
        else 
        {
            res.push(convertToChar(remainings));
        }

        total /= base;
    }

    return res;
}

bool checkValid_36(string A, string B, int base)
{
    for(char& c : A)
    {
        if( c - '0' > 9)
        {
            if(convertToNumb(c) >= base)
            {
                return false;
            }
        }
    }

    for(char& c : B)
    {
        if( c - '0' > 9)
        {
            if(convertToNumb(c) >= base)
            {
                return false;
            }
        }
    }

    return true;
}

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

void printStack(const stack<char>& s){
    for (auto it = s; !it.empty(); it.pop()) {
        cout << it.top();  // Print the top element
    }
    cout << endl;
}

void printStack(const stack<long>& s) {
    for (auto it = s; !it.empty(); it.pop()) {
        cout << it.top();  // Print the top element
    }
    cout << endl;
}

// int main(){

//     stack<char> s;

//     s = sumOfBase_36("AB", "CB", 16);
    
//    printStack(s);
// }