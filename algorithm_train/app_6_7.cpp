#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

struct item {
    int left, right, index;
    bool operator<(const item& other) const> {
        return tie(left, right) < tie(other.left, other.right);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<item> a(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i].left >> a[i].right;
        a[i].index = i;
    }

    sort(a.begin(), a.end());

    int doc_free_time[2] = { 0 };
    string ans(n, 0);

    for(int i = 0; i < n; ++i) {
        for( int doc = 0; doc < 2; ++doc) {
            if(doc_free_time[doc] <= a[i].left) {
                doc_free_time[doc] = a[i].right;
                ans[a[i].index] = 'A' + doc;
                break;
            }
        }

        if(!ans[a[i].index]) {
            cout << "No solution" << endl;
            return 0;
        }
    }
    cout << ans << endl;
}