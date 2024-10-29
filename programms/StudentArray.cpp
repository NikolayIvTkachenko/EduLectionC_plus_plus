#include <iostream>
using namesoace std;

struct student
{
    char name[50];
    int roll;
    float mark;
} s[5];

void func001()
{
    cout << "Input information about student: " << endl;

    for(int i = 0; i < 5; ++i)
    {
        s[i].roll = i + 1;
        cout << "Course: ";
        cin >> s[i].roll;

        cout << "Name: ";
        cin >> s[i].name;

        cout << "Mark: ";
        cin >> s[i].mark;

        cout << endl;
    }

    cout << "Show Informatio: " << endl;

    for(int i = 0; i < 5; ++i)
    {
        cout << "\nCourse: " << i +1 << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Mark: " << s[i].mark << endl;
    }

}


int main()
{
    func001();

    return 0;
}