#include <iostream>
#include <vector>

using namespace std;

int Min;

void Colorize(vector<vector<int>> &map, vector<vector<int>> cctv, int time, int dir, int &count)
{
	if (dir == 0)
	{
		for (int i = cctv[time][0]; i >= 0; i--)
		{
			if (map[i][cctv[time][1]] == 6)
				break;
			else if (map[i][cctv[time][1]] == 0)
			{
				count--;
				map[i][cctv[time][1]] = 9;
			}
		}
	}
	else if (dir == 1)
	{
		for (int i = cctv[time][1]; i < map[0].size(); i++)
		{
			if (map[cctv[time][0]][i] == 6)
				break;
			else if (map[cctv[time][0]][i] == 0)
			{
				count--;
				map[cctv[time][0]][i] = 9;
			}
		}
	}
	else if (dir == 2)
	{
		for (int i = cctv[time][0]; i < map.size(); i++)
		{
			if (map[i][cctv[time][1]] == 6)
				break;
			else if (map[i][cctv[time][1]] == 0)
			{
				count--;
				map[i][cctv[time][1]] = 9;
			}
		}
	}
	else if (dir == 3)
	{
		for (int i = cctv[time][1]; i >= 0; i--)
		{
			if (map[cctv[time][0]][i] == 6)
				break;
			else if (map[cctv[time][0]][i] == 0)
			{
				count--;
				map[cctv[time][0]][i] = 9;
			}
		}
	}
}

//
//int GetBlind(vector<vector<int>> map)
//{
//	int Count = 0;
//	for (int i = 0; i < map.size(); i++)
//		for (int j = 0; j < map[i].size(); j++)
//			if (map[i][j] == 0)
//				Count++;
//		
//	return Count;
//}

void DFS(vector<vector<int>> map, vector<vector<int>> cctv, int time, int dir, int count)
{
	vector<vector<int>> map_copy = map;
	// 색칠
	// dir 0 -> 북, 1 -> 동, 2 -> 남, 3 -> 서
	// cctv[time][2] == 1 -> 한 방향

	// 한 방향씩 컬러라이즈
	if (cctv[time][2] == 1)
		Colorize(map_copy, cctv, time, dir, count);
	else if (cctv[time][2] == 2)
	{
		Colorize(map_copy, cctv, time, dir, count);
		Colorize(map_copy, cctv, time, (dir + 2) % 4, count);
	}
	else if (cctv[time][2] == 3)
	{
		Colorize(map_copy, cctv, time, dir, count);
		Colorize(map_copy, cctv, time, (dir + 1) % 4, count);
	}
	else if (cctv[time][2] == 4)
	{
		Colorize(map_copy, cctv, time, dir, count);
		Colorize(map_copy, cctv, time, (dir + 1) % 4, count);
		Colorize(map_copy, cctv, time, (dir + 2) % 4, count);
	}
	else if (cctv[time][2] == 5)
	{
		Colorize(map_copy, cctv, time, dir, count);
		Colorize(map_copy, cctv, time, (dir + 1) % 4, count);
		Colorize(map_copy, cctv, time, (dir + 2) % 4, count);
		Colorize(map_copy, cctv, time, (dir + 3) % 4, count);
	}

	if (time == cctv.size() - 1)
	{
		if (Min > count)
			Min = count;
		return;
	}

	if (cctv[time + 1][2] == 5) {
		DFS(map_copy, cctv, time + 1, 0, count);
	}
	else if (cctv[time + 1][2] == 2) {
		DFS(map_copy, cctv, time + 1, 0, count);
		DFS(map_copy, cctv, time + 1, 1, count);
	}
	else {
		DFS(map_copy, cctv, time + 1, 0, count);
		DFS(map_copy, cctv, time + 1, 1, count);
		DFS(map_copy, cctv, time + 1, 2, count);
		DFS(map_copy, cctv, time + 1, 3, count);
	}


	// Min보다 blind가 적다면 Min 대체

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> Map;
	vector<vector<int>> CCTV;
	Min = N * M;
	int Init = Min;

	for (int i = 0; i < N; i++)
	{
		vector<int> Temp;
		for (int j = 0; j < M; j++)
		{
			int Input;
			cin >> Input;
			Temp.push_back(Input);
			if (Input != 0)
			{
				Init--;
				Min--;
			}
			if (Input > 0 && Input < 6)
			{
				vector<int> Temp2({ i, j, Input });
				CCTV.push_back(Temp2);
			}
		}
		Map.push_back(Temp);
	}
	if (CCTV.size()) {

		DFS(Map, CCTV, 0, 0, Init);
		DFS(Map, CCTV, 0, 1, Init);
		DFS(Map, CCTV, 0, 2, Init);
		DFS(Map, CCTV, 0, 3, Init);
	}

	cout << Min;
}