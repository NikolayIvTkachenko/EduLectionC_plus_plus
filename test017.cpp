#include <random>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto show = [] (vector<int>& vec) { 
    for (auto k : vec) cout << k << ' ';
    cout << endl;
};


void func001()
{
    random_device rd;
    mt19937 gen(rd());

    vector<int> v(10);

    for (int i = 0; i < 10; i++) v[i] = i;
    show(v);

    shuffle(v.begin(), v.end(), gen);
    show(v);
}

void func002()
{
    vector<int> v(10);
    for (int i = 0; i < v.size(); i++) v[i] = i;
    auto show = [] (vector<int>& vec) { 
        for (auto k : vec) cout << k << ' ';  
        cout << endl;
    };
    auto is_odd = [](int elem) {
        return (elem & 1) > 0;
    };
    show(v);

    vector<int> q(v);
    partition(v.begin(), v.end(), is_odd);

    cout << "partition:  ";
    show(v);

    stable_partition(q.begin(), q.end(), is_odd);
    cout << "stable_partition: ";
    show(q);

    partial_sort(q.begin(), q.begin() + 5, q.end(), greater<int>());
    cout << "partial sort q on decrease ";
    show(q);

    sort(v.begin(), v.end());
    cout << "sort v on increase: ";
    show(v);

    sort(q.begin(), q.end(), greater<int>());
    cout << "sort q on decrease: ";
    show(q);

    vector<int> w(8, 1);
    partial_sort_copy(v.begin(), v.end(), w.begin(), w.begin() + 5, greater<int>());
    cout << "partial sort v on decrease: ";
    show(w);

    nth_element(w.begin(), find(w.begin(), w.end(), 6), w.end());
    cout << "nth_element = 6: ";
    show(w);


}

void func003()
{
    vector<int> v(10,2), v1(v);
    partial_sum(v.begin(), v.end(), v.begin());

    for(int e : v) cout << e << ' ';
    cout << endl;

    partial_sum(v1.begin(), v1.end(), v1.begin(), [](int e1, int e2) { return e1*e2; });

    for( int e : v1) cout << e << ' ';
    cout << endl;

}

int main()
{
    //func001();
    //func002();
    func003();


}