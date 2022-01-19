#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	vector<int> Primes;
	int Sum = 0;

	for (int i = M; i <= N; i++)
	{
		bool Flag = false;
		
		if (i == 2 || i == 3)
		{
			Primes.push_back(i);
			continue;
		}
		
		if (i % 2 == 0 || i % 3 == 0 || i == 1)
			continue;
		
		for (int j = 3; j < i; j++)
		{
			if (i % j == 0)
			{
				Flag = true;
				break;
			}
		}
		if (!Flag)
			Primes.push_back(i);
	}

	for (int i = 0; i < Primes.size(); i++)
		Sum += Primes[i];

	if (Primes.size() == 0)
		cout << -1;
	else
		cout << Sum << "\n" << Primes[0];

	return 0;
}