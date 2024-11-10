#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int64_t> a(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int64_t ans1 = a[0] * a[1];
    int64_t ans2 = a[0] * a[n - 1];
    int64_t ans3 = a[n - 2] * a[n - 1];

    int64_t ans = min(ans, min(ans2, ans3));

    cout << ans << endl;

}
