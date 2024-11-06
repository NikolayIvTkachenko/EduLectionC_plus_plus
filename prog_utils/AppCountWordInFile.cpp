#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        cerr << "Use: count_words <file_name>" << endl;
        returnEXIT_FAILURE;
    }
    ifstream infile(argv[1]);
    istream_iterator<string> in { infile }, end;
    cout << "Quantity words: " << distance(in, end) << endl;
}