#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> Stick;
    Stick.push_back(64);
    
    int Target;
    cin >> Target;
    
    int Last = 0;
    
    while(true)
    {
        if(Target == 64)
            break;
         
        
        int Sum = 0;
        for(int i = 0; i < Stick.size(); i++)
            Sum += Stick[i];
        
        if(Target == Sum)
            break;
        else if(Target < Sum)
        {
            Stick[Last] /= 2;
            
            Sum = 0;
            for(int i = 0; i < Stick.size(); i++)
                Sum += Stick[i];
            
            if(Target <= Sum)
                continue;
            else
                Stick.push_back(Stick[Last++]);
        }
    }
    
    cout << Stick.size();
    
    return 0;
}