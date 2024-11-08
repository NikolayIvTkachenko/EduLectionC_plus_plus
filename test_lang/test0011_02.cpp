#include <iostream>
#include <string>

using namespace std;

template <class T, int N> class Stack
{
private:
    T st[N];
    short top = -1;
public:
    class Range : public exception
    {
    private:
        string report;
    public:
        Range(const char* str) : report(str) { }
        virtual char const* what() const noexcept override
        {
            return report.c_str();
        }    
    };

    Stack() = default;

    void push(T& var)
    {
        if (top >= N - 1) throw Range ("Stack overflow");
        st[++top] = var;
    }

    T& pop()
    {
        if (top < 0) throw Range ("Stack empty");
        return st[top--];
    }
};


int func003()
{
    Stack<int, 100> si;
    int i;
    setlocale(LC_CTYPE, "");
    try
    {
        for (i = 0; i < 10; i++) si.push(i);
        for (i = 0; i < 11; i++) cout << si.pop() << '\t';
        cout << endl;
    }
    catch (Stack<int, 100>::Range& e)
    {
        cout << "Exception: " << e.what() << endl;
        return 1;
    }
    return 0;

}




void func001()
{
    setlocale(LC_CTYPE, "");
    int a = 5, b = 0, c;
    bool flag;

    do 
    {
        try{
            c = a / b;
            flag = false;
        }
        catch(...)
        {
            cout << "Devided by 0 \n Change denominator to 2";
            b = 2;
            flag = true;
        }
    } while(flag);
    cout << "Result devided: " << c << endl;

}


void func002()
{
    int b = 0;
    std::exception ex;
    bool flag = true;
    do
    {

        try{
            if(b == 0) throw ex;
        }
        catch(const exception& exp)
        {
            cout << exp.what() << endl;
            flag = false;
        }
    }while(flag);

}


int main()
{
    //func001();
    //func002();
    func003();


}