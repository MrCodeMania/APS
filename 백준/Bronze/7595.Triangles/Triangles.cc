#include <iostream>

using namespace std;

int main()
{
    int iTime;
    
    while(true)
    {
        cin >> iTime;
        
        if(iTime==0)
            break;
        
        for(int i = 0; i < iTime; i++)
        {
            for(int j = 0; j < i+1; j++)
                cout << "*";
            cout << endl;
        }
    }
}