#include <iostream>
#include <string>

template <class T> //template <typename T>

void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

using namespace std;

template <class T> class StackV02
{
private : 
    T st[100];    
    short top;

public:
    StackV02() : top(-1) {}
    void push (const T& var) { st[++top] = var; } 
    T& pop() { return st[top--]; }   
};

template<typename T> auto sum(const T& value)
{
    return value;
}

template<typename T, typename...Args> auto sum(const T& value, const Args&... args)
{
    return value + sum(args...);
}


void func003()
{
    std::cout << sum(1, -2, 4) << std::endl;
    std::cout << sum(2.3, 2, 8.55) << std::endl;
    std::string s1("text "), s2("123");
    std::cout << sum(s1, s2) << std::endl;
    std::cout << sum(s1, "345") << std::endl;
}



void func002()
{
    StackV02<int> si;
    int i;
    for ( i = 0; i < 10; i++) si.push(i);
    for ( i = 0; i < 10; i++) cout << si.pop() << '\t';
    cout << endl;

    setlocale(LC_CTYPE, "");
    
    StackV02<string> str;
    string name[5] = { "Sergo", "Dmitry", "Anton", " Vladimir", "Helen"};
    for (i = 0; i < 5; i++) str.push(name[i]);
    for (i = 0; i < 5; i++) cout << str.pop() << '\t';
    
    cout << endl;

}




void func001()
{
    int i(1), j(2);
    ::swap(i, j);
    cout << i << '\t' << j << endl;

    double x(1.1),  y(2.2);
    ::swap(x, y);
    cout << x << '\t' << y << endl;

}

int main()
{
    //func001();
    //func002();
    func003();
}