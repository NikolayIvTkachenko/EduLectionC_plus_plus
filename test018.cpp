#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <map>
//#include <multimap>
#include <windows.h>
#include <unordered_set>

using namespace std;

template <class T> void show(T& c) { 
    for (auto e : c) cout << e << ' '; 
    cout << endl;
};


void func001()
{
    setlocale(LC_CTYPE, "");
    set<int> c, c1 { 1, 5, 4, 2, 8, 3, 7, 6, 9};
    cout << "Size: c1: " << c1.size() << endl;
    cout << "Max size set for int number: " << c1.max_size() << endl;

    cout << "Set is empty?: " << boolalpha << c.empty() << endl;
    c = c1;
    cout << "set c: ";
    show(c);

    (c == c1)? cout << "c == c1\n" : cout << "c != c1\n";
    auto it = c.find(4);

    cout << "Position number 4: " << distance(c.begin(), it) << endl;
    cout << "Next number from 4? " << *(++it) << endl;

    c.insert(10);
    c.emplace(-1);
    c.erase(1);

    cout << "set c: ";
    show(c);

    set<int, greater<int>> s(c.cbegin(), c.cend());
    s.insert({ 11, 12, 13 });

    show(s);

}

void func002()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    map<string, string> spr;

    string name, number;
    cout << "Input name and number: \n";

    while(true)
    {
        getline(cin, name);
        if(name.empty()) break;
        getline(cin, number);
        spr[name] = number;
    }

    spr.insert({ "Ivanov I.I. ", "22-222-22"});
    spr.insert({ "Petrov P.P. ", "33-333-33"});

    for (auto e : spr) cout << e.first << '\t' << e.second << endl;


}


void func003()
{
    unordered_set<string> us({"bc", "de", "ax", "su", "ru" });
    for(auto e : us) cout << e << ' ';
    cout << endl;

    cout << "load_factor: " << us.load_factor() << endl;
    int n = us.bucket_count();

    for (int i = 0; i < n; ++i)
    {
        int k = us.bucket_size(i);
        cout << "bucket " << i << ":" << k << endl;

        if(k == 0) continue;
        auto beg = us.cbegin(i);
        auto end = us.cend(i);

        while(beg != end) cout << *beg++ << ' ';
        cout << endl;
    }

    for_each(us.cbegin(), us.cend(), [](string s){
        cout << s << ' ';
    });
    cout << endl;
}

int main()
{
    //func001();
    //func002();
    func003();
}