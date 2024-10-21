#include <iostream>
using namespace std;

int main()
{
    int i = 3;
    cout << (i << 2) << endl;
    cout << (i >> 1) << endl;
    cout << (i & 1) << endl;
    cout << (i | 4) << endl;
    cout << (~i) << endl;

    setlocale(LC_CTYPE, "");
    double a, b, c;
    char ch;
    cout << "Calculation /n Example a + b <Enter> \n";
    while(true) {
        cin >> a >> ch >> b;
        switch(ch) 
        {
            case '+': c = a + b; break;
            case '-': c = a - b; break;
            case '*': c = a * b; break;
            case '/': c = a / b; break;
            default:    cout << "Unacceptable operation" << ch << "Output" << endl;
                        return 1;
        }
        cout << c << endl;
    }
    return 0;
}