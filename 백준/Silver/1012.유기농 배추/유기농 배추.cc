#include <iostream>
#include <vector>

#define IOFAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

class Cabbage
{
private:
	vector<vector<int>> Farm;
	int Count;
public:
	Cabbage(int M, int N, int K);
	void DFS(int row, int col, bool flag);
	void GetCount();
};

Cabbage::Cabbage(int M, int N, int K)
{
	Count = 0;

	for (int i = 0; i < N; i++)
	{
		vector<int> Temp;
		for(int j = 0; j < M; j++)
			Temp.push_back(0);

		Farm.push_back(Temp);
	}	

	for (int i = 0; i < K; i++)
	{
		int m, n;
		cin >> m >> n;

		Farm[n][m] = 1;
	}
}

void Cabbage::DFS(int row, int col, bool flag)
{
	if (Farm[row][col] == 1)
	{
		Farm[row][col] = 0;
		if (flag)
		{
			Count++;
			flag = false;
		}
	}
	else
		return;

	if (row > 0)
		DFS(row - 1, col, flag);
	if (col > 0)
		DFS(row, col - 1, flag);
	if (row < Farm.size() - 1)
		DFS(row + 1, col, flag);
	if (col < Farm[0].size() - 1)
		DFS(row, col + 1, flag);
}

void Cabbage::GetCount()
{
	cout << Count << "\n";
}

int main()
{
	IOFAST();

	int iTestCase;
	cin >> iTestCase;

	while (iTestCase--)
	{
		int M, N, K;
		cin >> M >> N >> K;

		Cabbage C(M, N, K);
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				C.DFS(i, j, true);
			}
		}

		C.GetCount();
	}

	return 0;
}
