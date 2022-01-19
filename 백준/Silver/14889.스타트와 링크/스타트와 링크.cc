// 1을 포함해서 돌면 다 돈 게 아닌 것인가?

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int arr[21][21] = { 0, };
	int Min = 100000;

	vector<int> Index;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	
	for (int i = 0; i <= N / 2; i++)
		Index.push_back(i);

	while (true)
	{
		vector<int> Start;
		vector<int> Link;

		for (int i = 1; i <= N; i++)
			Link.push_back(i);

		for (int i = 1; i < Index.size(); i++)
		{
			Start.push_back(Index[i]);
			Link[Index[i] - 1] = 0;
		}
		
		int S_Sum = 0;

		for (int i = 0; i < Start.size(); i++)
		{
			for (int j = i + 1; j < Start.size(); j++)
			{
				S_Sum += arr[Start[i]][Start[j]] + arr[Start[j]][Start[i]];
			}
		}

		int L_Sum = 0;

		for (int i = 0; i < Link.size(); i++)
		{
			for (int j = i + 1; j < Link.size(); j++)
			{
				if (Link[i] != 0 && Link[j] != 0)
					L_Sum += arr[Link[i]][Link[j]] + arr[Link[j]][Link[i]];
			}
		}
		
		if (abs(S_Sum - L_Sum) < Min)
			Min = abs(S_Sum - L_Sum);
		

		Index[N / 2]++;
		
		for (int i = N / 2; i > 1; i--)
		{
			if (Index[i] >= (i + N / 2))
			{
				++Index[i - 1];

				Index[i] = Index[i - 1] + 1;

				for (int j = i; j < N / 2; j++)
				{
					Index[j + 1] = Index[j] + 1;
				}
			}
		}

		if (Index[2] >= (2 + N / 2))
			break;
	}

	cout << Min;
}