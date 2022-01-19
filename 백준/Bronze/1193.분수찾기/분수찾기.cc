#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> Sum;
	Sum.push_back(0);

	for (int i = 1; Sum[i - 1] < 10000000; i++)
		Sum.push_back(Sum[i - 1] + i);

	int X;
	cin >> X;

	int Start = 0;

	for (int i = 1; Sum[i - 1] < 10000000; i++)
	{
		if (Sum[i - 1] < X && X <= Sum[i])
		{
			X -= Sum[i - 1] + 1;
			Start = i;
			break;
		}
	}

	if (Start % 2 == 1)
	{
		cout << Start - X << "/" << 1 + X  ;
	}
	else
	{
		cout << 1 + X << "/" << Start - X;
	}
}