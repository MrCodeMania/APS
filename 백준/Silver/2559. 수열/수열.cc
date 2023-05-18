#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	int maxV = -99999999;

	vector<int> nums(N + 1, 0);
	vector<int> sums(N + 1, 0);

	for (int i = 1; i <= N; i++){
		cin >> nums[i];
	}

	for (int i = 1; i <= K; i++) {
		sums[K] += nums[i];
	}

	for (int i = K; i <= N; i++) {
		
		if (i != K) {
			sums[i] = nums[i] + sums[i - 1] - nums[i - K];
		}

		if (sums[i] > maxV) {
			maxV = sums[i];
		}
	}

	cout << maxV;

	return 0;
}