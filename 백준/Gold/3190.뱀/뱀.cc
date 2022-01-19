#include <iostream>
#include <queue>

using namespace std;

int Map[101][101] = { 0, };
int head[2] = { 1,1 };
int tail[2] = { 1,1 };
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main()
{
	int N;
	cin >> N;

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		Map[r][c] = 2;
	}

	int L;
	cin >> L;

	queue<pair<int, char>> Direction;
	

	for (int i = 0; i < L; i++)
	{
		int X;
		char C;
		cin >> X >> C;
		
		Direction.push(make_pair(X, C));
	}

	Map[1][1] = 1;
	int index = 0;
	int time = 0;

	queue<pair<int, int>> Snake;
	Snake.push(make_pair(head[0], head[1]));

	while (true)
	{
		time++;

		head[0] += dir[index][0];
		head[1] += dir[index][1];

		if (head[0] < 1 || head[0] > N || head[1] < 1 || head[1] > N)
			break;
		else if (Map[head[0]][head[1]] == 1)
			break;
		else if (Map[head[0]][head[1]] == 0)
		{
			Snake.pop();
			Map[head[0]][head[1]] = 1;
			Map[tail[0]][tail[1]] = 0;
		}
		else if (Map[head[0]][head[1]] == 2)
		{
			Map[head[0]][head[1]] = 1;
		}

		Snake.push(make_pair(head[0], head[1]));

		tail[0] = Snake.front().first;
		tail[1] = Snake.front().second;
		
		if (Direction.size())
		{
			if (Direction.front().first == time)
			{
				if (Direction.front().second == 'L')
					index = index - 1 < 0 ? index - 1 + 4 : index - 1;
				if (Direction.front().second == 'D')
					index = index + 1 > 3 ? index + 1 - 4 : index + 1;

				Direction.pop();
			}
		}
	}

	cout << time<< endl;
}