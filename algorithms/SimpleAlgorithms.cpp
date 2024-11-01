#include <iostream>
#include <cmath>

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

void func005_nod_v2()
{
    int n1, n2;
    cout << "Input two number: ";
    cin >> n1 >> n2;

    //Если введены отрицательные числа, меняем знак на положительный
    n1 = ( n1 > 0) ? n1 : -n1;
    n2 = ( n2 > 0) ? n2 : -n2;

    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }    
    cout << "NOD = " << n1 << endl; 
} 


//NOK - нименьшее общее кратное
void func006_nok()
{
    int n1, n2, LCM;
    cout << "Input two whole naumber: ";
    cin >> n1 >> n2;

    //Determinant maximum n1 and n2 and save in LCM
    LCM = ( n1 > n2 ) ? n1 : n2;

    while(1)
    {
        if( LCM % n1 == 0 && LCM % n2 == 0 )
        {
            cout << "NOK = " << LCM << "\n";
            break;
        } 
        ++LCM;
    }
    cout << endl;
}

//Опеределние НОК через НОД
void func007()
{
    int n1, n2, hcf, temp, lcm;

    cout << "Input two number: ";
    cin >> n1 >> n2;

    hcf = n1;
    temp = n2;

    while(hcf != temp)
    {
        if (hcf > temp)
            hcf -= temp;
        else 
            temp -= hcf;
    }

    lcm = (n1 * n2) / hcf;

    cout << "NOK = " << lcm;
}

//Определим количество цифр в числе
void func008()
{
    long long n;
    int count = 0;

    cout << "input whole number: ";
    cin >> n;

    while(n != 0)
    {
        n /= 10;
        ++count;
    }
    cout << "Number of digits: " << count << endl;
}

//Вычисляем обратное число
void func009()
{
    int n, reversedNumber = 0, remainder;

    cout << "Input whole number/integer: ";
    cin >> n;

    while(n != 0)
    {
        cout << "==========================" << endl;
        remainder = n % 10;
        cout << "remainder: " << remainder << endl;
        reversedNumber = reversedNumber*10 + remainder;
        cout << "reversedNumber: " << reversedNumber << endl;
        n /= 10;
        cout << "n: " << n << endl;
    }
    cout << "Reverse number = "<< reversedNumber << endl;
    
    int test; 
    test = 5 % 3;
    cout << "5 % 3 = " << test << endl;

}

//Вычисляем степень числа
void func010()
{
    int exponent;
    float base, result = 1;

    cout << "Input number and power of number: ";
    cin >> base >> exponent;
    cout << base << "^" << exponent << " = ";

    while (exponent != 0) {
        result *= base;
        --exponent;
    }

    cout << result << endl;
}

void func011_SimpleNumber()
{
    int n, i;
    bool isPrime = true;

    cout << "Input integer positive number: ";
    cin >> n;

    for(i = 2; i <= n / 2; ++i)
    {
        if( n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    if(isPrime)
    {
        cout << "This is simple number" << endl;
    }
    else
    {
        cout << "This is not simple number" << endl;
    }
}

void func012()
{
    int low, high, i, flag, temp;
    cout << "Input simple number between a and b, input a and b: ";

    cin >> low >> high;

    if (low > high)
    {
        temp = low;
        low = high;
        high = temp;
    }

    while (low < high)
    {
        flag = 0;
        for(i = 2; i <= low/2; ++i)
        {
            if(low % i == 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            cout << low << " ";
        ++low;
    }

    cout << endl;
}

//Проверка на число Армстронга - это число, которое в данной системе счисления равно сумме своих цифр, 
//возведенных в степень, равную количеству его цифр
//1634 = 1^4 + 6^4 + 3^4 + 4^4
//153 = 1^3+5^3+3^3
//только для трех значных чисел = 153
void func013()
{
    int origNum, num, digit, sum = 0;
    cout << "Input integer positive number: ";
    cin >> origNum;
    cout << endl;

    num = origNum;

    while(num != 0)
    {
        cout << "===========" << endl;
        digit = num % 10;
        cout << "digit = " << digit << endl;
        sum += digit * digit * digit;
        cout << "sum = " << sum << endl;;
        num /= 10;
        cout << "num = " << num << endl;
    }

    if(sum == origNum)
        cout << origNum << " - number Armstrong" << endl;
    else 
        cout << origNum << " - not number Armstrong" << endl;
}

void func014()
{
    int low, high, i, temp1, temp2, remainder, n = 0, result = 0;
    cout << "Input start and end of range: ";
    cin >> low >> high;
    cout << "Numbers Armstrongs: "; 

    for(i = low + 1; i < high; ++i)
    {
        temp2 = i;
        temp1 = i;

        while(temp1 != 0 )
        {
            temp1 /= 10;
            ++n;
        }

        while( temp2 != 0)
        {
            remainder = temp2 % 10;
            result += pow (remainder, n);
            temp2 /= 10;
        }

        if (result == i)
        {
            cout << i << " ";
        }

        n = 0;
        result = 0;
    }

    cout << "\n";
}

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

void func015()
{
    int n;
    cout << "Input positive number: ";
    cin >> n;

    cout << "Factorial: " << n << " = " << factorial(n) << endl;
}


int add(int n);
//Сумма n натуральных чисел с использованием рекурсии
void func016()
{
    int n;
    cin >> n;
    cout << "Summ = " << add(n) << endl;
}

int add(int n)
{
    if (n != 0)
        return n + add(n - 1);
    return 0;
}


int gcd(int n1, int n2);
//Вычисление НОД с использованием рекурсии
void func017()
{
    int n1, n2;
    cout << "Input two integer positive numbers: ";

    cin >> n1 >> n2;
    cout << "NOD " << n1 << " and " << n2 << " = " << gcd(n1, n2) << endl;

}
int gcd(int n1, int n2)
{
    if (n2 != 0) {
        cout << "====" << endl;
        cout << "n1 = " << n1 << endl;
        cout << "n2 = " << n2 << endl;
        return gcd(n2, n1 % n2);
    } else {
        return n1;
    }
}


void reverse (const string& a);
void func018()
{
    string str;
    cout << "input string: " << endl;
    getline(cin, str);
    reverse(str);
}

void reverse(const string& str)
{
    //cout << "Reverse " << str << endl;
    size_t numOfChars = str.size();
    if(numOfChars == 1)
        cout << str << endl;
    else
    {
        cout << str[numOfChars-1];
        reverse(str.substr(0, numOfChars - 1));
    }
}

int calculatePower(int, int);
void func019()
{
    int base, powerRaised, result;
    cout << "Input number: ";
    cin >> base;

    cout << "Input power: ";
    cin >> powerRaised;

    result = calculatePower(base, powerRaised+1);
    cout << base << " ^ " << powerRaised << " = " << result << endl; 
}

int calculatePower(int base, int powerRaised)
{
    if(powerRaised != 1)
        return (base * calculatePower(base, powerRaised-1));
    else
        return 1;
}



int main()
{

    //func001();
    //func002_fibonaci();
    //func003_fibonaci_v2();
    //func004_nod();
    //func005_nod_v2();
    //func006_nok();
    //func007();
    //func008();
    //func009();
    //func010();
    //func011_SimpleNumber();
    //func012();
    //func013();
    //func014();
    //func015();
    //func016();
    //func017();
    //func018();
    func019();

    return 0;
}