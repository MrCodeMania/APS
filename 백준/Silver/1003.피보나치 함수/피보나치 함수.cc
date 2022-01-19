#include <iostream>

using namespace std;

int main()
{
	int iTestCase;
	cin >> iTestCase;

	while (iTestCase--)
	{
		int Count_Zero[41] = { 1,0, };
		int Count_One[41] = { 0,1, };

		int N;
		cin >> N;

		for (int i = 2; i < 41; i++)
		{
			if (N < i)
				break;
			Count_Zero[i] = Count_Zero[i - 2] + Count_Zero[i - 1];
			Count_One[i] = Count_One[i - 2] + Count_One[i - 1];
		}

		cout << Count_Zero[N] << " " << Count_One[N] << endl;
	}
}