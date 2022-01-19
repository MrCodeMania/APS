#include <iostream>
#include <string>

using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	cin.ignore();
	while (testcase--)
	{
		string Input;
		getline(cin, Input, '\n');

		int Sum = 0;
		int Count = 1;

		for (int i = 0; i < Input.size(); i++)
		{
			if (Input[i] == 'O')
			{
				Sum = Sum + Count;
				Count++;
			}
			else if (Input[i] == 'X')
			{
				Count = 1;
			}
		}

		cout << Sum << endl;
	}
	return 0;
}