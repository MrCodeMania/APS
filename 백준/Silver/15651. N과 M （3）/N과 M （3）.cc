#include <iostream>

using namespace std;

int N, M;
int sequence[9] = { 0, };

void DFS(int size)
{
	if (size == M) {
		for (int i = 1; i <= M; i++) {
			cout << sequence[i] << " ";
		}
		
		cout << "\n";

		return;
	}
	
	for (int i = 1; i <= N; i++) {
		sequence[size + 1] = i;
		DFS(size + 1);
	}
}

int main() {
	cin >> N >> M;

	DFS(0);
}