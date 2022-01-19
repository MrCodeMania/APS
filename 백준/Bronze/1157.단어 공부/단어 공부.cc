#include <iostream>

using namespace std;

int main()
{
	int Alphabet[26] = { 0, };
	char Input[1000001];
	cin >> Input;

	for (int i = 0; Input[i] != NULL; i++)
	{
		if (Input[i] >= 'a')
			Alphabet[(int)(Input[i] - 'a')]++;
		else if (Input[i] >= 'A')
			Alphabet[(int)(Input[i] - 'A')]++;
		else
			continue;
	}

	int Most = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (Most == j)
				continue;
			else if (Alphabet[Most] <= Alphabet[j])
			{
				Most = j;
				if (i > 0)
				{
					Most = -1;
					break;
				}
			}
		}
	}

	if (Most == -1)
		cout << "?" << endl;
	else
		cout << (char)(Most+'A') << endl;
}