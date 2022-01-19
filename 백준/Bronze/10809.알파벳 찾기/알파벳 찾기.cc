#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);

	string Input;
	getline(cin,Input);

	int Count[26] = { 0, };
	bool Visited[26] = { false, };

	Count[Input[0] - 97] = -1;
	Visited[Input[0] - 97] = true;

	for (int i = 1; i < Input.size(); i++)
	{
		if (Visited[Input[i] - 97])
			continue;
		else
		{
			Visited[Input[i] - 97] = true;
			Count[Input[i] - 97] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (Count[i] == 0)
			cout << "-1 ";
		else if (Count[i] == -1)
			cout << "0 ";
		else
			cout << Count[i] << " ";
	}

	return 0;
}