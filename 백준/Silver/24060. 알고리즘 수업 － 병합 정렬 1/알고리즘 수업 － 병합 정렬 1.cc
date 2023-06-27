#include <iostream>

using namespace std;

int A[500001] = { 0, };
int temp[500001] = { 0, };
int cnt = 0;
int N, K;

void merge(int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = 1;

	while (i <= mid && j <= end) {
		if (A[i] <= A[j]) {
			temp[k++] = A[i++];
		}
		else {
			temp[k++] = A[j++];
		}
	}

	while (i <= mid)
		temp[k++] = A[i++];

	while (j <= end)
		temp[k++] = A[j++];

	i = start;
	k = 1;

	while (i <= end) {

		if (++cnt == K)
			cout << temp[k];

		A[i++] = temp[k++];
	}
}

void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}

int main() {
	
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	merge_sort(1, N);

	if (cnt < K) {
		cout << -1;
	}
}