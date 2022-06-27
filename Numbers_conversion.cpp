#include <iostream>
using namespace std;
 
// Decimal to binary conversion using recursion
int d2b(int d){
    if (d == 0)
        return 0;
    else
        return (d % 2 + 10 *
                d2b(d / 2));
}

// Binary to decimal conversion using recursion
int b2d(string b, int i=0){
    int n = b.length();
    if (i == n-1)
      return b[i] - '0';
     
    return ((b[i] - '0') << (n-i-1))  +
            b2d(b, i+1);
}
 
int main()
{
    cout <<"Number Conversion.\nEnter b for Binary, d for Decimal, o for Octal, r for Roman and h for Hexadecimal values." << endl;
    string inp,out;
    cout <<"Enter your choice for input number: ";
    cin >>inp;
    cout <<"Enter your choice for output number: ";
    cin >>out;
    if(inp=="d" && out=="b"){
        int d;
        cout << "Enter a decimal number: ";
        cin >> d;
        cout << "The binary value of " << d << " is " << d2b(d);
    }

    else if(inp=="b" && out=="d"){
        int b;
        cout << "Enter a binary number: ";
        cin >> b;
        cout << "The decimal value of " << b << " is " << b2d(to_string(b));
    }
    
    return 0;
}