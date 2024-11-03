#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void fun001()
{
    ifstream ifiles1, ifiles2;
    ofstream ifilet;
    char ch, fname1[20], fname2[20], fname3[30];

    cout << "Input name first file: ";
    cin >> fname1;

    cout << "input name second file: ";
    cin >> fname2;

    cout << "Input name result file: ";
    cin >> fname3;

    ifiles1.open(fname1, ios_base::binary | ios_base::in);
    ifiles2.open(fname2, ios_base::binary | ios_base::in);

    if(ifiles1 == NULL || ifiles2 == NULL)
    {
        perror("Happen error when open sources file\n");
        exit(EXIT_FAILURE);
    }

    ifilet.open(fname3, ios_base::binary | ios_base::out);
    if(!ifilet)
    {
        perror("Error when create result file\n");
        exit(EXIT_FAILURE);
    }

    ifiles1 >> ifilet.rdbuf();
    ifiles2 >> ifilet.rdbuf();

    cout << "Files were merged in " << fname3 << " success ! \n";

    ifiles1.close();
    ifiles2.close();
    ifilet.close();
}

int main()
{
    fun001();

}