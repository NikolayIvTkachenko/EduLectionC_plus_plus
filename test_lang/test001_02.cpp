#include <iostream>

using namespace std;

class Base
{
public:
    void show()
    {
        cout << "Base::show() \n" ; 
    }
};

class Dev001 : protected Base
{
public:
    using Base::show;
};


class Base02
{
public:
    // virtual void show()
    // {
    //     cout << "Base::show() \n" ; 
    // }
    ~Base02()
    {
        cout << "Destructor Base\n";
    }
    void show()
    {
        cout << "Base::show() \n" ; 
    }
};

class Dev102 : public  Base02
{
public:
    ~Dev102()
    {
        cout << "Destructor Dev102 \n";
    }
    void show()
    {
        cout << "Dev102::show() \n" ; 
    }
};

class Dev202 : public Base02
{
public:

    ~Dev202()
    {
        cout << "Destructor Dev202 \n";
    }

    void show()
    {
        cout << "Dev202::show() \n" ; 
    }
};

void func0001()
{
    Dev001 dv1;
    dv1.show();
}




void func0002()
{
    Dev102 dv1;
    Dev202 dv2;
    Base02 *p;

    p = &dv1;
    p->show();
    p = &dv2;
    p->show();

    delete p;

}

void func003()
{
    Dev102 *p;
    delete p;
}

int main()
{
    //func0001();
    //func0002();
    func003();
}