#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		vector<int> Score;

		float Num;
		cin >> Num;

		float Sum = 0;
		for (int i = 0; i < Num; i++)
		{
			int input;
			cin >> input;
			Score.push_back(input);
			Sum += input;
		}

		float Count = 0;

		for (int i = 0; i < Num; i++)
		{
			if (Score[i] >(Sum / Num))
				Count++;
		}

		cout << fixed;
		cout.precision(3);
		cout << (Count * 100 / Num) << "%" << endl;
	}
}