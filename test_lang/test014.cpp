#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <iterator>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

void func001()
{
    int m[] = { 1, 5, 3, 4, 0, 2, 1, 4, 8, 3};
    vector <int> v1;
    vector <int> v2(20);
    vector <int> v3(10, 1);
    vector <int> v4(v3);
    vector <int> v5(m, m + 10);
    vector <int> v6{1, 2, 3, 4, 5, 6, 7, 8};

    cout << "empty v1 = " << v1.empty() << endl;
    cout << "size v5 = " << v5.size() << endl;
    cout << "max_size v5 = " << v5.max_size() << endl;
    v5.reserve(200);

    cout << "New size v5 = " << v5.size() << endl;
    cout << "Capacity v5 = " << v5.capacity() << endl;
    for (int e: v6) cout << e << ' '; cout << endl;

    if (v3 == v4) cout << "v3 is equal v4\n";
    vector <int> w(begin(m), begin(m) + 3);
    if (w < v5) cout << "w < v5\n";

    v1 = w;
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << '\t';
    v2.assign(100, 0);

    cout << "\nsize v2 = " << v2.size() << endl;
    cout << "capacity v2 = " << v2.capacity() << endl;
    v6.swap(w);

    cout << "size v6 = " << v6.size() << endl;
    cout << "size w = " << w.size() << endl;

    vector<int>::iterator it;
    for (it = w.begin(); it < w.end(); ++it) cout << * it << '\t';
    cout << endl;
    for (auto e : w) cout << e << " ";
    cout << endl;

    //vector<Type>::pointer ptr;
    //vector<Type>::const_pinter c_ptr;

    vector<int>::pointer ptr = w.data();
    for (int i = 0; i < w.size(); ++i, ++ptr) cout << *ptr << ' ';
    cout << endl;

}

void func002()
{
    vector <int> v;
    for (int i = 0; i < 10; i++) v.push_back(i);

    while (!v.empty()) 
    {
        cout << v.back() << ' ';
        v.pop_back();
    }

    cout << endl;
    vector <int> q(5, 2);
    q.emplace(q.begin(), -1);
    q.emplace_back(-2);
    q.insert(q.begin() + 6, 5, 1);

    for(auto e : q) cout << e << ' ';
    cout << endl;

    q.erase(q.begin() + 6, q.begin() + 11);

    for (auto e : q) cout << e << ' '; 
    cout << endl;

    q.resize(5);

    cout << "size q = " << q.size() << endl;

    for (auto e : q) cout << e << ' ';
    q.clear();


}

void func003()
{
    array<int, 10> ar = { 1, 2, 3, 4, 5};
    for (auto k : ar) cout << k << ' ';
}

void func004()
{
    deque<int> d1;
    deque<int> d2(10);
    deque<int> d3(10, 1);
    deque<int> d4(d3);
    deque<int> d5 = {1, 2, 3, 4, 5};

    setlocale(LC_CTYPE, "");
    cout << "Size d4 = " << d4.size() << endl;
    cout << "Max size deque<int> = " << d4.max_size() << endl;

    if(d1.empty()) cout << " d1 empty\n" ;
    if (d3 == d4) cout << "d3 == d4\n";
    else cout << "d3 != d4\n";

    int arr[5] = { -1, 3, 5, 8, 2};

    deque<int> d6(arr, arr + 5);

    d1.assign(d6.cbegin(), d6.cend());
    d1.insert(d1.end(), d5.cbegin(), d5.cend());

    cout << "Content deque d2: ";
    for(auto e1 : d1) cout << e1 << ' ';
    cout << endl;

    for (unsigned int i = 0; i < d2.size(); i++) d2[i] = i + 1;
    cout << "Content deque d2: ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    deque<int> deq(d6.cbegin(), d6.cend());

    deque<int>::const_iterator it;
    cout << "Contain deq: ";

    for (it = deq.cbegin(); it != deq.cend(); it++) cout << *it << ' ';
    cout << endl;


}

void func005()
{
    list<int> numbers{ 1, 2, 3, 4, 5 };

    list<int> lst;
    list<int> lstt(10);
    list<int> lsttt(10, 2);
    list<int> lstttt(lst2);
    list<int> lsttttt{ -1, 3, 5, 8, 2 };
    
    cout << "Size lst = 3 " << lstttt.size() << endl;
    cout << "Max Size lst3 = " << lstttt.max_size() << endl;

    if(lst.empty()) cout << "lst is empty\n";
    if(lst3 == lst2) cout << "lst == lst2\n";
    else cout << "lst3 != lst2\n";

    lst = lsttttt;
    lst.sort();

    lst.splice(lst.end(), lsttttt);
    cout << "lst.sort+splice: ";

    for(auto e : lst) cout << e << ' ';
    cout << endl;
    
    lst.unique();
    cout << "lst.unique: ";
    for(auto e : lst) cout << e << ' ';
    cout << endl;
    
    lsttt.unique();
    cout << "lst2.unique: ";
    for(auto e : lsttt) cout << e << ' ';
    cout << endl;

    lst.reverse();
    for(auto e : lst) cout << e << ' ';
    cout << endl;


}


int main()
{
    //func001();
    //func002();
    //func003();
    func005();


}

