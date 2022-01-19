// 소수를 구하고 골드바흐
// 나누기 2로부터 소수인지

#include <vector>
#include <iostream>

using namespace std;

vector<int> Primes;

void GetPrime();

int main()
{
	cin.tie(NULL);

	int TestCase;
	cin >> TestCase;

	GetPrime();

	while (TestCase--)
	{
		int N;
		cin >> N;

		int Down = (N / 2);
		int Up = (N / 2);

		bool Got = false;

		for (int k = 0; k < (N / 2) - 1; k++)
		{
			for (int i = 0; i < Primes.size(); i++)
			{
				if (Down == Primes[i])
				{
					for (int j = 0; j < Primes.size(); j++)
					{
						if (N - Down == Primes[j])
						{
							cout << Down << " " << N - Down << "\n";
							Got = true;
						}

						if (Got)
							break;
					}
				}

				if (Got)
					break;

				if (Up == Primes[i])
				{
					for (int j = 0; j < Primes.size(); j++)
					{
						if (N - Up == Primes[j])
						{
							cout << N - Up << " " << Up << "\n";
							Got = true;
						}

						if (Got)
							break;
					}
				}

				if (Got)
					break;
			}

			Down--;
			Up++;
		}
	}
}

void GetPrime()
{
	Primes.push_back(2);
	for (int i = 3; i <= 10000; i += 2)
	{
		bool Flag = false;

		for (int j = 2; j < i; j++)
			if (i % j == 0)
				Flag = true;

		if (!Flag)
			Primes.push_back(i);
	}
}