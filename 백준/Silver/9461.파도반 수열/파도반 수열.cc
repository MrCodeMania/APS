#include <iostream>
#include <vector>

using namespace std;

class Spiral
{
private:
	vector<unsigned long long> DP;
public:
	Spiral();
	unsigned long long Get(int n);
};

Spiral::Spiral()
{
	for (int i = 0; i < 100; i++)
		this->DP.push_back((unsigned long long)0);

	this->DP[0] = 1; this->DP[1] = 1; this->DP[2] = 1;
	this->DP[3] = 2; this->DP[4] = 2;
	for (int i = 5; i < 100; i++)
	{
		this->DP[i] = this->DP[i - 1] + this->DP[i - 5];
	}
}

unsigned long long Spiral::Get(int n)
{
	return this->DP[n - 1];
}

int main()
{
	int TestCase;
	cin >> TestCase;

	while (TestCase--)
	{
		int s;
		cin >> s;

		Spiral S;

		cout << S.Get(s) << endl;
	}
	return 0;
}