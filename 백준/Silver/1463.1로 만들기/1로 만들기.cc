#include <iostream>
#include <vector>

#define MAX_SIZE 1000000

using namespace std;

int main()
{
	vector<int> CalcTimes(MAX_SIZE);

	int nInput;

	cin >> nInput;

	CalcTimes[0] = 0;
	CalcTimes[1] = 0;
	CalcTimes[2] = 1;
	CalcTimes[3] = 1;
	CalcTimes[4] = 2;
	CalcTimes[5] = 3;
	CalcTimes[6] = 2;

	for (int Num = 7; Num <= nInput; Num++)
	{
		int Least = MAX_SIZE;
		
		if (((Num % 3) == 0))
		{
			if (Least >= CalcTimes[Num / 3] + 1)
				Least = CalcTimes[Num / 3] + 1;
		}
		if ((Num % 2) == 0)
		{
			if (Least >= CalcTimes[Num / 2] + 1)
				Least = CalcTimes[Num / 2] + 1;
		}

		if (Least >= CalcTimes[Num - 1] + 1)
			Least = CalcTimes[Num - 1] + 1;

		CalcTimes[Num] = Least;
	}

	cout << CalcTimes[nInput];

	return 0;
}