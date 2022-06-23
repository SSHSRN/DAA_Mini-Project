#include <iostream>
using namespace std;
 
// Decimal to binary conversion using recursion
int d2b(int d)
{
    if (d == 0)
        return 0;
    else
        return (d % 2 + 10 *
                d2b(d / 2));
}
 
int main()
{
    cout <<"Number Conversion.\nEnter b for Binary, d for Decimal, o for Octal, r for Roman and h for Hexadecimal values." << endl;
    string inp,out;
    cout <<"Enter your choice for input number";
    cin >>inp;
    cout <<"Enter your choice for output number";
    cin >>out;
    if(inp=="d" && out=="b"){
        int d;
        cout << "Enter a decimal number: ";
        cin >> d;
        cout << "The binary value of " << d << " is " << d2b(d);
    }
    
    return 0;
}