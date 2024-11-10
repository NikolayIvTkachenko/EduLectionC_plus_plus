#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void func001()
{
    string s;
    getline(cin, s);
    istringstream stream(s);

    vector<int> a;
    int x;
    
    while (stream >> x)
        a.push_back(x);
    int n = (int) a.size();
    vector<int> cnt(n);
    bool ok = true;

    for (auto x : a)
    {
        if(x > n || cnt[x - 1])
            ok = false;
        else
            ++cnt[x - 1];
    }
    cout << (ok ? "OK" : "BAD") <<  endl;
}

void func002()
{
    string s;
    getline(cin, s);
    istringstream stream(s);

    vector<int> perm;
    int x;

    while (stream >> x)
        perm.push_back(x - 1);

    int n = (int) perm.size();
    
    cout << "n = " << n << endl;
    cout << "perm = " << perm.size() << endl;

    int ans = 0;
    vector <char> visited(n);

    for (int start = 0; start < n; ++start)
    {
        if(visited[start]) 
            continue;
        ++ans;

        int current = start;
        do {
            visited[current] = true;
            current = perm[current];

        } while (current != start);
    }
    cout << ans << endl;
}

int main()
{
    //func001();

    func002();


}