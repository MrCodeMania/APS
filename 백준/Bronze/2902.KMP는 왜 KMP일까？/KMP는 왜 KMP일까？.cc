#include <iostream>
#include <string>

using namespace std;

int main()
{
    string KMP;
    getline(cin,KMP,'\n');
    
    cout << KMP[0];
    for(int i = 1; i < KMP.size(); i++)
    {
        if(KMP[i] == '-')
            cout << KMP[i+1];
    }
}