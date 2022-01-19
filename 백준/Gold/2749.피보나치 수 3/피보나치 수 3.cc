#include <iostream>
#include <vector>

using namespace std;

int fibonacci(long long n)
{
	vector<int> Fib;
	Fib.push_back(0);
	Fib.push_back(1);
	Fib.push_back(1);
    
    if(n >= 1500000)
        n %= 1500000;
    
	for (int i = 3; i <= n; i++)
		Fib.push_back((Fib[i - 2]%1000000 + Fib[i - 1]%1000000)%1000000);
	
	return Fib[n];
}

int main()
{
	long long n;
	cin >> n;

	cout << fibonacci(n);

	return 0;
}
