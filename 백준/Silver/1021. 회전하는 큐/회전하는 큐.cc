#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int level[51] = { 0, };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	deque<int> dq(N, 0);
	
	for (int i = 1; i <= N; i++) {
		dq[i - 1] = i;
	}

	int start = 0;
	int sum = 0;

	for (int i = 0; i < M; i++) {
		int target;
		cin >> target;

		if (target == dq.front()) {
			dq.pop_front();
			continue;
		}

		deque<int> lTemp = dq;
		deque<int> rTemp = dq;

		int lCount = 0;
		int rCount = 0;
		
		for (int j = 0; j < rTemp.size(); j++) {
			int front = rTemp.front();
			if (front == target) {
				rCount = j;
				break;
			}
			rTemp.pop_front();
			rTemp.push_back(front);
		}

		for (int j = 0; j < lTemp.size(); j++) {
			int front = lTemp.front();
			if (front == target) {
				lCount = j;
				break;
			}
			lTemp.push_front(lTemp.back());
			lTemp.pop_back();
		}

		if (lCount < rCount) {
			dq = lTemp;
			sum += lCount;
		}
		else {
			dq = rTemp;
			sum += rCount;
		}

		dq.pop_front();
	}

	cout << sum;
	
}