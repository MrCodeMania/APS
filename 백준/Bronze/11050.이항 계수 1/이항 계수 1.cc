#include <iostream>

using namespace std;

int Factorial(int n)
{
	if ((n == 1) || (n == 0))
		return 1;
	else
		return Factorial(n - 1) * n;
}

int main()
{
	int N;
	int K;

	cin >> N >> K;
    
    if(1 <= N && N <= 10 && 0 <= K && K <= N)
	    cout << Factorial(N) / (Factorial(K) * Factorial(N - K));

	return 0;
}