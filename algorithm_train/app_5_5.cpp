#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int i = max(n / k, 1);
    int ans1 = abs(n - k * i);
    ++i;
    int ans2 = abs(n - k * i);
    cout << min(ans1, ans2) << endl;
}