#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int TestCase;
	cin >> TestCase;

	while (TestCase--)
	{
		int Stick, Ant;
		cin >> Stick >> Ant;

		vector<pair<int, int>> Ants;
		for (int i = 0; i < Ant; i++)
		{
			int t;
			cin >> t;
			pair<int, int> Temp = make_pair(t, t);
			Temp.first = (Temp.first - 0);
			Temp.second = (Stick - Temp.second);
			
			if (Temp.first >= Temp.second)
			{
				int swap = Temp.first;
				Temp.first = Temp.second;
				Temp.second = swap;
			}
			
			Ants.push_back(Temp);
		}

		int Least = Ants[0].first;
		int Most = Ants[0].second;

		for (int i = 0; i < Ant; i++)
		{
			if(Least <= Ants[i].first)
				Least = Ants[i].first;
			if (Most <= Ants[i].second)
				Most = Ants[i].second;
		}

		cout << Least << " "<< Most << endl;
	}
}