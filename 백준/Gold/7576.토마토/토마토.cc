#include <iostream>
#include <queue>

int idx, nidx;
char b[1000][1000];
char buf[1<<18];
using namespace std;

char read()
{
	if (idx == nidx) {
		nidx = fread(buf, 1, 1 << 18, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt()
{
	int sum = 0;
	int flg = 0;
	char now = read();

	while (now == ' ' || now == '\n') now = read();
	if (now == '-') flg = 1, now = read();
	while (now >= '0' && now <= '9') {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? -sum : sum;
}

int main()
{
	int M, N;
    M = readInt();
    N = readInt();

	int** Tomato = new int*[N];
	for (int i = 0; i < N; i++)
		Tomato[i] = new int[M];

	queue<pair<int, int>> Queue;
	int Time = 0;
	bool IsGoing = false;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Tomato[i][j] = readInt();
			
			if (Tomato[i][j] == 1)
				Queue.push(make_pair(i, j));
			else if (Tomato[i][j] == 0)
				IsGoing = true;
		}
	}
	

	while (IsGoing)
	{
		int Last_Size = Queue.size();

		while (Last_Size--)
		{
			int row = Queue.front().first;
			int col = Queue.front().second;
			Queue.pop();

			if (row > 0)
			{
				if (Tomato[row - 1][col] == 0)
				{
					Tomato[row - 1][col] = 1;
					Queue.push(make_pair(row - 1, col));
				}
			}

			if (row < N - 1)
			{
				if (Tomato[row + 1][col] == 0)
				{
					Tomato[row + 1][col] = 1;
					Queue.push(make_pair(row + 1, col));
				}
			}

			if (col > 0)
			{
				if (Tomato[row][col - 1] == 0)
				{
					Tomato[row][col - 1] = 1;
					Queue.push(make_pair(row, col - 1));
				}
			}

			if (col < M - 1)
			{
				if (Tomato[row][col + 1] == 0)
				{
					Tomato[row][col + 1] = 1;
					Queue.push(make_pair(row, col + 1));
				}
			}
		}

		if (++Time > M * N)
			break;
		IsGoing = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Tomato[i][j] == 0)
				{
					IsGoing = true;
					break;
				}
			}
			if (IsGoing)
				break;
		}
	}

	if (IsGoing)
		cout << -1;
	else
		cout << Time;
}
