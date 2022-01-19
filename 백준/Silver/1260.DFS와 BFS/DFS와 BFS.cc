#include <iostream>
#include <queue>

using namespace std;

void DFS(bool visited[], bool connect[][1001], int vertex, int num)
{
	cout << vertex << " ";
	for (int i = 1; i <= num; i++)
	{
		if (vertex != i)
		{
			if (!visited[i] && (connect[vertex][i] || connect[i][vertex]))
			{
				visited[i] = true;
				DFS(visited, connect, i, num);
			}
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	bool Connect[1001][1001] = { false, };
	bool Visited[1001] = { false, };

	for (int i = 0; i < M; i++)
	{
		int F, S;
		cin >> F >> S;

		Connect[F][S] = true;
		Connect[S][F] = true;
	}

	Visited[V] = true;
	cout << V << " ";

	for (int i = 1; i <= N; i++)
	{
		if (V != i)
		{
			if (!Visited[i] && (Connect[V][i] || Connect[i][V]))
			{
				Visited[i] = true;
				DFS(Visited, Connect, i, N);
			}
		}
	}

	cout << endl;

	queue<int> BFS;
	bool BFS_Visited[1001] = { false, };

	cout << V << " ";
	BFS_Visited[V] = true;
	BFS.push(V);

	while (!BFS.empty())
	{
		int Times = BFS.size();

		while (Times--)
		{
			for (int i = 1; i <= N; i++)
			{
				if (BFS.front() != i)
				{
					if (!BFS_Visited[i] && (Connect[BFS.front()][i] || Connect[i][BFS.front()]))
					{
						cout << i << " ";
						BFS_Visited[i] = true;
						BFS.push(i);
					}
				}
			}

			if (BFS.empty())
				break;

			BFS.pop();
		}
	}
}