#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Rope
{
private:
	int Ropes[100000];
	int N;
public:
	Rope(int n);
	int GetAnswer();
};

Rope::Rope(int n)
{
    this->N = n;
	for (int i = 0; i < this->N; i++)
	{
		int Temp;
		cin >> Temp;
		Ropes[i] = Temp;
	}
}

int Rope::GetAnswer()
{
	int Most = 0;

	sort(Ropes,Ropes+N);
    
	for (int i = 0; i < this->N; i++)
	{
		Ropes[i] = Ropes[i] * (this->N - i);

		if (Most < Ropes[i])
			Most = Ropes[i];
	}

	return Most;
}

int main()
{
	int N;
	cin >> N;

	Rope R(N);
	cout << R.GetAnswer();
}