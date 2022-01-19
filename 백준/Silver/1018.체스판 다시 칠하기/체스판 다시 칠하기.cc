#include <iostream>

using namespace std;

char Board[50][50];

int main()
{
	int N, M;
	cin >> N >> M;

	int Min = 64;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> Board[i][j];
	}

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			// W 스타트
			int Num = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if (((k - i) + (l - j)) % 2)
					{
						if (Board[k][l] == 'W')
							Num += 1;
					}
					else
					{
						if (Board[k][l] == 'B')
							Num += 1;
					}
				}
			}

			if (Min > Num)
				Min = Num;
			Num = 0;


			// W 스타트
			Num = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if (((k - i) + (l - j)) % 2)
					{
						if (Board[k][l] == 'B')
							Num += 1;
					}
					else
					{
						if (Board[k][l] == 'W')
							Num += 1;
					}
				}
			}

			if (Min > Num)
				Min = Num;
		}
	}

	cout << Min << endl;
}