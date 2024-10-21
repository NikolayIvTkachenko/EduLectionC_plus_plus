#include <string.h>
#include <iostream>

using namespace std;

const string s_Name = "Name: ";
const string s_Num = "Number: ";
const string s_School = " Name of education institution: ";
const string s_Level_education = "Level: ducation (11 - shcool, 12 - college, ...:) ";
const string s_Title = "Position: ";

class Student
{
protected:
    string school;
    unsigned short education;

public:
    Student(const string sch = "", const unsigned short educat = 0) : school(sch), education(educat) {}

    void get()
    {
        cout << s_School; getline(cin, school);
        cout << s_Level_education;
        (cin >> education).ignore();
    }

    void put()
    {
        cout << s_School << school << endl;
        cout << s_Level_education << education << endl;
    }
};

class Employee : public Student
{
protected:
    string name;
    unsigned int number;

public:
    Employee(const string sch = "", const unsigned short educat = 0, const string nam = "", const unsigned int num = 0) : Student(sch, educat), name(nam), number(num) { }
    void get()
    {
        Student::get();
        cout << s_Name; getline(cin, name);
        cout << s_Num; (cin >> number).ignore();
    }
    void put()
    {
        Student::put();
        cout << s_Name << name << endl;
        cout << s_Num << number << endl;
    }
};

class Manager : public Employee
{
private:
    string title;
public:
    Manager(const string sch = "", const unsigned short educat = 0, const string nam = "", const unsigned int num = 0, const string tit = "") :
    Employee(sch, educat, nam, num), title(tit) {}

    void get()
    {
        Employee::get();
        cout << s_Title; getline(cin, title);
    }   
    void put()
    {
        Employee::put();
        cout << s_Title << title << endl;
    }  
};