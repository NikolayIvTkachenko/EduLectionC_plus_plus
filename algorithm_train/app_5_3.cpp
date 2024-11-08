#include <iostream>
#include <vector>
#include <cstdint> 
#include <chrono>

using namespace std;

int main()
{
    int n;
    cin >> n;

    //vector<long unsigned int> f = {0, 1};
    vector<int64_t> f = {0, 1};

    while ((int)f.size() <= n)
    {
        f.push_back(f[f.size() - 1] + f[f.size() - 2]);
    }
    cout << f[n] << endl;
    cin >> n;
}