#include <iostream>

using namespace std;

int main()
{
    long long A, B;
    cin >> A >> B;
    
    long long Temp_A = A;
    long long Temp_B = B;
    
    while(true)
    {
        if(Temp_A == Temp_B)
        {
            cout << Temp_A;
            break;
        }    
        else if(Temp_A > Temp_B)
            Temp_B += B;
        else
            Temp_A += A;
    }
}