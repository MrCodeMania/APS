#include <iostream>

using namespace std;

int N, M;
bool visited[9] = { false, };
int sequence[9] = { 0, };

void DFS(int idx, int size)
{
	if (size == M) {
		for (int i = 1; i <= M; i++) {
			cout << sequence[i] << " ";
		}
		
		cout << "\n";

		return;
	}
	
	for (int i = idx; i <= N; i++) {

		if (!visited[i]) {
			visited[i] = true;
			sequence[size + 1] = i;
			DFS(i + 1, size + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	DFS(1, 0);
}