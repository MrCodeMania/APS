#include <iostream>

using namespace std;

int main()
{
	int Target;
	cin >> Target;

	for (int i = 1; i <= Target; i++)
	{
		if (i == Target)
		{
			Target = 0;
			break;
		}

		int Sum = 0;
		Sum += i;
		int Temp = i;
		while (Temp > 0)
		{
			Sum += Temp % 10;
			Temp /= 10;
		}

		if (Sum == Target)
		{
			Target = i;
			break;
		}
	}

	cout << Target;
}