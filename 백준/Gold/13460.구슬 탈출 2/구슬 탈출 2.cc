#include <iostream>
#include <vector>

using namespace std;

// 방향이 L이면 구슬들의 x좌표를 참조해 먼저 움직일 구슬을 정한다.
// Red(); Blue();

enum e { r, l, down, up };

char c[2] = { 'R','B' };
int dir[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
int N, M;
int pos[2][2] = { 0, }; // red = 0, blue = 1
int Min = 11;

// 벽이나 구슬, 골 만날 때까지 move
pair<int,int> Move(vector<vector<char>> board, int color, int d)
{
	// d == 0 || 1 -> 1
	// d == 2 || 3 -> 0

	int last_i = pos[color][0];
	int last_j = pos[color][1];

	int new_i = last_i;
	int new_j = last_j;

	for (int i = 0; i < 12; i++)
	{
		new_i = new_i + dir[d][0];
		new_j = new_j + dir[d][1];

		if (new_i > 0 && new_i < N - 1 && new_j > 0 && new_j < M - 1)
		{
			if (board[new_i][new_j] == 'O')
				return make_pair(-1,-1);
			if (board[new_i][new_j] == '#' || board[new_i][new_j] == c[abs(color - 1)])
				break;
			else if (board[new_i][new_j] == '.')
			{
				last_i = new_i;
				last_j = new_j;
			}
		}
		else break;
	}

	return make_pair(last_i, last_j);
}

void DFS(vector<vector<char>> board, int direction, int times)
{
	if (times == 11)
		return;

	// direction == 0, color == 1, 
	

	
	int f_c = 0;
	int s_c = 1;
	int pos_temp[2][2];

	pos_temp[0][0] = pos[0][0];
	pos_temp[0][1] = pos[0][1];
	pos_temp[1][0] = pos[1][0];
	pos_temp[1][1] = pos[1][1];

	if (direction == 0 || direction == 3)
	{
		if (pos[0][abs(direction / 2 - 1)] > pos[1][abs(direction / 2 - 1)])
		{
			f_c = 0;
			s_c = 1;
		}
		else
		{
			f_c = 1;
			s_c = 0;
		}
	}
	else
	{
		if (pos[0][abs((direction / 2) - 1)] < pos[1][abs((direction / 2) - 1)])
		{
			f_c = 0;
			s_c = 1;
		}
		else
		{
			f_c = 1;
			s_c = 0;
		}
	}

	bool Goal[2] = { false, };
	
	pair<int, int> ret = Move(board, f_c, direction);
	if (ret.first == -1)
	{
		Goal[f_c] = true;
		board[pos[f_c][0]][pos[f_c][1]] = '.';
	}
	else
		swap(board[ret.first][ret.second], board[pos[f_c][0]][pos[f_c][1]]);
			
	pair<int, int> ret_2 = Move(board, s_c, direction);
	if (ret_2.first == -1)
	{
		Goal[s_c] = true;
		board[pos[s_c][0]][pos[s_c][1]] = '.';
	}
	else
		swap(board[ret_2.first][ret_2.second], board[pos[s_c][0]][pos[s_c][1]]);

	if (Goal[0])
	{
		if (Goal[1])
			return;
		else
		{
			if (times < Min)
				Min = times;
					
			return;
		}
	}
	else if (Goal[1])
		return;
			
	if (ret_2.first == pos[s_c][0] && ret_2.second == pos[s_c][1] && ret.first == pos[f_c][0] && ret.second == pos[f_c][1]);
	else
	{
		pos[f_c][0] = ret.first;
		pos[f_c][1] = ret.second;
		pos[s_c][0] = ret_2.first;
		pos[s_c][1] = ret_2.second;
				
		for(int d = 0; d < 4; d++)
			DFS(board, d, times + 1);
	}

	pos[0][0] = pos_temp[0][0];
	pos[0][1] = pos_temp[0][1];
	pos[1][0] = pos_temp[1][0];
	pos[1][1] = pos_temp[1][1];

	swap(board[ret_2.first][ret_2.second], board[pos[s_c][0]][pos[s_c][1]]);
	swap(board[ret.first][ret.second], board[pos[f_c][0]][pos[f_c][1]]);
		
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<vector<char>> board;

	for (int i = 0; i < N; i++)
	{
		vector<char> temp;
		for (int j = 0; j < M; j++)
		{
			char t;
			cin >> t;
			temp.push_back(t);
		}
		board.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'B')
			{
				pos[1][0] = i;
				pos[1][1] = j;
			}
			else if (board[i][j] == 'R')
			{
				pos[0][0] = i;
				pos[0][1] = j;
			}
		}
	}

	DFS(board, 0, 1);
	DFS(board, 1, 1);
	DFS(board, 2, 1);
	DFS(board, 3, 1);
	
	if (Min == 11)
		cout << -1 << endl;
	else
		cout << Min << endl;

	return 0;
}