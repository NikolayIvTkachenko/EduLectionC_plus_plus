
#include <iostream>
#include <String.h>
#include <windows.h>

using namespace std;

class String
{
    private:
        char *s;
        int n;
        static int strlen(const char *str)
        {
            int i = 0;
            while (*str++) i++;
            return i;
        }
    public:
        String(): s(nullptr), n(0) {}
        String(const char *str, int len = 0)
        {
            n = (len == 0)? strlen(str) : len;
            s = new char[n];
            for (int i = 0; i < n; i++) s[i] = str[i];
        }
        String(const String& T) : n(T.n), s(new char[T.n])
        {
            for (int i = 0; i < n; i++) s[i] = T.s[i];
        }
        ~String() { if(s) delete[] s;}

        String operator = (const String& st)
        {
           if(&st == this) return *this;
           if (s) delete[] s;
           n = st.n;
           s = new char[n];
           for (int i = 0; i < n; i++) s[i] = st.s[i];
           return *this; 
        }

        inline int length() { return n; }
        inline char at(int k) { return (k >= 0 && k < n)? s[k] : '\0'; }
        inline void setchar(char ch, int k)
        {
            if ( k >= 0 && k < n) s[k] = ch;
        } 

        String& erase(int start, int end)
        {
            int i, j, k = n + start - end -1;
            char *p = new char[k];
            for(i = 0; i < start; ++i) p[i] = s[i];
            for(j = ++end; j < n; ++i, ++j) p[i] = s[j];
            delete[] s;
            s = p;
            n = k;
            return *this;
        }

        String& insert(int k, const char *str)
        {
            int i, j, q, w;
            n += (w = strlen(str));
            char *p = new char[n];

            for (i = 0; i < k; ++i) p[i] = s[i];
            for (j = k, q = 0; q < w; ++j, ++q) p[j] = str[q];

            for(; j < n; ++i, ++j) p[j] = s[i];
            delete[] s;
            return *this;
        }

        inline String& append (const char *str) {return insert(n, str); }

        bool operator == (const String& s2)
        {
            if (n != s2.n) return false;
            for (int i = 0; i< n; ++i) 
                if (s[i] != s2.s[i]) return false;
            return true;
        }

        inline bool operator != (const String& s2)
        {
            return !(*this == s2);
        }

        bool operator < (const String& s2)
        {
            int k = (n < s2.n)? n : s2.n;
            for (int i = 0; i < k; ++i)
            {
                if (s[i] == s2.s[i]) continue;
                return (s[i] < s2.s[i])? true : false;
            }
            return (n < k)? true : false;
        }

        inline bool operator > (const String& s2)
        {
            return !(*this < s2 || *this == s2);
        }

        String& operator + (const String& str)
        {
            int i, j, k = n + str.n;
            char *p = new char[k];
            for ( i = 0; i < n; ++i) p[i] = s[i];
            for ( j = 0; i < k; ++i, ++j) p[i] = str.s[j];
            return *(new String(p, k));
        }

        operator char* ()
        {
            char *p = new char[n + 1];
            int i;
            for ( i = 0; i < n; ++i) p[i] = s[i];
            p[i] = '\0';
            return p;
        }

        //Запретить нейвное преобразование
        //explicit String(const char *str, int len = 0);

        friend std::ostream& operator << (std::ostream& out, const String& str)
        {
            out.write(str.s, str.n);
            return out;
        }

        friend std::istream& operator >> (std::istream& in, String& str)
        {
            char buf[256];
            in.getline(buf, 256);
            str = String(buf);
            return in;
        }

};

void func001()
{
    String str, t("String main"), text(t);

    char *p = String(" add");
    cout << t << endl;
    text.append(p);
    cout << text << endl;

    String s("1");
    str = text + s;
    cout << str << endl;

    for (int i = 0; i < text.length(); i++)
        if (text.at(i) == ' ') text.setchar(' ', i);
    cout << text << endl;
    text.erase(7, 11).insert(7,"12345");

    cout << text.append("789") << endl;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << String("Русский язык: ");
    cin >> str;
    cout << "Внешний текст: " << str << endl;    

}

class MyVector
{
    private:
        int* ptr = nullptr;
        int nn = 0;

    public:
        MyVector() = default;
        MyVector(const int* p, int k) : nn(k)
        {
            if (ptr != nullptr) delete[] ptr;
            ptr = new int[k];
            for (int i = 0; i < k; ++i) ptr[i] = p[i];
        }    
        MyVector(const MyVector& v) : MyVector(v.ptr, v.nn){}
        MyVector(std::initializer_list<int> iList)
        {
            nn = iList.size();
            if (ptr != nullptr) delete[] ptr;
            int *p = ptr = new int[nn];
            for (const int& e : iList) *p++ = e;
        }

        void show() 
        { 
            for (int i = 0; i < nn; ++i) 
                std::cout << ptr[i] << ' ';
            std::cout << std::endl;    
        }
};


void func002()
{
    int arr[] = { 6, 7, 8, 9 };
    MyVector v1;
    MyVector v2(arr, 4);
    MyVector v3(v2);
    MyVector v4{1, 2, 3, 4, 5};
    v1 = v3;
    v1.show();
    v4.show();
}


int main()
{
    func001();

}