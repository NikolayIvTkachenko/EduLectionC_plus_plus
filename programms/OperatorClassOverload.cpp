#include <iostream>

using namespace std;

class coord
{
private:
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }

    void get_xy() { cout << "X: " << x << " Y: " << y << endl; }
    coord operator+(coord ob2);
    coord operator-(coord ob2); 
};

coord coord::operator+(coord ob2)
{
    coord temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}

coord coord::operator-(coord ob2)
{
    coord temp;
    temp.x = x - ob2.x;
    temp.y = y - ob2.y;
    return temp;
}

int main()
{
    coord a(100, 200), b(50, 70), c, d;

    c = a + b;
    d = a - b;

    c.get_xy();
    d.get_xy();

    return 0;
}