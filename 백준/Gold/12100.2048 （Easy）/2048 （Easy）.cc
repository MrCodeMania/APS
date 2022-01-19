#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Max = 1;
int N;

void DFS(vector<vector<int>> board, int d, int times)
{
	int local_max = 2;
	
	int nomore = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (local_max < board[i][j])
				local_max = board[i][j];
			if(board[i][j])
				nomore++;
		}

	}
		
	if (Max < local_max)
		Max = local_max;

	if (Max > local_max * pow(2, 5 - times))
		return;

	if (times == 5)
		return;
	
	if (nomore == 1)
		return;
	
	int last_index = 0;

	bool unified[20][20] = { false, };

	if (d == 0)
	{
		for (int i = 0; i < N; i++)
		{
			last_index = N - 1;

			for (int j = N - 2; j >= 0; j--)
			{
				if (board[i][j])
				{
					if (unified[i][last_index])
						swap(board[i][--last_index], board[i][j]);
					else
					{
						if (board[i][last_index] == 0)
							swap(board[i][last_index], board[i][j]);
						else if (board[i][last_index] == board[i][j])
						{
							board[i][last_index] *= 2;
							board[i][j] = 0;
							unified[i][last_index] = true;
						}
						else if (board[i][last_index] != board[i][j])
							swap(board[i][--last_index], board[i][j]);
					}
				}
			}
		}
	}
	else if (d == 1)
	{
		for (int i = 0; i < N; i++)
		{
			last_index = 0;

			for (int j = 1; j < N; j++)
			{
				if (board[i][j])
				{
					if (unified[i][last_index])
					{
						last_index++;
						swap(board[i][last_index], board[i][j]);
					}
					else
					{
						if (board[i][last_index] == 0)
							swap(board[i][last_index], board[i][j]);
						else if (board[i][last_index] == board[i][j])
						{
							board[i][last_index] *= 2;
							board[i][j] = 0;
							unified[i][last_index] = true;
						}
						else if (board[i][last_index] != board[i][j])
							swap(board[i][++last_index], board[i][j]);
					}
				}
			}
		}
	}
	else if (d == 2)
	{
		for (int j = 0; j < N; j++)
		{
			last_index = 0;

			for (int i = 1; i < N; i++)
			{
				if (board[i][j])
				{
					if (unified[last_index][j])
					{
						last_index++;
						swap(board[last_index][j], board[i][j]);
					}
					else
					{
						if (board[last_index][j] == 0)
							swap(board[last_index][j], board[i][j]);
						else if (board[last_index][j] == board[i][j])
						{
							board[last_index][j] *= 2;
							board[i][j] = 0;
							unified[last_index][j] = true;
						}
						else if (board[last_index][j] != board[i][j])
							swap(board[++last_index][j], board[i][j]);
					}
				}
			}
		}
	}
	else if (d == 3)
	{
		for (int j = 0; j < N; j++)
		{
			last_index = N - 1;

			for (int i = N - 2; i >= 0; i--)
			{
				if (board[i][j])
				{
					if (unified[last_index][j])
					{
						last_index--;
						swap(board[last_index][j], board[i][j]);
					}
					else
					{
						if (board[last_index][j] == 0)
							swap(board[last_index][j], board[i][j]);
						else if (board[last_index][j] == board[i][j])
						{
							board[last_index][j] *= 2;
							board[i][j] = 0;
							unified[last_index][j] = true;
						}
						else if (board[last_index][j] != board[i][j])
							swap(board[--last_index][j], board[i][j]);
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
		DFS(board, i, times + 1);
}

int main()
{
	cin >> N;

	vector<vector<int>> board;


	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			temp.push_back(input);
		}
		board.push_back(temp);
	}

	DFS(board, 5, -1);

	cout << Max << endl;
}