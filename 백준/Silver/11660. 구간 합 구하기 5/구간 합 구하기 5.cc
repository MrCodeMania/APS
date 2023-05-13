#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	int N, M;
	cin >> N >> M;

	vector<vector<int>> table(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> table[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			table[i][j] += table[i][j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			table[j][i] += table[j - 1][i];
		}
	}

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
                              
	while (M--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int prefixSum = table[x2][y2] - table[x1 - 1][y2] - table[x2][y1 - 1] + table[x1 - 1][y1 - 1];

		cout << prefixSum << "\n";
	}

	return 0;
}