#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int Miro[101][101];
	
	for (int i = 1; i <= N; i++)
	{
		string S;
		cin >> S;

		for (int j = 0; j < M; j++)
			Miro[i][j + 1] = S[j] - 48;
	}

	queue<pair<int,int>> Q;
	Q.push(pair<int,int>({ 1,1 }));
	bool Visited[101][101] = { false, };

	int Count = 0;

	while (true)
	{
		int Times = Q.size();

		Count++;

		while (Times--)
		{
			if (Q.front().first == N && Q.front().second == M)
				break;

			// 위로
			if (Q.front().first > 1 && !Visited[Q.front().first - 1][Q.front().second])
			{
				if (Miro[Q.front().first - 1][Q.front().second])
				{
					Visited[Q.front().first - 1][Q.front().second] = true;
					Q.push(pair<int, int>({ Q.front().first - 1, Q.front().second }));
				}
			}

			// 왼쪽
			if (Q.front().second > 1 && !Visited[Q.front().first][Q.front().second - 1])
			{
				if (Miro[Q.front().first][Q.front().second - 1])
				{
					Visited[Q.front().first][Q.front().second - 1] = true;
					Q.push(pair<int, int>({ Q.front().first, Q.front().second - 1 }));
				}
			}

			// 아래로
			if (Q.front().first < N && !Visited[Q.front().first + 1][Q.front().second])
			{
				if (Miro[Q.front().first + 1][Q.front().second])
				{
					Visited[Q.front().first + 1][Q.front().second] = true;
					Q.push(pair<int, int>({ Q.front().first + 1, Q.front().second }));
				}
			}

			// 오른쪽
			if (Q.front().second < M && !Visited[Q.front().first][Q.front().second + 1])
			{
				if (Miro[Q.front().first][Q.front().second + 1])
				{
					Visited[Q.front().first][Q.front().second + 1] = true;
					Q.push(pair<int, int>({ Q.front().first, Q.front().second + 1 }));
				}
			}

			Q.pop();
		}


		if (Times >= 0)
			break;
	}

	cout << Count << endl;
}