#include <iostream>
#include <iomanip>
#include <math.h>
#define _USR_MATH_DEFINES

#include <windows.h>
#include <sstream>
#include <fstream>

using namespace std;
const int width = 12;

void func001()
{
    cout << setw(6) << "x" << setw(width) << "sin(x)" << setw(width) << "cos(x)" << endl;
    cout.setf(ios_base::showpoint | ios_base::fixed);

    for (double x = 0.; x < M_PI_2; x += 0.1)
    {
        cout << setw(6) << setprecision(2) << x << setw(width) << setprecision(6) << sin(x) << setw(width) << setprecision(6) << cos(x) << endl;
    }
}

void func002()
{
    char buf[256];
    int k;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Input string 1: ";
    cin.get(buf, 256);
    k = cin.gcount();
    cout << "Size string = " << k << endl;
    k = cin.get();
    cout << "Last symbol of string: " << k << endl;
    cout << buf << endl;
    cout << "Input string 2: ";
    cin.getline(buf, 5);
    cin.ignore(10, '\n');
    cout << buf << endl;
}

void func003()
{
    double x[10];
    string in_buf;
    setlocale(LC_CTYPE, "");
    cout << "Input number bumbers to string: " << endl;
    getline(cin, in_buf);
    istringstream in(in_buf);
    int n = 0;

    while(in >> x[n]) ++n;
    ostringstream out;

    out << "inputed number : " << n << endl;

    for(int i = 0; i < n; ++i) out << x[i] << '\t';
    out << endl;
    cout << out.str();
}


int func004()
{
    setlocale(LC_CTYPE, "");
    ifstream in;
    ofstream out;
    string name, str;
    cout << "Name outputed file? ";

    cin >> name;
    in.open(name);

    if(in.is_open())
    {
        cout << "Name outputed file? ";
        cin >> name;
        out.open(name);
        if(out.is_open())
        {
            while(getline(in, str))
            {
                cout << str << endl;
                out << str << endl;
            }
            in.close();
        }
        else
        {
            cout << "Error with open outputed file: " << name << endl;
            return 1;
        }
        out.close();
    }
    else
    {
        cout  << "File not found \n";
        return 1;
    }


    return 0;
}

void func005()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;
    cout << "Inputed string: ";

    getline(cin, str);

    ofstream out("test02.txt", ios_base::app);
    if(out.is_open())
    {
        out << str << endl;
        out.close();
    }
}

int main() 
{
    //func001();
    //func002();
    //func003();
    //func004();
    func005();

}