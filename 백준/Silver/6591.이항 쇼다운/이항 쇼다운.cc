#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k;

	while (true) {
		scanf("%d %d", &n, &k);
		if (n == 0 && k == 0)
			break;

		long long answer = 1;
		
		k = min(k, n - k);
		for (int i = 1; i <= k; i++)
		{
			answer *= n;
			answer /= i;
			n--;
		}

		printf("%d\n", answer);
	}
}