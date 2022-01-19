#include <iostream>
#include <string>

using namespace std;

int main()
{
	string N;
	getline(cin, N, '\n');

	int Digit[9] = { 0, };

	for (int i = 0; i < N.size(); i++)
	{
		if (N[i] - '0' == 6 || N[i] - '0' == 9)
			Digit[6]++;
		else
			Digit[N[i] - '0']++;
	}

	Digit[6] = (Digit[6] + 1) / 2;

	int Set = 0;

	for (int i = 0; i < 9; i++)
	{
		if (Digit[i] >= Set)
			Set = Digit[i];
	}

	cout << Set;
}