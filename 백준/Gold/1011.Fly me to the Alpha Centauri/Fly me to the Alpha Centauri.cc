#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;

	vector<long long> Slot;

	long long T = 0;
	long long Two = 2;

	for (long long i = 1; T < 4294967296; i++)
	{
		T += Two *i;

		Slot.push_back(T);
	}
	

	while (testcase--)
	{
		long long x, y;
		cin >> x >> y;

		long long diff = y - x;

		if (diff == 0)
			cout << 0 << endl;
		else
		{
			int i;
			for (i = 0; i < Slot.size(); i++)
			{
				if (diff <= Slot[i])
					break;
			}
			if (diff > Slot[i] - (i + 1))
				cout << (i+1) * 2 << endl;
			else
				cout << (i+1) * 2 - 1 << endl;
		}
		
	}
}