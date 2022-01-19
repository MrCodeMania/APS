#include <iostream>
#include <algorithm>

using namespace std;

void DFS(char map[][100], int N, char color, int row, int col)
{
	if (map[row][col] == color)
		map[row][col] = '0';
	else
		return;
	
	if (row > 0)
		DFS(map, N, color, row - 1, col);
	if (row < N - 1)
		DFS(map, N, color, row + 1, col);
	if (col > 0)
		DFS(map, N, color, row, col - 1);
	if (col < N - 1)
		DFS(map, N, color, row, col + 1);
	



}

int main()
{
	int N;
	cin >> N;

	char Grid[100][100];
	char Weakness[100][100];
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char cInput;
			cin >> cInput;
			
			Grid[i][j] = cInput;
			if (cInput == 'R')
				cInput = 'G';
			Weakness[i][j] = cInput;
		}
	}

	int f_answer = 0;
	int s_answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Grid[i][j] != '0')
			{
				f_answer++;
				DFS(Grid, N, Grid[i][j], i, j);
			}
			if (Weakness[i][j] != '0')
			{
				s_answer++;
				DFS(Weakness, N, Weakness[i][j], i, j);
			}
		}
	}
	
	cout << f_answer << " " << s_answer;
}