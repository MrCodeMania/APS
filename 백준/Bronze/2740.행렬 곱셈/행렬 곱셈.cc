#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M, K;
	vector<vector<int>> NM;
	vector<vector<int>> MK;
	vector<vector<int>> NK;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		vector<int> Temp;
		for (int j = 0; j < M; j++)
		{
			int Input;
			cin >> Input;
			Temp.push_back(Input);
		}
		NM.push_back(Temp);
	}

	cin >> M >> K;

	for (int i = 0; i < M; i++)
	{
		vector<int> Temp;
		for (int j = 0; j < K; j++)
		{
			int Input;
			cin >> Input;
			Temp.push_back(Input);
		}
		MK.push_back(Temp);
	}

	for (int i = 0; i < N; i++)
	{
		vector<int> Temp;
		for (int j = 0; j < K; j++)
		{
			int Mul = 0;

			for (int l = 0; l < M; l++)
			{
				Mul += NM[i][l] * MK[l][j];
			}
			Temp.push_back(Mul);
		}
		NK.push_back(Temp);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << NK[i][j] << " ";
		}
		cout << endl;
	}
}