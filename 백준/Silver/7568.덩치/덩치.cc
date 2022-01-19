#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<pair<int, int>> Men;
	int Level[50] = { 0, };
	
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		Men.push_back(make_pair(x,y));
	}

	for (int i = 0; i < N; i++)
	{
		int Rank = 1;

		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				if (Men[i].first < Men[j].first && Men[i].second < Men[j].second)
					Rank++;
			}
		}

		Level[i] = Rank;
	}

	for (int i = 0; i < N; i++)
		cout << Level[i] << " ";
}