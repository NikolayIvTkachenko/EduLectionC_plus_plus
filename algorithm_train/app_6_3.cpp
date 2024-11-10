#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

int main()
{
    int64_t a, b;
    cin >> a >> b;
    a /= 10;
    b /= 10;

    cout << min({a, b, (a + b) / 3 }) << endl;
}