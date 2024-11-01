#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int func001()
{
    ofstream fout("test00.txt");

    if(!fout)
    {
        cout << "Cannot open fial to record";
        return 1;
    }

    fout << "Hello, Hello!\n";
    fout << "Yet another line\n";

    fout.close();

    cout << "Ready!" << endl;

    return 0;
}

int func002()
{
    ifstream fin("test00.txt");

    fin.unsetf(ios::skipws);
    if (!fin) {
        cout << "Cannot open file for read!";
        return 1;
    }

    char ch;

    while(!fin.eof())
    {
        fin >> ch;
        cout << ch;
    }

    cout << endl;
    fin.close();

    return 0;
}


int func003()
{
    string s;
    ifstream file("test00.txt");

    while(getline(file, s))
    {
        cout << s << endl;
        s += "+";
        cout << s << endl;
    }
    file.close();

    return 0;
}


int main()
{
    //return func001();
    //return func002();
    return func003();

}