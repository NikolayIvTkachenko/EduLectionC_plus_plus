#include <iostream>
using namespace std;

class demo 
{
private:
    int a;
public:
    demo(){};
    demo(int n) { a = n ;} 
    void set_a(int n) { a = n; }    
    int get_a() { return a; }
};

void func001()
{
    demo ar[3];
    int i;

    for (i = 0; i < 3; i++) ar[i].set_a(i);
    for (i = 0; i < 3; i++) cout << ar[i].get_a() << " ";

    cout << endl;
}

void func002()
{
    demo ar[3] = { 3, 2, 1};
    int i;

    for (i = 0; i < 3; i++) cout << ar[i].get_a() << " ";
    cout << endl;
}

class parent 
{
private:
    int x;
public:
    void setx(int n) { x = n; }
    void showx() { cout << x << endl; }
};

class child: public parent 
{
private:
    int y;
public:
    void sety(int n) { y = n; }
    void showy() { cout << y << endl; }
};


void func003()
{
    child ob;
    ob.setx(100);
    ob.sety(200);

    ob.showx();
    ob.showy();
}


int main()
{
    //func001();
    //func002();
    func003();
    return 0;
}