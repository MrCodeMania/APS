#include <iostream>
#include <vector>

using namespace std;


class Cycle
{
private:
	vector<int> Relation;
	int Count = 0;
public:
	Cycle(int n);
	void BFS(int target, int destination);
	int GetNumber(int index);
	void Print();
};

Cycle::Cycle(int n)
{
	for (int i = 0; i < n; i++)
	{
		int Temp;
		cin >> Temp;
		this->Relation.push_back(Temp);
	}
}

void Cycle::BFS(int target, int destination)
{
	if (target < 0)
		return;

	int t_temp = this->Relation[target] - 1;

	this->Relation[target] = -1;

	if (t_temp == destination)
		this->Count += 1;
	else
		BFS(t_temp, destination);
}

int Cycle::GetNumber(int index)
{
	return this->Relation[index];
}

void Cycle::Print()
{
	cout << this->Count << endl;
}

int main()
{
	int iTestCase;
	cin >> iTestCase;

	while (iTestCase--)
	{
		int N;
		cin >> N;

		Cycle C(N);
		
		for (int j = 0; j < N; j++)
			C.BFS(C.GetNumber(j) - 1, j);

		C.Print();
	}
}