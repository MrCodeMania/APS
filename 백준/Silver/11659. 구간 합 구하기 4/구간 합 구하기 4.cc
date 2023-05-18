#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> sums(N + 1, 0);
	for (int i = 1; i <= N; i++){
		cin >> sums[i];
		sums[i] += sums[i - 1];
	}

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int t = 0; t < M; t++) {
		int i, j;
		cin >> i >> j;

		cout << sums[j] - sums[i - 1] << "\n";
	}

	return 0;
}