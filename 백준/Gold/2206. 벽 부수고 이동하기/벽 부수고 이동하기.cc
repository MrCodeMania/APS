#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001] = { 0, };
bool visited[1001][1001][2] = { false, };
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int N, M;

class qData {
public:
	int i;
	int j;
	bool pass;
	qData(int i, int j, int pass) {
		this->i = i;
		this->j = j;
		this->pass = pass;
	}
};

int solution() {
	
	queue<qData> q;
	q.push(qData(1, 1, false));
	
	visited[1][1][0] = true;
	visited[1][1][1] = true;
	
	int cnt = 1;
	bool success = false;

	if (N == 1 && M == 1)
		return 1;

	while (q.size()) {
		int size = q.size();
		while (size--) {
			qData temp = q.front();
			
			// 4방향 돌면서 bfs queue에 담기
			// 벽이 있다면 pass == false 일 때만, 허물고 넣기
			// cout << temp.i << " " << temp.j << endl;
			for (int i = 0; i < 4; i++) {
				int new_i = temp.i + dir[i][0];
				int new_j = temp.j + dir[i][1];

				if (new_i == N && new_j == M) {
					success = true;
					while (q.size()) 
						q.pop();
					break;
				}


				if (new_i > 0 && new_i <= N && new_j > 0 && new_j <= M) {
					// 길이라면
					if (map[new_i][new_j] == 0) {
						if (!visited[new_i][new_j][temp.pass]) {
							visited[new_i][new_j][temp.pass] = true;
							q.push(qData(new_i, new_j, temp.pass));
						}
					}
					// 벽이라면 pass == false일 때 허물고
					// pass == false visit이 왔었는지 체크
					else if(temp.pass == false) {
						if (!visited[new_i][new_j][!temp.pass]) {
							visited[new_i][new_j][!temp.pass] = true;
							q.push(qData(new_i, new_j, !temp.pass));
						}
					}
				}

			}
			
			if(q.size())
				q.pop();
		}
		cnt++;

	}

	if (success)
		return cnt;
	else
		return -1;
}

int main() {

	cin >> N >> M;

	string s;

	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) 
			map[i][j] = s[j - 1] - '0';
	}

	cout << solution();
}