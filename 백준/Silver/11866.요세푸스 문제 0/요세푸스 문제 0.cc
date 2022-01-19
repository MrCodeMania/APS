#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	
	vector<int> Josephus;
	int Remove[1000] = { false, };

	int Index = -1;

	for (int i = 0; i < N; i++)
		Josephus.push_back(i + 1);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			Index = (Index + 1) % N;
			while (Remove[Index])
				Index = (Index + 1) % N;
		}
		if (i == 0)
			cout << "<" << Josephus[Index];
		else
			cout << ", " << Josephus[Index];

		if (i == N - 1)
			cout << ">";

		Remove[Index] = true;
	}
}