#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

void func001()
{
    int m[8] = { 4, 7, 1, 6, 8, 2, 6, 4 };
    vector<int> v(sizeof(m) / sizeof(int));
    copy(cbegin(m), cend(m), v.begin());
    for (int e : v) cout << e << ' '; 
}

void func002()
{
    vector<int> v = { 4, 7, 1, 6, 8, 2, 6, 4, 9, 3 };
    ostream_iterator<int> out_it(cout, " ");
    copy(v.begin(), v.end(), out_it);

    cout << endl;
    ofstream f("text01.txt");
    if (f.is_open())
    {
        ostream_iterator<int> it_out_file(f, "\t");
        copy(v.begin(), v.end(), it_out_file);
        f.close();
    }
}

void func003()
{
    istream_iterator<int> in_it(cin), end_of_stream;
    vector<int> v;
    copy(in_it, end_of_stream, back_inserter(v));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

}

// void func004()
// {
//     setlocale(LC_CTYPE, "");
//     ifstream infile("text01.txt");
//     if (infile.is_open())
//     {
//         istream_iterator<int> file_it(infile), end_of_stream;
//         vector<int> v;
//         copy(file_it, end_of_stream, back_inseter(v));
//         infile.close();
//         copy(v.cbegin(), v.cend, ostream_iterator<int>(cout, " "));
//         cout << endl;
//     } else {
//         cout << "File not found" << endl;
//     }
// }

class square {
public:
    int operator() (int k) {return k * k; }    
};

void func005()
{
    setlocale(LC_CTYPE, "");
    ifstream infile("text02.txt");
    if(infile.is_open())
    {
        istream_iterator<int> f_it(infile), end;
        vector<int> v;

        transform(f_it, end, back_inserter(v), square());
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    } else {
        cout << "fILE NOT FOUND";
    }
}


void func006()
{
    setlocale(LC_CTYPE, "");
    array<int, 5> a { 1, 3, 5, 7, 9};
    array<int, 5> b { 0, 2, 4, 6, 8};
    array<int, 5> c;

    int s = 0;

    transform(a.cbegin(), a.cend(), b.cbegin(), c.begin(), [&s](int i, int j){
        int k = i - j;
        s += (k *= k);
        return k;
    });

    for (auto e : c) cout << e << ' ';
    cout << "\nSum of squares of difference: " << s << endl;

    swap_ranges(a.begin(), a.end(), b.begin());

}

void func007()
{
    vector<int> v(10);
    fill(v.begin(), v.begin() + 5, 1);
    fill_n(v.begin() + 5, 5, 2);
    replace(v.begin(), v.end(), 1, 0);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    swap_ranges(v.begin(), v.begin() + 5, v.begin() + 5);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ""));
    cout << endl;

}

int main()
{
    //func001();
    //func002();
    //func003();
    //func004();
    //func005();
    //func006();
    func007();
    cout << "TEST TEST" << endl;
}