#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int  n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> cnt(n + 1);

    for(auto x : a)
    {
        if(x <= n)
            ++cnt[x];
    } 

    vector<int> free;

    for (int i = 1; i <= n; ++i){
        if(!cnt[i])
            free.push_back(i);
    }

    cout << free.size() << endl;

    for(auto x : a) {
        if (x <= n)
            --cnt[x];

        if (x > n || cnt[x]) {
            x = free.back();
            free.pop_back();
        }
        cout << x << ' ';
    }
    cout << endl;
}