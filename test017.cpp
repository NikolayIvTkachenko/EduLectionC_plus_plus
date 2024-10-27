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

    sort(v.begin(), v.end());
    cout << "sort v on increase: ";
    show(v);

    sort(q.begin(), q.end(), greater<int>());
    cout << "sort q on decrease: ";
    show(q);
}



int main()
{
    //func001();
    func002();
}