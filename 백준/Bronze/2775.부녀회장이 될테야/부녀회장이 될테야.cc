#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		int k, n;
		cin >> k >> n;

		vector<vector<int>> House;

		for (int i = 0; i <= k; i++)
		{
			vector<int> Temp;
			Temp.resize(n);
			House.push_back(Temp);
		}

		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				House[i][j] = 0;

				if (i == 0)
					House[i][j] = j + 1;
				else
				{
					for (int t = 0; t <= j; t++)
					{
						House[i][j] += House[i - 1][t];
					}
				}
			}
		}

		cout << House[k][n -1] << endl;
	}

	return 0;
}