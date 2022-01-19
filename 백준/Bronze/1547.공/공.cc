#include <iostream>

using namespace std;

int main()
{
    int Ball = 1;
    int Time;
    cin >> Time;
    
    while(Time--)
    {
        int First, Second;
        cin >> First >> Second;
        
        if(First == Ball)
            Ball = Second;
        else if(Second == Ball)
            Ball = First;
    }
    
    cout << Ball;
}