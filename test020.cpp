#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void func001()
{
    setlocale(LC_CTYPE, "");
    unsigned int k;
    string str;

    set<string> glossary;
    ifstream in("ttest.txt");
    
    if(in.is_open())
    {
        while (in >> str)
        {
            k = str.find_last_of("\",.;:!?-+=");
            if (k != -1) str.erase(k);
            if(str.size() < 2) continue;

            glossary.emplace(str);
        }
        for (auto e : glossary) cout << e << endl;
    }
    else
    {
        cout << "FILE DOES NOT FOUND \n";
    }
}

void func002()
{
    setlocale(LC_CTYPE, "");
    ifstream file("raw_data.txt");

    if(file.is_open())
    {
        vector<vector<double>> v;
        string str, str_val;

        while (getline(file, str))
        {
            vector<double> vs;
            istringstream in(str);
            double z;

            while(in >> z) vs.push_back(z);
            v.push_back(vs);
        }

        for(size_t i = 0; i < v.size(); ++i)
        {
            for( auto e: v[i]) cout << e << ' ';
            cout << endl;
        }

    }
}


int main()
{

}