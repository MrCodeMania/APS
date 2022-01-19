#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int Max = INT32_MIN;
int Min = INT32_MAX;

void DFS(vector<int> Numbers, vector<int> Opers, vector<bool> Visited, int Value, int Time, int Index)
{
	Visited[Index] = true;

	if (Opers[Index] == 0) // +
		Value += Numbers[Time + 1];
	else if (Opers[Index] == 1) // -    
		Value -= Numbers[Time + 1];
	else if (Opers[Index] == 2) // *    
		Value *= Numbers[Time + 1];
	else if (Opers[Index] == 3) // /    
			Value /= Numbers[Time + 1];
	

	for (int i = 0; i < N - 1; i++)
	{
		if (!Visited[i])
			DFS(Numbers, Opers, Visited, Value, Time + 1, i);
	}

	if (Time == N - 2)
	{
		if (Max < Value)
			Max = Value;
		if (Min > Value)
			Min = Value;
		return;
	}
}

int main()
{
	cin >> N;

	vector<int> Numbers;
	vector<int> Opers;
	vector<bool> Visited;
	int Last = -1;

	for (int i = 0; i < N; i++)
	{
		int Temp;
		cin >> Temp;
		Numbers.push_back(Temp);
	}

	for (int i = 0; i < 4; i++)
	{
		int oper;
		cin >> oper;
		for (int j = 0; j < oper; j++)
		{
			Opers.push_back(i);
			Visited.push_back(false);
		}
	}

	for (int i = 0; i < Opers.size(); i++)
	{
		if (Last != Opers[i])
			DFS(Numbers, Opers, Visited, Numbers[0], 0, i);
		Last = Opers[i];
	}

	cout << Max << endl;
	cout << Min << endl;
}