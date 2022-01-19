#include <iostream>
#include <vector>

using namespace std;

class CoinClass
{
public:

	vector<int> CaseArray;
	vector<int> Coin;
	int Total;
	int Kind;
	int Least;

	CoinClass(int n);
	int GetCase();
};

CoinClass::CoinClass(int n)
{
	cin >> this->Total;
	this->Kind = n;
	this->Least = 10000;

	for (int i = 0; i < n; i++)
	{
		int input_coin;
		cin >> input_coin;

		if (input_coin <= this->Least)
			this->Least = input_coin;

		this->Coin.push_back(input_coin);
	}

	this->CaseArray.push_back(1);

	for(int i = 0; i < this->Total; i++)
		this->CaseArray.push_back(0);
}

int CoinClass::GetCase()
{
	for (int i = 0; i < this->Kind; i++)
	{		
		for (int j = 0; j <= this->Total; j++)
		{
			if (this->Coin[i] <= j)
				this->CaseArray[j] += this->CaseArray[j - this->Coin[i]];

		}
	}
	return CaseArray[this->Total];
}

int main()
{
	int Num;
	cin >> Num;

	CoinClass C(Num);

	cout << C.GetCase();

	return 0;
}