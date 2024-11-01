#include <iostream>
using namespace std;

const int SIZE = 26;

class stack {
    char stck[SIZE];
    int tos;
    int stackId = 0;
public:
    stack();
    stack(int id);
    ~stack();
    void init();
    void push(char ch);
    char pop();    
};

stack::stack()
{
    cout << "Constructor stack\n";
    tos = 0;
}

stack::stack(int id)
{
    cout << "StackId = " << id << " Constructor stack\n";
    tos = 0;
    stackId = id;
}

stack::~stack()
{
    cout << "StackId = " << stackId << " Destructor is working...\n";
}

void stack::init()
{
    tos = 0;
}

void stack::push(char ch)
{
    if (tos == SIZE) {
        cout << "Stack us full!!" << endl;
        return;
    }
    stck[tos] = ch;
    tos++;
}

char stack::pop()
{
    if(tos == 0)
    {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    tos--;
    return stck[tos];
}


void func001()
{
    stack s1, s2;
    int i;

    s1.init();
    s2.init();

    s1.push('a');
    s2.push('b');
    s1.push('c');
    s2.push('d');
    s1.push('e');
    s2.push('f');

    for (i = 0; i < 3; i++) cout << s1.pop() << " ";
    cout << endl;

    for (i = 0; i < 3; i++) cout << s2.pop() << " ";
    cout << endl;
}

void func002()
{
    stack s1, s2;
    int i;

    s1.push('a');
    s2.push('b');
    s1.push('c');
    s2.push('d');
    s1.push('e');
    s2.push('f');

    for (i = 0; i < 3; i++) cout << s1.pop() << " ";
    cout << endl;

    for (i = 0; i < 3; i++) cout << s2.pop() << " ";
    cout << endl;
}

void func003()
{
    stack s1(1), s2(2);
    int i;

    s1.push('a');
    s2.push('b');
    s1.push('c');
    s2.push('d');
    s1.push('e');
    s2.push('f');

    for (i = 0; i < 3; i++) cout << s1.pop() << " ";
    cout << endl;

    for (i = 0; i < 3; i++) cout << s2.pop() << " ";
    cout << endl;
}

int main()
{
    //func001();
    //func002();
    func003();

}


