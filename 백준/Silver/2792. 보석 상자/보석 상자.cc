#include <iostream>
#include <vector>

using namespace std;

int v[300000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int maxV = 0;

	for (int i = 0; i < M; i++) {
		cin >> v[i];	
		if (maxV < v[i]) maxV = v[i];
	}

	int left = 1;
	int right = maxV;
	int jeal = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < M; i++) {
			cnt += v[i] / mid;
			if (v[i] % mid) {
				cnt++;
			}
		}

		if (cnt <= N) {
			right = mid - 1;
			jeal = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << jeal;

}