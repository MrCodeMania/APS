#include <iostream>

using namespace std;

int main()
{
    int Score[5];
    int Avrg = 0;
    
    for(int i = 0; i < 5; i++)
    {
        cin >> Score[i];
        if(Score[i] < 40)
            Score[i] = 40;
    }
        
    Avrg = (Score[0] + Score[1] + Score[2] + Score[3] + Score[4]) / 5;
    
    cout << Avrg;
}