#include <iostream>

using namespace std;

int main()
{
	int Input;
	cin >> Input;

	while (Input != 0)
	{
		bool Array[246913];
		int Count = 0;

		for (int i = 0; i < 246913; i++)
		{
			Array[i] = true;
		}

		for (int i = 2; i <= Input; i++)
		{
			for (int j = 2; i * j <= Input * 2; j++)
			{
				if (i * j > Input)
					Array[i*j] = false;
			}
		}

		for (int i = Input + 1; i <= Input * 2; i++)
		{
			if (Array[i])
				Count++;
		}

		cout << Count << endl;

		cin >> Input;
	}
}

