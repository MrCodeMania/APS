#include <iostream>
#include <vector>

using namespace std;

class Stairs
{
public:
	Stairs(int N);
	int Calc();
	vector<vector<int>> Space;
	int HowManyStairs;
};

Stairs::Stairs(int N)
{
	this->HowManyStairs = N;

	for (int i = 0; i < this->HowManyStairs; i++)
	{
		vector<int> Temp;
		Temp.resize(10);
		this->Space.push_back(Temp);
	}
}

int Stairs::Calc()
{
	int Sum = 0;

	this->Space[0][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		this->Space[0][i] = 1;
		Sum += this->Space[0][i];
	}

	for (int i = 1; i < this->HowManyStairs; i++)
	{
		Sum = 0;

		for (int j = 0; j < 10; j++)
		{
			if(j == 0)
				this->Space[i][0] = this->Space[i - 1][1] % 1000000000;
			else if(j == 9)
				this->Space[i][9] = this->Space[i - 1][8] % 1000000000;
			else
				this->Space[i][j] = (this->Space[i - 1][j - 1] + this->Space[i - 1][j + 1]) % 1000000000;
			
			Sum %= 1000000000;
			Sum += this->Space[i][j];
		}
	}
	return Sum %= 1000000000;
}

int main()
{
	int n;
	cin >> n;

	if (n > 0)
	{
		Stairs X(n);
		cout << X.Calc();
	}
	else
		cout << 0;
}