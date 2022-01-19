#include <iostream>
#include <vector>

using namespace std;

long long fibonacci(int n)
{
    vector<long long> Fib;
    Fib.push_back(0);
    Fib.push_back(1);
    
    for(int i = 2; i <= n; i++)
        Fib.push_back(Fib[i-2]+Fib[i-1]);
    
    return Fib[n];
}

int main()
{
    int n;
    cin >> n;
    
    cout << fibonacci(n);
    
    return 0;
}
