#include <iostream>

using namespace std;

int dp[71][71][71];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i <= 70; i++) {
		for (int j = 0; j <= 70; j++) {
			for (int k = 0; k <= 70; k++) {
				if (i <= 50 || j <= 50 || k <= 50) {
					dp[i][j][k] = 1;
				}
				else if (i < j && j < k) {
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				}
				else {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		int val;

		if (a <= 0 || b <= 0 || c <= 0) {
			val = 1;
		}
		else if (a > 20 || b > 20 || c > 20) {
			val = dp[70][70][70];
		}
		else {
			val = dp[a + 50][b + 50][c + 50];
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << val << "\n";
	}
}