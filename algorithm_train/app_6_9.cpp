#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> x(n);

    for(int i = 0; i < n; ++i)
        cin >> x[i];

    sort(x.begin(), x.end());

    for(int i = 0; i < n; ++i)
        cout << x[i] << ' ';
    
    cout << endl;

    int ans = x[n / 2 - 1];

    cout << ans << endl;
}