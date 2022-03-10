#include <iostream>
#include <string>

using namespace std;

string dp[2][1001] = { "", };

int last = 1;

int main() {

	string a, b;

	getline(cin, a);
	getline(cin, b);

	/*
	  [A C A Y K P]
	[C 0 1 0 0 0 0
	[A 1 1 2 0 0 0
	[P 1 1 1 1 0 0
	[C 1 2
	[A     3
	[K       4
	*/

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				if (last == 1)
					dp[1][j] = dp[0][j - 1] + a[i - 1];
				else
					dp[0][j] = dp[1][j - 1] + a[i - 1];
			}
			else {
				if (last == 1)
					dp[1][j] = dp[1][j - 1].size() < dp[0][j].size() ? dp[0][j] : dp[1][j - 1];
				else
					dp[0][j] = dp[0][j - 1].size() < dp[1][j].size() ? dp[1][j] : dp[0][j - 1];
			}

		}
		last++;
		last %= 2;
	}

	string t = "";

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (t.size() < dp[i][j].size())
				t = dp[i][j];
		}
	}

	if (t.size() == 0)
		cout << t.size();
	else
		cout << t.size() << endl << t;

	return 0;

}