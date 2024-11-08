#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
    private:
        int t = 0;
    public:
    Time(){}
    Time(int h, int m = 0, int s = 0) : t(s + m*60 + h*3600){}
    Time(Time& tm) : t(tm.t) {}

    inline int gethours() { return t / 3600; }
    inline int getminutes() { return (t % 3600) / 60; }
    inline int getsec() { return t % 60; }

    Time addsec(int s) { t += s; return *this; }
    Time addmin(int m) { t += m * 60; return *this; }
    Time addhours(int h) { t += h * 3600; return *this; }

    void show()
    {
        cout << setw(2) << gethours() << ":" << setw(2) << getminutes() << ":" << setw(2) << getsec() << endl;
    }

    Time operator + (Time& tm)
    {
        Time tmp;
        tmp.t = t + tm.t;
        return tmp;
    }

};

void func001()
{
        cout << "Classes" << endl;

    Time t, tf, tw(8);
    cout << setfill('0');
    tw.show();
    tw.addmin(90).show();
    Time k = tw;

    k.addsec(15).addmin(100).addhours(1).show();
    t.addhours(-4).show();

    tw = Time(1, 3, 10);
    tf = Time(5);

    (t = tw + tf).show();

}

class Test
{
    private:
        int k;
    public:
        Test(const int d = 0) : k(d) { cout << "k=" << k << " , Constructor is working with one parameter\n"; }
        Test(const Test& t) : k(t.k) { cout << "k=" << k << ", Constructor is working in copy\n"; }
        ~Test() { cout << "k=" << k << ", Destructor is working\n"; }

        Test& operator + (const Test& a)
        {
            cout << "Operator + is working \n";
            return *(new Test(k + a.k));
        }

        Test& operator = (const Test& a)
        {
            cout << "a=" << a.k << ", Operator = (equals) is working \n";
            k = a.k;
            return *this;
        }

        void show() { cout << k << endl;}

};

void func002()
{
    setlocale(LC_CTYPE, "");
    Test t, t1(1), t2(2);
    t = t1 + t2;
    t.show();
}


class Integer
{
    private:
        int k;
    public:
        Integer(int a = 0) : k(a){}
        Integer(const char *str) {k = atoi(str);}
        Integer(const Integer& a) : k(a.k) {}

        Integer operator + () {return *this;}
        Integer operator - () { k = -k; return *this; }
        Integer operator ++ () { ++k; return *this; }

        Integer operator ++ (int) {
            int tmp = k;
            ++k;
            return Integer(tmp);
        }   

        Integer operator -- (int) {
            int tmp = k;
            --k;
            return Integer(tmp);
        }

        Integer operator + (const Integer& a) { return Integer(k + a.k); }
        Integer operator - (const Integer& a) { return Integer(k - a.k); }
        Integer operator * (const Integer& a) { return Integer(k * a.k); }
        Integer operator / (const Integer& a) { return Integer(k / a.k); } 
        Integer operator % (const Integer& a) { return Integer(k % a.k); }

        friend ostream& operator << (ostream& out, Integer& a) { out << a.k; return out; }
        friend istream& operator >> (istream& in, Integer& a) { in >> a.k; return in; }

};

void func003()
{
    Integer a, b, c("3"), d(2);
    a = 1;
    b = "2";

    //cout << ++a << ' ' << b << ' ' << c << ' ' << d << endl;
    //cout << a++ << ' ' << --b << ' ' << endl;
    d = b + c;

    //cout << a << ' ' << d << ' ' << a*d << endl;
    cin >> a >> b;
    cout << a << '\t' << b << endl;
}


int main()
{
    //func001();
    //func002();
    func003();
}