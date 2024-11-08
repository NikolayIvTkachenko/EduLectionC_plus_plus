#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

struct Student
{
    char namePerson[20];
    int number;
};

void func001()
{

    Student st = {"Nikolay Tkachenko", 200004};
    cout << st.namePerson << endl;
    cout << st.number << endl;

    Student *p1; // = new Student{"", 4};
    p1 = &st; //При задании значения указателю структурной переменной требуется операция взятия адреса
    cout << p1->namePerson << endl;
    cout << p1->number << endl;

    Student* p2 = new Student;
    strcpy(p2->namePerson, "Petr");
    //p2->namePerson = "Petr";  -> not working 

    //p2->name = "Petr000000000000000"; 
    // error: incompatible types in assignment of 'const char [5]' to 'char [20]'
    // error: invalid array assignment
    p2->number=33;

    cout << p2->namePerson << endl;
    cout << p2->number << endl;

}

struct List
{
    int dat;
    List* next;
};

void func002()
{
    int i;
    List *p, *heap = new List;
    for(p = heap, i = 0; i < 10; i++ )
    {
        p -> dat = i;
        p = p -> next = new List;
    }
    p->next = nullptr;
    for(p = heap; p->next != nullptr; p = p->next)
    {
        cout << p->dat << endl;
    }
}


union Flag
{
    long g;
    char ch[4];
};

void func003()
{
    Flag f1;
    f1.ch[0] = 1;
    f1.ch[1] = 2;
    f1.ch[2] = 4;
    f1.ch[3] = 8;

    cout << "Flag = " << hex << f1.g << endl;
    f1.g = 0; //All flags equals zero

    cout << "Flags is NULL\n";

    for(int i = 0; i < 4; i++)
    {
        cout << "Flag (" << i << "): " << (int)f1.ch[i] << endl;
    }
}


struct flagg
{
    unsigned int active : 1;
    unsigned int ready : 1;
    unsigned int error : 1;
};

struct numericCustom
{
    unsigned int m : 23; //Мантиса
    unsigned int p : 8; //Порядок
    unsigned int z : 1; //Знак числа
};

union Num
{
    numericCustom a;
    float x;
};

void func004()
{
    Num n;
    //n.x = 3.0f;
    n.x = 55.0f;

    cout << n.a.z << ' ' << n.a.p << ' ' << hex << n.a.m << endl;
}

struct DateTimeCustom
{
    unsigned int Year : 6;
    unsigned int Month : 4;
    unsigned int Day : 5;
    unsigned int Hour : 5;
    unsigned int Minute : 6;
    unsigned int Second : 6;
};

void func005()
{
    DateTimeCustom dt;
    tm timeinfo;
    time_t seconds = time(NULL);

    //localtime_s(&timeinfo, &seconds);
    //localtime(&timeinfo, &seconds);
    //dt.Day = timeinfo.tm_mday;
    //dt.Month = timeinfo.tm_mon + 1;
    //dt.Year = timeinfo.tm_year - 70;
    //dt.Hour = timeinfo.tm_hour;
    //dt.Minute = timeinfo.tm_min;
    //dt.Second = timeinfo.tm_sec;

    //cout << dt.Day << '.' << dt.Month << '.' << 1970 + dt.Year << '\t' << dt.Hour << ":" << dt.Minute << ":" << dt.Second << endl;
}

void func006(int n, char *arg[], char *env[])
{
    setlocale(LC_CTYPE, "");
    cout << "Environment Variable: \n";
    for(int i = 0; env[i]; i++) cout << env[i] << endl;

}

int main(int n, char *arg[], char *env[]) 
{
    setlocale(LC_CTYPE, "");
    cout << "Environment Variable: \n";
    for(int i = 0; env[i]; i++) cout << env[i] << endl;
}



// int main()
// {

//     //func001();
//     //func002();
//     //func003();
//     func004();


// }