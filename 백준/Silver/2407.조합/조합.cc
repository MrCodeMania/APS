#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Combination
{
private:
	vector<vector<int>> Answer;
	vector<int> Sum;
	int N;
	int M;
public:
	Combination(int n, int m);
	void Increase(int t);
	void GetSum(int t,int a, int b);
	void GetAnswer(int n, int m);
};

Combination::Combination(int n, int m)
{
	this->N = n;
	this->M = m;

	this->Sum.push_back(0);

	for (int i = 1; i <= 101; i++)
		Sum.push_back(Sum[i - 1] + i);

	int Count = 1;

	for (int i = 0; i < (Sum[100] + 101); i++)
	{
		if (Count != 101)
		{
			if (i == Sum[Count])
				Count++;
		}
		vector<int> Temp;
		Temp.resize(Count);
		this->Answer.push_back(Temp);
	}
}

void Combination::Increase(int t)
{
	for (int i = 0; i < this->Answer[t].size(); i++)
	{
		while(this->Answer[t][i] > 9)
		{
			this->Answer[t][i + 1]++;
			this->Answer[t][i] -= 10;
		}
	}
}

void Combination::GetSum(int t,int a, int b)
{
	for (int i = 0; i < Answer[a].size(); i++)
		Answer[t][i] = Answer[a][i] + Answer[b][i];
}

void Combination::GetAnswer(int n, int m)
{
	int Count = 1;
	for (int i = 1; i <= Sum[n]+m; i++)
	{
		
		if (i == Sum[Count] - 1)
		{
			Answer[i][0] = 1;
			continue;
		}
		else if (i == Sum[Count])
		{
			Count++;
			Answer[i][0] = 1;
			continue;
		}
		else
		{
			GetSum(i,i - Answer[i].size(), i - Answer[i].size() + 1);
			this->Increase(i);
		}
	}
	bool Flag = false;

	for (int i = this->Answer[Sum[n] + m].size() - 1; i >= 0; i--)
	{
		if (Answer[Sum[n]+m][i] != 0)
			Flag = true;
		if (Flag)
			cout << this->Answer[Sum[n]+m][i];
	}
}

int main()
{
	int n, m;

	cin >> n >> m;

	Combination C(n,m);
	C.GetAnswer(n,m);

	return 0;
}