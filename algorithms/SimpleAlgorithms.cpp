#include <iostream>

using namespace std;

void func001()
{
    int n, reversed = 0, remainder, original;

    cout << "Input whole number:  ";
    cin >> n;

    original = n;

    while (n != 0)
    {
        remainder = n%10;
        reversed = reversed*10 + remainder;
        n /= 10;
    }

    if(original == reversed)
        cout << original << " - palidrome\n";
    else 
        cout << original << " - not polydrom\n";
}

void func002_fibonaci()
{
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    cout << "Input quantity elements of subsequence ";
    cin >> n;
    cout << "Subsecuence fibonacci: ";
    for (int i = 1; i <= n; ++i)
    {
        if(i == 1)
        {
            cout << " " << t1;
            continue;
        }
        if(i == 2)
        {
            cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        cout << nextTerm << " ";
    }
    cout << endl;
}

void func003_fibonaci_v2()
{
    int t1 = 0, t2 = 1, nextTerm = 0, n;
    cout << "Input positive number: ";
    cin >> n;
    cout << "Sequences fibonacci: " << t1 << ", " << t2 << ", ";

    nextTerm = t1 + t2;

    while(nextTerm <= n)
    {
        cout << nextTerm << " ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    cout << endl;
}

//NOD = Наибольший общий делитель
void func004_nod() 
{
    int n1, n2, hcf;
    cout << "Input two number: ";
    cin >> n1 >> n2;

    if(n2 > n1)
    {
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }

    for(int i = 1; i <= n2; ++i)
    {
        if(n1 % i == 0 && n2 % i == 0)
        {
            hcf = i;
        }
    }

    cout << "NOD = " << hcf << endl;
}


int main()
{

    //func001();
    //func002_fibonaci();
    //func003_fibonaci_v2();
    func004_nod();

    return 0;
}