#include <iostream>
#include <cmath>
#include <cstring>

//#include <string.h>
//#include <cstring>
//#include <stdio.h>
using namespace std;

void func001() 
{

    int *b = new int { 4 };
    int* n = new int[5] {1, 5, 7, 9, 1};
    double *arr = new double[10] {1.0, 4.4, 5.1, .7, 2.9, 4.2, 3.7, 8};

    delete b;
    delete[] arr;

    int i(0), *q, *k = new int[10];
    while (i < 10) k[i++] = i;
    for(q = k, i =0; i < 10; i++) cout << *q++ << endl;
    delete[] k; //освобождение памяти

}


void func002() 
{
    int i,j;
    double** q = new double* [9]; //** - указатель на указатель
    for(i = 0; i < 9; i++) 
    {
        q[i] = new double[9];
        for(j = 0; j < 9; j++)
        {
            cout << (q[i][j] = (i+1)*(j+1)) << '\t';
            cout << endl;
        }
    }

    for(i = 0; i < 9; i++) delete[] q[i];
    delete[] q; 
}

void func003()
{
    int i, j;
    double(*q)[9] = new double[9][9];
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++) cout <<(q[i][j] = (i + 1)*(j + 1)) << '\t';
        cout << endl;
    }
    delete[] q;
}

void func004()
{
    static char buf[9*9*8];
    int i, j;
    double(*q)[9] = new (buf) double[9][9];
    for(i = 0; i < 0; i++)
    {
        for(j = 0; j < 9; j++) cout << (q[i][j] = (i + 1) * (j + 1)) << '\t';
        cout << endl;
    }
}


void func005()
{
    int A[3][3] = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };
    int B[3][3] = { {4, 4, 4}, {5, 5, 5}, {6, 6, 6} };
    int C[3][3];

    int i, j, k;
    setlocale(LC_CTYPE, "");
    cout << "Addition matrix\n";
    for (i = 0; i < 3; ++i)
        for(j = 0; j < 3; ++j) C[i][j] = A[i][j] + B[i][j];

    for(i = 0; i< 3; ++i)
    {
        for(int elem: C[i]) cout << elem << ' ';
        cout << endl;
    }

    cout << "Multiplication matrix \n";

    for(i = 0; i< 3; ++i)
        for(j = 0; j < 3; ++j)
        {
            C[i][j] = 0;
            for (k = 0; k < 3; ++k) C[i][j] += A[i][k] * B[k][j];
        }

    for(i = 0; i < 3; ++i)
    {
        for(int elem: C[i]) cout << elem << ' ';
        cout << endl;
    }    
}

int func006()
{
    constexpr int N = 3;
    setlocale(LC_CTYPE, "");
    double M[3][3] = { {5, 1, 4}, {7, 4, 7}, {1, 2, 3} };
    double q, z;

    int i, j, k;
    bool is_null = false;
    int count = 0;
    cout << "Source matrix \n";

    for(i = 0; i < N; ++i) 
    {
        for (j = 0; j < N; ++j) cout << M[i][j] << '\t';
        cout << endl;
    }

    for(i = 0; (i < N - 1) && (!is_null); ++i)
    {
        z = fabs(M[i][j]);
        for (j = i, k = i + 1; k < N; ++k)
            if((q = fabs(M[k][i])) > z) z = q, j = k;
        if(j != i)
        {
            ++count;
            for (k = i; k < N; ++k) z = M[i][k], M[i][k] = M[j][k], M[j][k] = z;
        }    

        for(j = i + 1; j < N; ++j)
        {
            q = M[i][i];
            if(fabs(q) < 1e-16)
            {
                is_null = true;
                break;
            }
            z = M[j][i] / q;
            for (k = i + 1; k < N; ++k) M[j][k] -= M[i][k] * z;
        }
    }

    k = N - 1;
    if((fabs(M[k][k]) < 1e-16) || is_null) z = 0.0;
    else 
    {
        for (i = 0, z = 1.0; i < N; ++i) z *= M[i][i];
        if (count & 1) z = -z;
    }

    cout << "Determinant: " << z << endl;
    return 0;
}

void func007()
{
    setlocale(LC_CTYPE, "");
    int i, j;
    char *p, str[256], *pt = nullptr;
    double arr[10];

    cout << "Input koefficient to string \n";
    cin.getline(str, 256);

    p = strtok(str, " \t,;"); //, &pt);

    i = 0;
    while(p)
    {
        arr[i++] = atof(p);
        p = strtok(NULL, " \t,;"); //, &pt);

    }
    for(j = 0; j < i; ++j) cout << arr[j] << '\t';

}

int func008()
{
    char str[] = "Remember me when you look at the moon!";
    char delim[] = " ";
    cout << "The tokens are:" << endl;
     // tokenize str in accordance with delim
    char *token = strtok(str,delim);
    // loop until strtok() returns NULL
    while (token)  {
        // print token
        cout << token << endl;
        // take subsequent tokens
        token = strtok(NULL,delim);
    }

  return 0;
}

int main() 
{
    //func001();
    //func002();
    //func003();
    //func004();
    //func005();
    //func006();
    func008();

}