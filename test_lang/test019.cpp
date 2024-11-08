#include <iostream>
#include <iterator>
#include <vector>

using namespace std;



void func001()
{
    cin.unsetf(ios::skipws);
    vector<char> str(256);
    vector<char>::iterator q, it = str.begin();

    istream_iterator<char> in(cin);
    ostream_iterator<char> out(cout);

    while((*it++ = *in) !='\n') ++in;

    for (q = str.begin(); q < it; q++) *out++ = *q;



}

int main()
{
    func001();
}