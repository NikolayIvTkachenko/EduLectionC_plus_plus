#include <iostream>
using namespace std;

int main()
{
    int i, j = 6, k(-1);

    char h = '0', ch;
    double pi = 3.14159;
    i = j + k;

    cout <<"\nj+k=" << i << endl;
    ch = h +1;
    cout << h << '\t' << ch << endl;

    cout << "\npi= " << pi << endl;

    int gg = 56;
    int jj = 5;
    cout << gg % jj << endl;
    
    int q1 = 0, q2 = 0, q3 = 0;

    q2 = ++q1;
    q3 = q1--;

    q1 = q2+++q3;

    cout << q1 << endl;
    cout << q1 << endl;
    cout << q2 << endl;


}