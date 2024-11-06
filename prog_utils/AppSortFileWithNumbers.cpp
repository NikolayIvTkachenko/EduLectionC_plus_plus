#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    fstream myfile("1.txt");
    vector<double> x(istream_iterator<double> (myfile), ());
    sort(x.begin(), x.end());

    for(const auto& elem: x) cout << elem << "\n";
}