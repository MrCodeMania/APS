#include <iostream>

using namespace std;

int return_Min(int a, int b, int c);

int main()
{
	int **RGBstreet;
	
	int N;

	cin >> N;

	RGBstreet = new int*[N];
	for (int i = 0; i < N; i++)
		RGBstreet[i] = new int[3];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> RGBstreet[i][j];

	for (int i = 1; i < N; i++)
	{
		RGBstreet[i][0] += (RGBstreet[i - 1][1] <= RGBstreet[i - 1][2]) ? RGBstreet[i - 1][1] : RGBstreet[i - 1][2];
		RGBstreet[i][1] += (RGBstreet[i - 1][2] <= RGBstreet[i - 1][0]) ? RGBstreet[i - 1][2] : RGBstreet[i - 1][0];
		RGBstreet[i][2] += (RGBstreet[i - 1][1] <= RGBstreet[i - 1][0]) ? RGBstreet[i - 1][1] : RGBstreet[i - 1][0];
	}

	cout << return_Min(RGBstreet[N - 1][0], RGBstreet[N - 1][1], RGBstreet[N - 1][2]);

	return 0;
}

int return_Min(int a, int b, int c)
{
	return c <= ((a <= b) ? a : b) ? c : ((a <= b) ? a : b);
}