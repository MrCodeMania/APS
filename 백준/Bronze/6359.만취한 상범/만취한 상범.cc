#include <iostream>
#include <vector>

using namespace std;

int Num_of_Divisor(int n)
{
    int Count = 0;
    
    for(int i = 1; i <= n; i++)
        if(n % i == 0)
            Count++;
    
    return Count;
}

int main()
{
    int Testcase;
    cin >> Testcase;
    
    while(Testcase--)
    {
        int Rooms;
        cin >> Rooms;
        
        vector<int> Prisons;
        for(int i = 0; i < Rooms; i++)
            Prisons.push_back(0);
        
        for(int i = 1; i < Prisons.size() + 1; i++)
        {
            if((Num_of_Divisor(i) % 2) == 0)
                Prisons[i-1] = 0;
            else
                Prisons[i-1] = 1;
        }
        
        int Fleer = 0;
        
        for(int i = 0; i < Prisons.size(); i++)
            if(Prisons[i] == 1)
                Fleer++;
        
        cout << Fleer << endl;
    }
}