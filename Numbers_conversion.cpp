#include <iostream>
#include <math.h>
#include<string.h>
using namespace std;
 
// Decimal to binary conversion using recursion
int d2b(int d){
    if (d == 0)
        return 0;
    else
        return (d % 2 + 10 * d2b(d / 2));
}

// Binary to decimal conversion using recursion
int b2d(string b, int i=0){
    int n = b.length();
    if (i == n-1)
      return b[i] - '0';
    
    return ((b[i] - '0') << (n-i-1))  + b2d(b, i+1);
}

// Decimal to octal conversion
int d2o(int d){
    int r, i = 1, o = 0;
    while (d != 0){
        r = d % 8;
        d /= 8;
        o += r * i;
        i *= 10;
    }
    return o;
}

// Octal to decimal conversion
int o2d(int o)
{
    int d = 0, i = 0, r;
    while (o != 0)
    {
        r = o % 10;
        o /= 10;
        d += r * pow(8, i);
        ++i;
    }
    return d;
}

// Decimal to hexadecimal conversion
void d2h(int d) {
    char arr[100];
    int i = 0;
    int d1 = d;
    while(d!=0) {
        int temp = 0;
        temp = d % 16;
        if(temp < 10) {
            arr[i] = temp + 48;
            i++;
        } 
        else {
            arr[i] = temp + 55;
            i++;
        }
        d = d/16;
    }
   cout << "The hexadecimal value of " << d1 << " is ";
   for(int j=i-1; j>=0; j--)
   cout << arr[j];
}

// Decimal to morse conversion
string morseEncode(char x){
	switch (x) {
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        case '0':
            return "-----";
        default:
            cerr << "Found invalid character: " << x << ' '<< endl;
            exit(0);
	}
}

void d2m(string s){
    cout << "The morse code of " << s << " is ";
	for (int i = 0; s[i]; i++)
		cout << morseEncode(s[i]);
	cout << endl;
}

// Hexadecimal to decimal conversion
int h2d(string h)
{
	int l = h.size();
	int base = 1;
	int d = 0;
	for (int i = l - 1; i >= 0; i--) {
		if (h[i] >= '0' && h[i] <= '9') {
			d += (int(h[i]) - 48) * base;
			base = base * 16;
		}
		else if (h[i] >= 'A' && h[i] <= 'F') {
			d += (int(h[i]) - 55) * base;
			base = base * 16;
		}
	}
	return d;
}

// Roman to decimal conversion
int r2d(string r) {
    int n = int(r.length());
    if (0 == n) {
        return 0;
    }

    int d = 0;
    for (int i = 0; i < n; i++) {
        switch (r[i]) {
            case 'I':
                d += 1;
                break;
            case 'V':
                d += 5;
                break;
            case 'X':
                d += 10;
                break;
            case 'L':
                d += 50;
                break;
            case 'C':
                d += 100;
                break;
            case 'D':
                d += 500;
                break;
            case 'M':
                d += 1000;
                break;
        }
    }

    for (int i = 1; i < n; i++) {
        if ((r[i] == 'V' || r[i] == 'X') && r[i - 1] == 'I') {
            d -= 1 + 1;
        }

        if ((r[i] == 'L' || r[i] == 'C') && r[i - 1] == 'X') {
            d -= 10 + 10;
        }

        if ((r[i] == 'D' || r[i] == 'M') && r[i - 1] == 'C') {
            d -= 100 + 100;
        }
    }
    return d;
}

// Decimal to roman conversion
string d2r(int d) {
    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string r = "";
    int i;
    for ( i = 0; i < 13; ++i){
        while(d - values[i] >= 0){
            r += str_romans[i];
            d -= values[i];
        }
    }
    return r;
}

int main(){
    cout <<"Number Conversion.\nEnter b for Binary, d for Decimal, o for Octal, r for Roman, m for Morse and h for Hexadecimal values." << endl;
    string inp,out;
    cout <<"Enter your choice for input number: ";
    cin >>inp;
    cout <<"Enter your choice for output number: ";
    cin >>out;

    // Input => Decimal
    if(inp == "d"){
        if(out == "d"){
            cout<<"Invalid Conversion";
        }

        else if(out == "b"){
            int d;
            cout << "Enter a decimal number: ";
            cin >> d;
            cout << "The binary value of " << d << " is " << d2b(d);
        }

        else if(out == "o"){
            int d;
            cout << "Enter a decimal number: ";
            cin >> d;
            cout << "The octal value of " << d << " is " << d2o(d);
        }

        else if(out == "h"){
            int d;
            cout << "Enter a decimal number: ";
            cin >> d;
            d2h(d);
        }

        else if(out == "m"){
            int d;
            cout << "Enter a decimal number: ";
            cin >> d;
            d2m(to_string(d));
        }

        else if(out == "r"){
            int d;
            cout << "Enter a decimal number: ";
            cin >> d;
            cout << "The roman value of " << d << " is " << d2r(d);
        }

        else{
            cout<<"Invalid Input";
        }
    }

    // Input => Binary
    if(inp == "b"){
        if(out == "d"){
            int b;
            cout << "Enter a binary number: ";
            cin >> b;
            cout << "The decimal value of " << b << " is " << b2d(to_string(b));
        }

        else if(out == "b"){
            cout<<"Invalid Conversion";
        }

        else if(out == "o"){
            int b;
            cout << "Enter a binary number: ";
            cin >> b;
            int d = b2d(to_string(b));
            cout << "The octal value of " << b << " is " << d2o(d);
        }

        else if(out == "h"){
            int b;
            cout << "Enter a binary number: ";
            cin >> b;
            int d = b2d(to_string(b));
            d2h(d);
        }

        else if(out == "m"){
            int b;
            cout << "Enter a binary number: ";
            cin >> b;
            int d = b2d(to_string(b));
            d2m(to_string(d));
        }

        else if(out == "r"){
            int b;
            cout << "Enter a binary number: ";
            cin >> b;
            int d = b2d(to_string(b));
            cout << "The roman value of " << b << " is " << d2r(d);
        }

        else{
            cout<<"Invalid Input";
        }
    }

    // Input => Octal
    if(inp == "o"){
        if(out == "d"){
            int o;
            cout << "Enter a octal number: ";
            cin >> o;
            cout << "The decimal value of " << o << " is " << o2d(o);
        }

        else if(out == "b"){
            int o;
            cout << "Enter a octal number: ";
            cin >> o;
            int d = o2d(o);
            cout << "The binary value of " << o << " is " << d2b(d);
        }

        else if(out == "o"){
            cout<<"Invalid Conversion";
        }

        else if(out == "h"){
            int o;
            cout << "Enter a octal number: ";
            cin >> o;
            int d = o2d(o);
            d2h(d);
        }

        else if(out == "m"){
            int o;
            cout << "Enter a octal number: ";
            cin >> o;
            int d = o2d(o);
            d2m(to_string(d));
        }

        else if(out == "r"){
            int o;
            cout << "Enter a octal number: ";
            cin >> o;
            int d = o2d(o);
            cout << "The roman value of " << o << " is " << d2r(d);
        }

        else{
            cout<<"Invalid Input";
        }
    }

    // Input => Hexadecimal
    if(inp == "h"){
        if(out == "d"){
            string h;
            cout << "Enter a hexadecimal number: ";
            cin >> h;
            cout << "The decimal value of " << h << " is " << h2d(h);
        }

        else if(out == "b"){
            string h;
            cout << "Enter a hexadecimal number: ";
            cin >> h;
            int d = h2d(h);
            cout << "The binary value of " << h << " is " << d2b(d);
        }

        else if(out == "o"){
            string h;
            cout << "Enter a hexadecimal number: ";
            cin >> h;
            int d = h2d(h);
            cout << "The octal value of " << h << " is " << d2o(d);
        }

        else if(out == "h"){
            cout<<"Invalid Conversion";
        }

        else if(out == "m"){
            string h;
            cout << "Enter a hexadecimal number: ";
            cin >> h;
            int d = h2d(h);
            d2m(to_string(d));
        }

        else if(out == "r"){
            string h;
            cout << "Enter a hexadecimal number: ";
            cin >> h;
            int d = h2d(h);
            cout << "The roman value of " << d << " is " << d2r(d);
        }

        else{
            cout<<"Invalid Input";
        }
    }

    // Input => Roman
    if(inp == "r"){
        if(out == "d"){
            string r;
            cout << "Enter a roman number: ";
            cin >> r;
            cout << "The decimal value of " << r << " is " << r2d(r);
        }

        else if(out == "b"){
            string r;
            cout << "Enter a roman number: ";
            cin >> r;
            int d = r2d(r);
            cout << "The binary value of " << r << " is " << d2b(d);
        }

        else if(out == "o"){
            string r;
            cout << "Enter a roman number: ";
            cin >> r;
            int d = r2d(r);
            cout << "The octal value of " << r << " is " << d2o(d);
        }

        else if(out == "h"){
            string r;
            cout << "Enter a roman number: ";
            cin >> r;
            int d = r2d(r);
            d2h(d);
        }

        else if(out == "m"){
            string r;
            cout << "Enter a roman number: ";
            cin >> r;
            int d = r2d(r);
            d2m(to_string(d));
        }

        else if(out == "r"){
            cout << "Invalid Conversion";
        }

        else{
            cout<<"Invalid Input";
        }
    }

    // /Input => Morse
    else if(inp == "m"){
        cout<<"Not supported right now.";
    }
    
    return 0;
}