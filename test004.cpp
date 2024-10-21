#include <iostream>
#include <cmath>
using namespace std;

void func001() {
    constexpr int N = 100;
    int i;
    double x,h, a(-1.0), b(1.0), y[N+1];

    h = (b - a) / N;
    for(i = 0, x = a; i <= N; i++, x += h)
    {
        y[i] = exp(-x*x);
        cout << x << '\t' << y[i] << endl;
    }

}

void func002() {
    int i, s, arr[] = {2, 4, 5, 7, 9, 12, 14};
    int n = end(arr) - begin(arr);
    cout << n << endl;
    for(i = s = 0; i < n; ++i) s += arr[i];
    cout << "sum: " << s << endl;
}

void func003() {
    int i;
    double min, max, m[] = {1.2, -3, 2.8, 8, 4.0 };
    cout << "Minimum & Maximum" << endl;
    for(i = 1, min = max = m[0]; i < sizeof(m) / sizeof(double); ++i)
    {
        if (m[i] > max) max = m[i];
        else if (m[i] < min) min = m[i];
    }
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
}


void func004() 
{
    //int *q, r = 1;
    //q = &r; //q - фдрес переменной r, где храниться число 1
    //int k = *q;

    //int a[5], *q = a; // a и q - указатели первого элемента массива a[0]

}

void func005()
{
    const char *t = "text";
    const char *q = t;

    cout << "Pointer *q" << endl;
    while (*q) cout << *q++;
    cout << "\nLength: " << q - t << endl;
}

void func006() {
    double q[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}};
    double *s = *q;

    for(int i = 0; i < 8; i++) cout << *s++ << '\t'; 
    cout << endl;

    cout << **q << endl; //q[0][0]

    cout << *(*q + 2) << endl; //q[0][2]
    cout << *(*q + 4) << endl; //q[1][0]

}


int main() 
{
    //func001();
    //func002();
    //func003();
    //func004();
    //func005();
    func006();

}