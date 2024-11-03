#include <iostream>
#include <iomanip>
#include <cstdio>
#include "string.h"
#include <cstring> 
#include <fstream>

using namespace std;

void func001TempFile() {
    string name1 = tmpnam(nullptr);
    cout << "Name temp file: " << name1 << '\n';

    char name2[L_tmpnam];
    if(tmpnam(name2)) {
        cout << "Name temp files: " << name2 << '\n';
    }
}

class passkey
{
private:
    int password, key, k;
public:
    passkey();
    void getkey();
    int checkkey(int);
    friend void encrypt(passkey);
    friend void decrypt(passkey);

} file1;

passkey::passkey()
{
    password = 88;
}

void passkey::getkey()
{
    cout << "Input key: ";
    cin >> key;
}

int passkey::checkkey(int a)
{
    if(a == key)
        return 1;
    else
        return 0;
}

char filenaam[40];


int fun002_cipherfile()
{
    int a, pw, x, k;
    string c;

    cout << "Input password (88): ";
    cin >> pw;
    if(pw != 88)
    {
        cout << "Incorrect password" << endl;
        return 0;
    }
    cout << "1 - encrypt\n 2-decrypt\n 3 - exit" << endl;

    cin >> a;
    if(a == 1)
    {
        file1.getkey();

        cout << "Name of file \n Direct \"Input _ata\"" << endl;
        cin >> filename;
        strcat(filenaam,".txt");

        cout << "Data for ebcrypt (XTRL + D for change input): " << endl;
        ofstream InputData(filenaam);

        while(cin >> c)
        {
            InputData << c << " ";
        }
        InputData.close();
        encrypt(file1);

        return 0;
    }
    else if(a==2)
    {
        file1.getkey();
        cout << "Input filename\n Direct: Input_Data" << endl;
        cin >> filenaam;

        strcat(filenaam, ".txt");
        decrypt(file1);

        return 0;
    }
    return 0;
}

void encrypt(passkey file)
{
    char encfilenaam[50] = "Encrypted_";
    strcat(encfilenaam, filenaam);

    int n;
    srand(file.key);
    ifstream OutputData(filenaam);
    char ch[50] = "";
    ofstream InputData(encfilenaam);
    OutputData.getline(ch, 49);

    do
    {
        n = 1 + rand() % 9;
        for(int i = 0; i < strlen(ch); i++)
        {
            ch[i] = ch[i] + n;
        }
        InputData << ch;
    } while(OutputData.getline(ch, 49));

    OutputData.close();
    InputData.close();

    cout << "File encrypt success" << endl;
    cout << "Encrypted data saves in file: " << encfilename << endl;
}

void decrypt(passkey file)
{
    char decfilenaam[50] = "Decrypted_";
    strcat(decfilenaam, filenaam);

    int m;
    srand(file.key);

    ifstream OutputData(filenaam);
    char ch[50] = "";

    ofstream InputData(decfilenaam);

    OutputData.getline(ch, 49);

    do
    {
        m = 1 + rand() % 9;
        for(int i = 0; i < strlen(ch); i++)
        {
            ch[i] = ch[i] - m;
        }
        InputData << ch;
    } while(OutputData.getline(ch, 49));

    OutputData.close();
    InputData.close();

    cout << "File decrypt success" << endl;
    cout << "Decrypt text save in file: "  << decfilenaam << endl;

}


int main()
{
    //func001TempFile();
    fun002_cipherfile();
}