#include <iostream>

using namespace std;

enum DAY { SUN, MON, TUE, WED, THU, FRI, SAT };

int main()
{
	int Calendar[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int x; int y;
	cin >> x >> y;
	
	int Day = SUN;
	
	for (int i = 0; i < x - 1; i++)
		Day += Calendar[i];
	Day += y;
	Day %= 7;

	switch (Day)
	{
		case SUN: cout << "SUN"; break;
		case MON: cout << "MON"; break;
		case TUE: cout << "TUE"; break;
		case WED: cout << "WED"; break;
		case THU: cout << "THU"; break;
		case FRI: cout << "FRI"; break;
		case SAT: cout << "SAT"; break;
	}

	return 0;
}