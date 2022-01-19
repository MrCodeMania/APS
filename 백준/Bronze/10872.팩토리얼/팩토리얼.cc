#include <iostream>

using namespace std;

int factorial(int n)
{
    int ReturnValue = 1;
    
    for(int i = 1; i <= n; i++)
    {
        ReturnValue *= i;
    }
    
    return ReturnValue;
}

int main()
{
    int num;
    cin >> num;
    
    cout << factorial(num);
    
    return 0;
}