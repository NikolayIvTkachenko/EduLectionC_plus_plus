#include <iostream>
using namespace std;

struct student
{
    char name[50];
    int roll;
    float mark;
};

struct Distance
{
    int f;
    float meters;
} d1, d2, sum;

typedef struct complex
{
    float real;
    float imag;
} complexNumber;

complexNumber add(complex, complex);

void func003()
{
    complexNumber n1, n2, temporaryNumber;
    char signOfImag;

    cout << "First complex number " << endl;
    cout << " Input real and unreal part: " << endl;
    cin >> n1.real >> n1.imag;

    cout << endl << "Second unreal number " << endl;
    cout << " Input real and unreal part: " << endl;
    cin >> n2.real >> n2.imag;

    signOfImag = (temporaryNumber.imag > 0) ? '+' : '-';
    temporaryNumber.imag = (temporaryNumber.imag > 0) ? temporaryNumber.imag : - temporaryNumber.imag;

    temporaryNumber = add (n1, n2);
    cout << "Summa = " << temporaryNumber.real <<  temporaryNumber.imag << "i";
    cout << endl;

}

void func001()
{
    student s;
    cout << "Info about student" << endl;
    cout << "Name: ";
    cin >> s.name;
    cout << "Course: ";
    cin >> s.roll;
    cout << "Mark: ";
    cin >> s.mark;

    cout << "\n Show info, " << endl;
    cout << "Name: " << s.name << endl;
    cout << "Course: " << s.roll << endl;
    cout << "Mark: " << s.mark << endl;
}

void func002()
{
    cout << "First structure" << endl;
    cout << "Countity steps: ";
    cin >> d1.f;
    cout << "Countinty meters: ";
    cin >> d1.meters;

    cout << "\nSecond structure" << endl;
    cout << "Countity steps: ";
    cin >> d2.f;
    cout << "Quantity meters: ";
    cin >> d2.meters;

    sum.f = d1.f + d2.f;
    sum.meters = d1.meters + d2.meters;

    cout << endl << "Sum = " << sum.f << " steps ";
    cout << sum.meters << " meters " << endl;

}

int main()
{
    //func001();
    //func002();
    func003();

    return 0;
}

complexNumber add(complex n1, complex n2)
{
    complex temp;
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return (temp);
}