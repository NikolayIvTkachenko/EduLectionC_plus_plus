#include <iostream>
#include <fstream>

using namespace std;

class coord
{
public:
    int x, y;
    coord(int i, int j) {x = i; y = j; }
    friend ostream &operator<< (ostream &stream, coord ob);
    friend istream &operator>> (istream &stream, coord &ob);
};

ostream &operator<< (ostream &stream, coord ob)
{
    stream << ob.x << " " << ob.y << '\n';
    return stream;
}

istream &operator>> (istream &stream, coord &ob)
{
    stream >> ob.x >> ob.y;
    return stream;
}


int func001()
{
    coord o1(100, 200), o2(300, 400);
    ofstream out("coords.txt");

    if(!out)
    {
        cout << "Error";
        return 1;
    }

    out << o1 << o2;
    out.close();

    ifstream in("coords.txt");
    coord o3(0, 0), o4(0, 0);

    in >> o3 >> o4;
    cout << o3 << o4;
    cout << endl;
    in.close();

    return 0;
}

int main()
{
    return func001();
}