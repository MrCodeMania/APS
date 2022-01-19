#include <iostream>
#include <vector>

using namespace std;

class Number
{
private:
	vector<int> Array;
	long long Sum;
public:
	Number();
	void GetValue();
};

Number::Number()
{
	this->Sum = 1;
	for (int i = 0; i < 3; i++)
	{
		int X;
		cin >> X;

		this->Sum *= X;
	}

	int Temp[10] = { 0,0,0,0,0,0,0,0,0,0 };
	this->Array.assign(Temp, Temp + 10);
}

void Number::GetValue()
{
	for (int i = 10; this->Sum > 0; this->Sum /= 10)
	{
		int Num = this->Sum % i;
		this->Array[Num]++;
	}

	for (int i = 0; i < 10; i++)
		cout << this->Array[i] << endl;
}

int main()
{
	Number N;

	N.GetValue();

	return 0;
}