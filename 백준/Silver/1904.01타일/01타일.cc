#include <string>
#include <iostream>

using namespace std;

long long Sequence[1000000];

int main()
{
	int N;
	cin >> N;

	Sequence[0] = 1;
	Sequence[1] = 2;

	for (int i = 2; i < N; i++)
	{
		Sequence[i] = Sequence[i-1] % 15746 + Sequence[i-2] % 15746;
	}

	cout << Sequence[N - 1] % 15746 << endl;
}