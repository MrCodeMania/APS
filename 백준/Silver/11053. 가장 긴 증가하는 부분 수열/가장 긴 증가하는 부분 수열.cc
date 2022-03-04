#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 50 -> 20 -> 30
	// 10 l 20 l 10 l 30 l 20 l 50
    //                           3

	// 자신보다 높으면 DP[i] = 1;
	// 자신보다 낮으면 DP[i] + DP[before] (전에 인덱스);

	int N = 0;
	cin >> N;

	vector<int> A;
	int DP[1000] = { 0, };
	// 6
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	
	int Max = 0;

	for (int i = 1; i < N; i++)
	{
		int Last = i;

		for (int j = i - 1; j >= 0; j--)
		{
			if (A[i] > A[j])
			{
				if (DP[Last] <= DP[j])
					Last = j;
			}
		}

		if (Last != i)
		{
			DP[i] = DP[Last] + 1;
		}

		if (DP[i] > DP[Max])
			Max = i;
	}

	cout << DP[Max] + 1 << endl;

}