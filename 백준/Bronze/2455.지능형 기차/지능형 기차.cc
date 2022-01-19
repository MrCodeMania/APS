#include<iostream>

using namespace std;

int main()
{
    int Max = 0;
    int People = 0;
    
    for(int i = 0; i < 4; i++)
    {
        int In, Out;
        
        cin >> Out >> In;
        
        People += In;
        People -= Out;
        
        if(People > Max)
            Max = People;
    }
    
    cout << Max;
}