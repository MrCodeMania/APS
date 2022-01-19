#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A;
	int DP_L[1000] = { 0, };
	int DP_R[1000] = { 0, };
	
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		A.push_back(temp);
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (A[i] < A[j])
				DP_R[j] = DP_R[i] + 1 > DP_R[j] ? DP_R[i] + 1 : DP_R[j];
		}
	}

	for (int i = N - 1; i > 0; i--)
	{

		for (int j = i - 1; j >= 0; j--)
		{
			if (A[i] < A[j])
				DP_L[j] = DP_L[i] + 1 > DP_L[j] ? DP_L[i] + 1 : DP_L[j];
		}
	}

	int Max = 0;

	for (int i = 0; i < N; i++)
	{
		if (Max < DP_L[i] + DP_R[i])
			Max = DP_L[i] + DP_R[i];
	}

	cout << Max + 1 << endl;

}