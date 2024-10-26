#include <algorithm>
#include <iostream>
#include <array>
#include <vector>

using namespace std;


void func001()
{
    setlocale(LC_CTYPE, "");
    array<int, 10> arr{ 4, 2, 1, 6, 8, 2, 6, 2, 9, 3};
    array<int, 10>::const_iterator beg = arr.cbegin();
    array<int, 10>::const_iterator end = arr.cend();
    array<int, 10>::const_iterator p = beg;

    while((p = find(p, end, 2)) != end)
    {
        cout << "Index of occurence number 2: " << p++ -beg << endl;

    }
}

// bool greater(int k) { return (k > 7); }

// void func002()
// {
//     setlocale(LC_CTYPE, "");
//     vector<int> v = { 4, 7, 1, 6, 8, 2, 4, 9, 3};
//     vector<int>::const_iterator it = find_if(v.cbegin(), v.cend(), ::greater);

//     cout << "Position 1-st number > 7: " << it - v.cbegin() << endl;
// }

void func003()
{
    setlocale(LC_CTYPE, "");
    vector<int> v = { 4, 7, 1, 6, 8, 2, 6, 4, 9, 3 };
    auto it = find_if(v.cbegin(), v.cend(), bind2nd(greater<int>(), 7));
    cout << "Position 1-st number > 7" << it - v.cbegin() << endl; 
}



class FunctionObject
{
private:
    int val;
public:
    FunctionObject(int v): val(v) {}
    bool operator () (int k) 
    {
        return k > val;
    }
};


void func004()
{
    setlocale(LC_CTYPE, "");
    vector<int> v = { 4, 7, 1, 6, 8, 2, 6, 4, 9, 3 };
    FunctionObject op(7);

    auto it = find_if(v.cbegin(), v.cend(), op);
    cout << "Position element > 7: " << it - v.cbegin() << endl;
    op = 9;

    it = find_if(v.cbegin(), v.cend(), op);
    if (it == v.cend()) cout << "Element > 9 not found \n";
    else cout << "Position element > 9: " << it - v.cbegin() << endl;

}



void func005()
{
    setlocale(LC_CTYPE, "");
    vector<int> v = { 4, 7, 1, 6, 8, 2, 6, 4, 9, 3  };
    auto it = find_if(v.cbegin(), v.cend(), [](int e) {
        return e > 7;
    });

    cout << "Position element > 7: " << it - v.cbegin() << endl;
    it = find_if(v.cbegin(), v.cend(), [](int e){
        return e > 9;
    });

    if (it == v.cend()) cout << "Element > 9 not found \n";
    else cout << "Position element > 9: " << it - v.cbegin() << endl;

    cout << "===========" << endl;
    int border = 7;
    auto compare = [&border](int e) { 
        cout << e << endl;
        cout << border << endl;
        return e > border; 
    };
    auto itt = find_if(v.cbegin(), v.cend(), compare);
    cout << "---------" << endl;
}

void func006()
{
    vector<int> v = { 4, 7, 1, 6, 8, 2, 6, 4, 9, 3  };
    //Iterator min_element(Iterator beg, Iterator end)
    auto p = min_element(v.cbegin(), v.cend());
    cout << "min element = " << *p << endl;
    p = max_element(v.cbegin(), v.cend());
    cout << "max elements = " << *p << endl;
}

int main()
{
    //func001();
    //func002();
    //func003();
    //func004();
    //func005();
    func006();

}