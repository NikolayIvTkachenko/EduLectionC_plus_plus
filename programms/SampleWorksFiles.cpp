#include <iostream>
#include <fstream>

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


int main()
{

    func001();

    return func001();

}