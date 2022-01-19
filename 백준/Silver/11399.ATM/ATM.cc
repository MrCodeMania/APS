#include <iostream>

using namespace std;

void QuickSort(int *arr, int left, int right, int size);

int main()
{
	int N;
	cin >> N;
	int Size = N;

	int Time[1000];

	while (N)
	{
		int Temp;
		cin >> Temp;
		Time[N-1] = Temp;
		N--;
	}
	
	for (int i = 0; i < Size; i++)
	{
		int Least = Time[i];
		int Leastj = 0;
		for (int j = i; j < Size; j++)
		{
			if (Least >= Time[j])
			{
				Leastj = j;
				Least = Time[j];
			}
		}
		int Temp = Time[i];
		Time[i] = Time[Leastj];
		Time[Leastj] = Temp;
	}

	for (int i = 1; i < Size; i++)
		Time[i] += Time[i - 1];

	int Sum = 0;

	for (int i = 0; i < Size; i++)
		Sum += Time[i];

	cout << Sum;
}

