#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <iterator>
#include <vector>

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

}



int main()
{
    func001();
}

