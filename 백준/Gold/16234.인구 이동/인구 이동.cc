#include <iostream>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;

int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0, -1} };
int countries[50][50];
int unions[50][50] = { 0, };
int N, L, R;
//DFS로 다찾은 다음 1로 정한다 그룹이 정해진 나라는 방문 안함

void DFS(int r, int c, int u)
{
	for (int i = 0; i < 4; i++)
	{
		int new_r = r + dir[i][0];
		int new_c = c + dir[i][1];

		if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N)
		{
			if (!unions[new_r][new_c])
			{
				if ((abs(countries[r][c] - countries[new_r][new_c]) >= L) && (abs(countries[r][c] - countries[new_r][new_c]) <= R))
				{
					unions[new_r][new_c] = u;
					DFS(new_r, new_c, u);
				}
			}
		}
	}
}

int main()
{
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> countries[i][j];
	int times = 0;

	while (true)
	{
		bool Organize = false;
		
		memset(unions, 0, sizeof(unions));
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!unions[i][j])
					DFS(i, j, i * N + j + 1);
			}
		}

		map<int, pair<int,int>> m;
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (unions[i][j] == 0)
					continue;
				if (m.find(unions[i][j]) == m.end())
					m[unions[i][j]] = make_pair(countries[i][j],1);
				else
				{
					Organize = true;
					m[unions[i][j]].first += countries[i][j];
					m[unions[i][j]].second += 1;
				}
			}
		}

		if (!Organize)
			break;

		times += 1;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (unions[i][j] == 0)
					continue;
				countries[i][j] = int(m[unions[i][j]].first / m[unions[i][j]].second);
			}
		}
	}

	cout << times << endl;
}