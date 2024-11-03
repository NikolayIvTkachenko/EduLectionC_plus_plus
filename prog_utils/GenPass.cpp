#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>


using namespace std;

class PassGen {
public:
    void displayMessage()
    {
        int passLength;
        int numOfPasswords;
        char * filename = new char;

        cout << "Input length password for generation:  ";
        cin >> passLength;

        cout << "Input quantity password for generation: ";
        cin >> numOfPasswords;

        cout << "Will be generate paswords: " << numOfPasswords << "." << endl;
        cout << endl;
        cout << "Input file anme  for save: ";
        cin >> filename;

        ofstream outFile(filename);

        for(int k = 0; k < numOfPasswords; k++){
            for(int i = 0; i < passLength; ++i) {
                numOfChars(passLength);
                passGenerator(passLength);
                outFile << password[i];
            }
            outFile << endl;
        }
        outFile.close();
        cout << "Password has been saved successfully to file: " << filename << endl;
    }

    void passGenerator(int passLength)
    {
        password = new char [passLength];
        for(int i = 0; i < numOfNumbers; ++i) {
            password[i] = char(rand() % 10 + 48);
        }
        for(int i = numOfNumbers; i < numOfNumbers + numOfBigChars; ++i) {
            password[i] = char(rand() %26 + 65);
        }
        for (int i = numOfNumbers + numOfBigChars; i < passLength; ++i){
            password[i] = char(rand() % 26 + 97);
        }
        random_shuffle(password, password + passLength);
    }

    void numOfChars(int passLength) {
        numOfSmallChars = rand() % passLength;
        int charRandEnd = passLength - numOfSmallChars;
        numOfBigChars = rand() % charRandEnd;
        numOfNumbers = passLength - numOfSmallChars - numOfBigChars;
    }

private:
    int numOfSmallChars;
    int numOfBigChars;
    int numOfNumbers;
    char * password;
};

int main()
{
    srand(time(NULL));
    PassGen * pass = new PassGen;
    pass->displayMessage();

    return 0;
}