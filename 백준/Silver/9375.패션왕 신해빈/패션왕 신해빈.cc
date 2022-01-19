#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FashionKing
{
private:
	vector<string> Fashion;
	vector<long long> NumberofSort;
public:
	FashionKing(int n);
	long long GetAnswer();
};

FashionKing::FashionKing(int n)
{
	this->Fashion.push_back("null");
	this->NumberofSort.push_back(0);

	for (int i = 0; i < n; i++)
	{
		string Name;
		string Wear;
		cin >> Name >> Wear;
		for (int j = 0; j < this->Fashion.size(); j++)
		{
			if (this->Fashion[j] == Wear)
			{
				this->NumberofSort[j]++;
				break;
			}
			if (j == this->Fashion.size() - 1)
			{
				this->Fashion.push_back(Wear);
				this->NumberofSort.push_back(1);
				break;
			}
		}
	}
}

long long FashionKing::GetAnswer()
{
	long long Sum = 1;

	for (int i = 1; i < this->NumberofSort.size(); i++)
		Sum *= (long long)(this->NumberofSort[i] + 1);



	return (Sum - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);

	int TestCase;
	cin >> TestCase;

	while (TestCase--)
	{
		int Num;
		cin >> Num;

		FashionKing F(Num);
		if (Num == 0)
			cout << Num << endl;
		else
			cout << F.GetAnswer() << endl;
	}

	return 0;
}