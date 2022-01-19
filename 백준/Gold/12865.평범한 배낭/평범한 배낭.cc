#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int DP[101][100001] = { 0, };

int main()
{
	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> Stuffs;

	for (int i = 0; i < N; i++)
	{
		pair<int, int> Temp;
		cin >> Temp.first;
		cin >> Temp.second;

		Stuffs.push_back(Temp);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (Stuffs[i - 1].first <= j)
				DP[i][j] = max(Stuffs[i - 1].second + DP[i - 1][j - Stuffs[i - 1].first], DP[i - 1][j]);
			else
				DP[i][j] = DP[i - 1][j];
		}
	}

	cout << DP[N][K] << endl;
}