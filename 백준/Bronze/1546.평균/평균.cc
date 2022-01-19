#include <iostream>
#include <vector>

using namespace std;

int main()
{
	float Num;
	cin >> Num;

	vector<float> Score;

	float Max = 0;

	for (int i = 0; i < Num; i++)
	{
		float temp;
		cin >> temp;

		if (temp >= Max)
			Max = temp;

		Score.push_back(temp);
	}

	float Sum = 0;

	for (int i = 0; i < Num; i++)
	{
		Score[i] = (Score[i] / Max) * 100;
		Sum += Score[i];
	}

	cout << fixed;
	cout.precision(2);

	cout << Sum / Num;

}