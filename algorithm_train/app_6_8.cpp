#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i += 2)
        cout << a[i].second << ' ';

    for (int i = n - 1 - n % 2; i >= 1; i -= 2)
        cout << a[i].second << ' ';
    

}