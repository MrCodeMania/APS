#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int Wine;
	cin >> Wine;

	vector<int> Amount;
	for (int i = 0; i < Wine; i++)
	{
		int Temp;
		cin >> Temp;

		Amount.push_back(Temp);
	}

	int DP[10000] = { Amount[0]};

	if (Wine > 1)
		DP[1] = Amount[0] + Amount[1];
	if (Wine > 2)
	{
		DP[2] = Amount[0] + Amount[2] < Amount[1] + Amount[2] ? Amount[1] + Amount[2] : Amount[0] + Amount[2];

		if (DP[1] > DP[2])
			DP[2] = DP[1];
	}

	for (int i = 3; i < Wine; i++)
	{
		DP[i] = Amount[i] + Amount[i - 1] + DP[i - 3] < Amount[i] + DP[i - 2] ? Amount[i] + DP[i - 2] : Amount[i] + Amount[i - 1] + DP[i - 3];

		if (DP[i - 1] > DP[i])
			DP[i] = DP[i - 1];
	}

	cout << DP[Wine - 1];

	return 0;
}