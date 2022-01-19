#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);

	vector<int> Primes;

	Primes.push_back(2);
	Primes.push_back(3);
	for (int i = 4; i < 1000; i++)
	{
		bool IsPrime = true;

		if (i % 2 == 0 || i % 3 == 0)
			continue;
		for (int j = 4; j < i; j++)
		{
			if (i % j == 0)
			{
				IsPrime = false;
				break;
			}
		}

		if (IsPrime)
			Primes.push_back(i);
	}

	int N, Count = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int Input;
		cin >> Input;

		for (int j = 0; j < Primes.size(); j++)
			if (Input == Primes[j])
				Count++;
	}

	cout << Count << "\n";

	return 0;
}