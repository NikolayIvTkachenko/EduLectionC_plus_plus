#include <string.h>
#include <iostream>

using namespace std;

const string s_Name = "Name: ";
const string s_Num = "Number: ";
const string s_School = " Name of education institution: ";
const string s_Level_education = "Level: ducation (11 - shcool, 12 - college, ...:) ";
const string s_Title = "Position: ";

class StudentV2
{
protected:
    string school = "";
    unsigned short education = 0;

public:
    StudentV2() = default;
    StudentV2(const string& sch, const unsigned short educat = 0) : school(sch), education(educat) {}
    StudentV2(const Student& st) :school(st.school), education(st.education) {}

    void get()
    {
        cout << s_School; getline(cin, scholl);
        cout << s_Level_education;
        (cin >> education).ignore();
    }

    void put()
    {
        cout << S_School << school << endl;
        cout << s_Level_education << education << endl;
    }
};

class EmployeeV2
{
protected:
    string name = "";
    unsigned int number = 0;

public:
    EmployeeV2() = default;
    EmployeeV2(const string& nam, const unsigned int num = 0) : name(nam), number(num) { }
    EmployeeV2(const Employee& empl) :name(empl.name), number(num) {}

    void get()
    {
        cout << s_Name; getline(cin, name);
        cout << s_Num; (cin >> number).ignore();
    }
    void put()
    {
        cout << s_Name << name << endl;
        cout << s_Num << number << endl;
    }
};

class ManagerV2
{
private:
    StudentV2 st {"", 0};
    EmployeeV2 empl{"", 0};
    string title;
public:
    ManagerV2() = default;
    ManagerV2(const StudentV2& stud, const Employee& emp, const string& tit) : st(stud), empl(emp), title(tit) {} 

    void get()
    {
        st.get();
        empl.get();
        cout << s_Title; getline(cin, title);
    }   
    void put()
    {
        st.put();
        emp.put();
        cout << s_Title << title << endl;
    }  
};

#include "Student.h"
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Manager manager;
    manager.get();
    manager.put();
}