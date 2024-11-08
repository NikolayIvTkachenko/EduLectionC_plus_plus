#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <iterator>

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

void func004()
{
    int i, k;
    ofstream out("test05.dat", ios_base::binary);

    for(i = 0; i < 1000; i++) out.write((char *) &i, sizeof(int));
    out.close();

    ifstream in("test05.dat", ios_base::binary);

    while (in.read((char *) &k, sizeof(int)))
    {
        cout << k << endl;
        in.seekg(99 * sizeof(int), ios_base::cur);
    }
    in.close();
}

void func00500()
{
    ofstream file("numberic.dat", ios_base::binary);
    for(int i = 0; i < 100; i++) file.write((char *) &i, sizeof(i));
    file.close();
}

void func005()
{
    fstream in_out("numeric.dat", ios_base::in | ios_base::out | ios_base::binary);
    if(in_out.is_open())
    {
        int k = 0;
        for(unsigned int pos = 0; in_out.seekg(pos, ios_base::beg); pos += sizeof(int))
        {
            if (!in_out.read((char*)&k, sizeof(int))) break;
            k += 100;
            if (!in_out.seekp(pos, ios_base::beg)) break;
            in_out.write((char*) &k, sizeof(int));
        }
        in_out.close();
    }
}

void func006()
{
    setlocale(LC_CTYPE, "");
    ifstream in("test.txt");
    cout << in.rdbuf();
    //in.close();

    ofstream out ("copy.txt");
    out << in.rdbuf();
    //out.close();
}

void func007()
{
    char ch;
    ifstream in("t.txt");
    filebuf *buf = in.rdbuf();

    while ((ch = buf -> sbumpc()) != EOF) cout << ch;

}

void func008()
{
    int i;
    char buf[] = "text";
    ostreambuf_iterator<char> it(cout);
    for(i = 0; buf[i]; i++) *it = buf[i];
    *it = '\n';

    ostreambuf_iterator<char> iter(cout.rdbuf());

    for(i = 0; i < 10; i++) *iter = i + '0', *iter = ' ';
    *iter = '\n';

    ifstream file("test.txt");

    if(file.is_open())
    {
        setlocale(LC_CTYPE, "");
        istreambuf_iterator<char> end_it, input_it(file);
        while(input_it != end_it) *it = *input_it++;
    }

}


int main()
{
    //func001();
    //func002();
    //func003();
    //func004();
    //func00500();
    //func005();

    //func006();
    //func007();
    func008();
}