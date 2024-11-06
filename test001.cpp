#include <iostream>
using namespace std;

namespace user 
{
    int k, r;
}


using namespace user;

int main()
{

    //setlocale(LC_CTYPE, "");
    setlocale(LC_ALL, "RU");
    int mm1;

    k = 10;
    int m = k /2;
    user::r = 50;
    

    int i;
    for (i = 0; i < 10; i++)
    {
        cout << i << endl;
    }

    // int ii = 0;
    // int kk(0);
    // int kkk{0};

    
    //cout << DAY::sunday << endl;
    cout << "Тест рекорорд" << endl;
    
    cin >> mm1;
    cout << mm1 << endl;
}

enum class DAY : short {sunday, monday, tuesday, wednesday, thursday, friday, saturday};