#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int min(int, int);
void swap(int*, int*);

inline int min02(int a, int b) {return (a < b)? a : b; }

void sort(int n, double x[])
{
    int i, j;
    double z;

    for(i = 0; i < n - 1; i++)
        for(j = n - 1; j > i; j--)
            if(x[j] < x[j - 1]) z = x[j], x[j] = x[j - 1], x[j - 1] = z;

}

void func001()
{
    double x[] = {1.2, -8, 3.4, 7, 8, 0, 8.1, 10};
    int n = sizeof(x) / sizeof(double);
    sort(n, x);
    for(int i = 0; i < n; i++) cout << x[i] << endl;
}

void (*func0015)();
double (*fd)(int, double);

decltype(sort) *f001;

void func002() 
{
    //указатель на функцию
    func0015 = func001;

}

int strlenv2(const char *s)
{
    int i;
    for(i = 0; *s++; i++);
    return i;
}

void strfill(char *s, int n, char ch = ' ') //третий параметр символд заполнитель
{
    for(int i = 0; i < n; i++) *s++ = ch;
    *s = '\0';
}


char* strcpy(char *out, const char *in)
{
    char* p = out;
    while((*p++ = *in++));
    return out;
}

char* strcat(char *s1,  char *s2)
{
    char* p = s1 + strlen(s1);
    while(( *p++ = *s2++));
    return s1;
}

char* revers(char s[])
{
    int n = strlen(s);
    char ch, *p, *q;
    for (p = s, q = s + (n - 1); p < q; p++, q--) 
    {
        ch = *p;
        *p = *q;
        *q = ch;
    }
    return s;
}

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}



double f(double& x) {return cos(x) - x;}
bool crossing(double f1, double f2)
{
    return ((f1 > 0 && f2 < 0) || (f1 < 0 && f2 > 0)) ? true : false;
}

int func003()
{
    setlocale(LC_CTYPE, "");
    double a, b, c;
    cout << "Method half devide for solution transcedent equals \n";
    cin >> a >> b;

    if(a > b) c = a, a = b, b = c;

    do
    {
        c = (a + b) / 2.0;
        if(crossing(f(a), f(c))) b = c;
        else if (crossing(f(b), f(c))) a = c;
            else { cout << "Solution on interval (" << a << ',' << b << ") not exists \n"; return 1; }
    } while((b-a > 1e-8));
    cout << "x = " << (a + b) / 2.0 << endl;
    return 0;
}


#define _USE_MATH_DEFINES
void func004()
{
    double x, sum, sn, n, h = 0.1;
    for (x = 0.0; x < M_PI_2; x +=h)
    {
        n = 1.0;
        sum = sn = x;
        do
        {
            sn *= -x * x / (2.0 * n * (2.0*n + 1.0));
            sum += sn;
            n += 1.0;
        } while(fabs(sn) > 1e-8);
        cout << x << '\t' << sum << endl;
    }
}

inline double ff(double x) { return sin(x*x);}
void func005()
{
    setlocale(LC_CTYPE, "");
    const double a = 0.0, b = 1.0, e = 1e-8;
    double s, w, x, h, n = 10.0;
    cout << "Integral Frenel(1.0): ";
    s = 0.0;

    do
    {
        w = s; h = (b - a) / n;
        for(s = 0.0, x = a; x < b - h; x += 2.0*h)
            s += ff(x) + 4.0 * ff(x + h) + ff(x + 2.0*h);
        s *= h / 3.0;
        n *= 2.0;
    } while(fabs(s - w) > e);
    cout << s << endl;
}



unsigned int Factorial(unsigned int n)
{
    if (n > 1) return n * Factorial(n - 1);
    if (n == 1 || n == 0) return 1;
}

unsigned int Fibonacci(unsigned int n)
{
    if (n > 2) return Fibonacci(n - 1) + Fibonacci(n - 2);
    if (n == 2 || n == 1) return 1;
    if (n == 0) return 0;
}

void func006()
{
    setlocale(LC_CTYPE, "");
    int n;
    cout << "Factorial n = ";
    cin >> n;
    cout << Factorial(n) << endl;
    cout << "Number Fibonacci for n = ";
    cin >> n;
    cout << Fibonacci(n) << endl;
}

constexpr int NNN = 4;
double* minor(const double m[], int k, int n)
{
    double* q = new double[(n - 1) * (n - 1)];
    double* v = q;

    m += n;
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < n; ++j) if( j != k) *v++ = *m++; else ++m;
    return q;
}

double determinant(const double m[], int n)
{
    double d = 0.0;
    if (n == 2) d = m[0] * m[3] - m[1] * m[2];
    else 
    {
        for(int i = 0; i < n; ++i)
        {
            double r = determinant(minor(m, i, n), n - 1);
            d += m[i] * (i & 1 ? -r : r);
        }
    }
    return d;
}

void print(const double (*m)[NNN])
{
    for(int i = 0; i < NNN; ++i)
    {
        for (int j = 0; j < NNN; ++j) cout << m[i][j] << '\t';
        cout << endl;
    }
}


void func007()
{
    setlocale(LC_CTYPE, "");
    double M[NNN][NNN] = { {3, 2, -5, 6}, {-7, 2, 6, 3}, {0, 4, -1, 9}, {2, 3, 5, 0}};

    double *w = *M;
    cout << "Source matrix \n";
    print(M);

    double d = determinant(w, NNN);
    cout << "Determinant = " << d << endl;

}

int main()
{
    int f = min(5, 9);
    cout << f << endl;

    int k = 1, m = 2;
    swap(&k, &m);

    cout << "k = " << k << endl;
    cout << "m = " << m << endl;

    double b[] = {8, 4, 5, 9, 10};
    int n = sizeof(b) / sizeof(double);
    cout << "n = " << n << endl;

    f001 = sort;
    f001(n, b);
    
    for(int i = 0; i < n; i++) cout << b[i] << endl;
    cout << "end " << endl;
    //func001();
    //func002();
    //func003();
    //func004();
    //func005();
    //func006();
    func007();


    return 0;
}


int min(int a, int b)
{
    return (a < b)? a : b;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}