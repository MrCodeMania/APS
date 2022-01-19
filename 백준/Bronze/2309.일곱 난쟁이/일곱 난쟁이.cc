#include <iostream>

using namespace std;

int main()
{
	int Men[9];
	int Sum = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> Men[i];
		Sum += Men[i];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != j)
			{
				if (Sum - Men[i] - Men[j] == 100)
				{
					Men[i] = 99999;
					Men[j] = 99999;
                    i=10;
                    break;
				}
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		int least = i;
		for (int j = i + 1; j < 9; j++)
		{
			if (Men[least] >= Men[j])
				least = j;
		}
		int Temp = Men[i];
		Men[i] = Men[least];
		Men[least] = Temp;
	}

	for (int i = 0; i < 9; i++)
	{
		if (Men[i] != 99999)
			cout << Men[i] << endl;
	}
}
