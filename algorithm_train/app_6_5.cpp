#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()\
{
    string s;
    cin >> s;

    int cnt[26] = {0};

    for (auto c : s)
        ++cnt[c - 'a'];

    string half, mid;

    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        half += string(cnt[i] / 2, c);
        if(cnt[i] % 2 && mid.empty())
            mid += c;
    }

    string half2 = half;
    reverse(half2.begin(), half2.end()); 
    
    string ans = half + mid + half2;

    cout << ans << endl;

}