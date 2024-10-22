#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>


void func001()
{
    setlocale(LC_CTYPE, "");
    char dmp[16];
    std::ifstream in("text02.txt", std::ios_base::binary);

    if(in.is_open())
    {
        int i, k;
        std::cout << std::setfill('0') << std::hex;

        while(!in.eof())
        {
            for(i = 0; i < 16; i++)
            {
                if((k = in.get()) == -1) break;
                dmp[i] = (k < ' ') ? ' ' : char(k);
                std::cout << std::setw(2) << k << ' ';
            }

            for (k = i; k < 16; ++k) std::cout << "  ";
            std::cout << " | ";
            std::cout.write(dmp, i);
            std::cout << std::endl;
        }
        in.close();
    }
}

using namespace std;

struct Complex
{
    double x, y;
    Complex(double a = 0.0, double b = 0.0) : x(a), y(b) {}
    void show()
    {
        cout << "z = " << x << y << 'i' << endl;
    }
};

void func002()
{
    Complex z1(1.25, 3.5);
    Complex z2(-4.1, 8.2);

    ofstream out("Complex.dat", ios_base::binary);
    out.write((char*) &z1, sizeof(z1));
    out.write((char*) &z2, sizeof(z2));

    out.close();
    Complex z;

    ifstream in("Complex.dat", ios_base::binary);
    cout.setf(ios_base::showpos);
    while(in.read((char*) &z, sizeof(z))) z.show();
    in.close();
}

void func003()
{
    string str;
    ofstream text("text03.txt");

    if( text.is_open())
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        cout << "Input Text: \n";

        while (getline(cin, str))
        {
            if(str.empty()) break;
            text.write(str.c_str(), str.length());
            text.put('\n');
        }
        text.close();
        cout << "Output string from file: \n";
        ifstream txt("text03.txt");

        while (getline(txt, str))
        {
            cout << str << endl;
        }
        txt.close();
    }
}

int main()
{
    //func001();
    //func002();
    func003();

}