#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Graph
{
private:
	vector<vector<int>> Array;
	int sizeA;
	int sizeB;
public:
	Graph(int asize, int bsize);
	int LetsGetit(string A, string B);
};

Graph::Graph(int asize, int bsize)
{
	this->sizeA = asize;
	this->sizeB = bsize;
	for (int i = 0; i < sizeA + 1; i++)
	{
		vector<int> Temp;
		Temp.resize(sizeB + 1);
		this->Array.push_back(Temp);
	}
}

int Graph::LetsGetit(string A, string B)
{
	int MaxCount = 0;

	for (int i = 0; i < this->sizeA + 1; i++)
	{
		for (int j = 0; j < this->sizeB + 1; j++)
		{
			if (i == 0 || j == 0)
				this->Array[i][j] = 0;
			else
			{
				if (A[i - 1] == B[j - 1])
					this->Array[i][j] = this->Array[i - 1][j - 1] + 1;
				else
				{
					this->Array[i][j] = this->Array[i - 1][j] < this->Array[i][j - 1] ? this->Array[i][j - 1] : this->Array[i - 1][j];
				}
			}
			if (MaxCount < this->Array[i][j])
				MaxCount = this->Array[i][j];
		}
	}

	return MaxCount;
}

int main()
{
	string InputA;
	string InputB;

	getline(cin, InputA, '\n');
	getline(cin, InputB, '\n');

	Graph X(InputA.size(),InputB.size());

	cout << X.LetsGetit(InputA, InputB);

	return 0;
}