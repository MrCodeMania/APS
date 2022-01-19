#include <iostream>
#include <vector>

using namespace std;

int N;
int consult[15][2];
int profit = 0;

void DFS(vector<bool> On, int index)
{
	int P = 0;

	if (index == N)
	{
		P = 0;
		for (int i = 0; i < N; i++)
		{
			if (On[i])
				P += consult[i][1];
		}

		if (P > profit)
			profit = P;

		return;
	}

	if (consult[index][0] == 1)
		DFS(On, index + 1);

	for (int i = 0; i < N; i++)
	{
		if (On[i])
			P += consult[i][1];
	}

	if (P < profit)
		return;

	if (consult[index][0] + index > N)
	{
		//끄는것
		On[index] = 0;
		DFS(On, index + 1);
		return;
	}
	
	//끄는것
	On[index] = 0;
	DFS(On, index + 1);

	//키는것
	On[index] = 1;
	for (int i = index + 1; i < index + consult[index][0] && i < N; i++)
		On[i] = 0;
	
	if (index + consult[index][0] < N)
		DFS(On, index + consult[index][0]);
	else
		DFS(On, N);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> consult[i][0];
		cin >> consult[i][1];
	}
	
	vector<bool> On(N, 1);

	DFS(On, 0);

	cout << profit << endl;
}