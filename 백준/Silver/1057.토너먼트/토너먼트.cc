#include <iostream>

using namespace std;

int main()
{
	int Fighter[100000];
	int N, A, B;
	cin >> N >> A >> B;
	int Last = -1;
	int Round = 1;

	for (int i = 0; i < N; i++)
		Fighter[i] = 1;

	for (int i = 0; i < N; i++)
	{
		if (Last > -1 && Fighter[i] == 1)
		{
			if ((Last == A-1 && i == B-1) || (Last == B-1 && i == A-1))
				break;
			else if (Last == A-1 || Last == B-1)
			{
				Fighter[Last] = 1;
				Fighter[i] = 0;
			}
			else if (i == A-1 || i == B-1)
			{
				Fighter[Last] = 0;
				Fighter[i] = 1;
			}
			else
			{
				Fighter[Last] = 1;
				Fighter[i] = 0;
			}
			Last = -1;
		}
		else if (Fighter[i] == 1)
			Last = i;
		
		if (i == N - 1)
		{
			i = -1;
			Last = -1;
			Round++;
		}
	}

	cout << Round;
}