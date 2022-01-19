#include <iostream>

using namespace std;

int main()
{
    int Input;
    cin >> Input;
    
    int NewNumber = Input;
    int Cycle = 1;    
        
    while(true)
    {
        int OldNumber = NewNumber;
        
        int Second = (OldNumber / 10) + (OldNumber % 10);
        NewNumber = (OldNumber % 10) * 10 + Second % 10;
        
        if(NewNumber == Input)
            break;
        
        Cycle++;
    }
    
    cout << Cycle;
        
}