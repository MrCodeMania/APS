#include <iostream>
#include <vector>

using namespace std;

int Fibonacci(int n);

int main()
{
    int num;
    cin >> num;
    
    cout << Fibonacci(num) ;
}

int Fibonacci(int n)
{
    vector<int> Fibonacci;
    
    Fibonacci.push_back(0);
    Fibonacci.push_back(1);
    
    for(int i = 2; i <= n; i++)
        Fibonacci.push_back(Fibonacci[i-2] + Fibonacci[i-1]);
    
    return Fibonacci[n];
}