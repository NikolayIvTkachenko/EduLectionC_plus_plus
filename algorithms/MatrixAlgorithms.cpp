#include <iostream>
#include <cmath>

using namespace std;

//arithmetic mean calculation
void func001_amc()
{
    int n, i;
    float num[100], sum = 0.0, average;

    cout << "Quantity element of array: ";
    cin >> n;

    while(n > 100 || n <= 0)
    {
        cout << "Quantity can be from 1 till 100" << endl;
        cout << "Input quantity again: ";
        cin >> n;
    }

    for(i = 0; i < n; ++i)
    {
        cout << i + 1 << " . Input element of array:  ";
        cin >> num[i];
        sum += num[i];
    }

    average = sum / n;
    cout << "Averafe = " << average << endl;

}

//Вычисляем наибольший элемент массива
void func002_max_element()
{
    int i, n;
    float arr[10];

    cout << "Input quantity elements (1-10): ";
    cin >> n;
    cout << endl;

    for(i = 0; i < n; ++i)
    {
        cout << "Input number " << i + 1 << " : ";
        cin >> arr[i];
    }

    for(i = 0; i < n; ++i)
    {
        if(arr[0] < arr[i]) arr[0] = arr[i];
    }

    cout << "Max: = " << arr[0] << endl;


}

float calculateSD(float data[]);
//Вычисляем среднеквадратичное отклонение
void func003_SD()
{
    int i;
    float data[10];

    cout << "Input ten elements:  ";
    for(i = 0; i < 10; ++i)
        cin >> data[i];

    cout << endl << "SD (CO) = " << calculateSD(data) << endl; 

}

float calculateSD(float data[])
{
    float sum = 0.0, mean, standardDeviation = 0.0;
    int i;
    for(i=0; i < 10; ++i)
    {
        sum += data[i];
    }
    mean = sum / 10;
    for (i = 0; i < 10; ++i)
    {
        standardDeviation += pow(data[i] - mean, 2);
    }
    return sqrt(standardDeviation / 10);
}


void func004_matrix_add()
{
    int r, c, a[100][100], b[100][100], summ[100][100], i, j;
    cout << "input quantity of string (1-100): ";
    cin >>r;
    cout << "Input quantity of column (1-100): ";
    cin >> c;

    cout << endl << "Input elements of first matrix: " << endl;

    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << "Input elements a " << i + 1 << j + 1 << " : ";
            cin >> a[i][j]; 
        }

    cout << endl << "Input elemets b " << i + 1 << j + 1 << " : ";

    for( i = 0; i < r; ++i)
        for( j = 0; j < c; ++j)
        {
            cout << "Input element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }    

    for( i =0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            summ[i][j] = a[i][j] + b[i][j];
        }

    cout << endl << "Sum of two matrix:  " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << summ[i][j] << " ";
            if(j == c - 1) cout << endl;
        }    
    cout << endl;    
}

//Умножение матриц
void func005_multiplication_matrix()
{
    int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

    cout << "Quantity rows and columns in the first matrix: ";
    cin >> r1 >> c1;

    cout << "Quantity rows and columns in the serconds matrix";
    cin >> r2 >> c2;

    while (c1 != r2)
    {
        cout << "Error! Quantity of columns of the first matrix no equal the quantity rows of the seconds matrix";

        cout << "Quantity rows and columns in the first matrix: ";
        cin >> r1 >> c1;

        cout << "Quantity rows and columns in the seconds matrix: ";
        cin >> r2 >> c2;

    }

    cout << endl << "Input elements of matrix 1: " << endl;
    for(i = 0; i < r1; ++i)
        for( j =0; j < c1; ++j)
        {
            cout << "Input element a" << i + 1 << j + 1 << " : ";
            cin >>a[i][j];
        }

    cout << endl << "Input elemeys of matrix 2: " << endl;

    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Input elemet b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }    

    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            mult[i][j] = 0;
        }

    for(i = 0;i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            } 

    cout << endl << "Result multiplay of matrix: " << endl;

    for( i = 0; i < r1; ++i)
        for( j = 0; j < c2; ++j)
        {
            cout << " " << mult[i][j];
            if(j == c2 - 1)
                cout << endl;
        }           
    cout << endl;
}

//Транспонированная матрица
void func006_trabsponir_Matrix()
{
    int a[10][10] , transpose[10][10], r, c, i, j;
    cout << "Input quantity rows and columns: ";
    cin >> r >> c;

    cout << "\nInput elemets of matrix: \n";
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << "a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }
    cout << "\nSource matrix: \n";
        


}


int main()
{
    //func001_amc();
    //func002_max_element();
    //func003_SD();
    //func004_matrix_add();
    //func005_multiplication_matrix();
    func006_trabsponir_Matrix();


    return 0;
}