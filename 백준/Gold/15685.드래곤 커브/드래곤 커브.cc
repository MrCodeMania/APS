#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int Answer = 0;

	int N;
	cin >> N;

	vector<vector<int>> DragonCurves;
	bool Map[101][101] = { false, };

	DragonCurves.push_back(vector<int>({ 0 }));

	for (int i = 1; i < 11; i++)
	{
		vector<int> Temp = DragonCurves[i - 1];
		for (int j = DragonCurves[i-1].size() - 1; j >= 0; j--)
			Temp.push_back((DragonCurves[i - 1][j] + 1) % 4);
		
		DragonCurves.push_back(Temp);
	}
	while (N--)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		Map[x][y] = true;
		int row = x, col = y;

		for (int i = 0; i < DragonCurves[g].size(); i++)
		{
			if ((DragonCurves[g][i] + d) % 4 == 0)
				Map[++row][col] = true;
			else if ((DragonCurves[g][i] + d) % 4 == 1)
				Map[row][--col] = true;
			else if ((DragonCurves[g][i] + d) % 4 == 2)
				Map[--row][col] = true;
			else if ((DragonCurves[g][i] + d) % 4 == 3)
				Map[row][++col] = true;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (Map[i][j])
			{
				if (Map[i + 1][j] && Map[i][j + 1] && Map[i + 1][j + 1])
					Answer++;
			}
		}
	}

	cout << Answer;
}