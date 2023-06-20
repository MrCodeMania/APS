#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool num[1000001] = { false, };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	num[1] = true;

	for (int i = 2; i <= 1000; i++) {
		if (num[i]) continue;
		for (int j = 2; i * j < 1000000; j++) {
			num[i * j] = true;
		}
	}

	map<int, bool> m;
	vector<int> prime;

	for (int i = 1; i < 1000000; i++) {
		if (!num[i]) {
			m[i] = true;
			prime.push_back(i);
		}
	}

	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;

		int cnt = 0;

		for (int j = 0; prime[j] <= N / 2; j++) {
			if (m.find(N - prime[j]) != m.end()) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
}