#include <iostream>

using namespace std;

void GetSelf(int Num[], bool bNum[]);

int main()
{
	int Num[10000];
	bool bNum[10000] = { true };

	for (int i = 0; i < 10000; i++)
		Num[i] = i + 1;

	for (int i = 0; i < 10000; i++)
		bNum[i] = true;
	GetSelf(Num, bNum);
}

void GetSelf(int Num[], bool bNum[])
{

	for (int i = 0; i < 10000; i++)
	{
		int Sum = Num[i];
		int Temp = Num[i];
		if (Temp >= 1000)
		{
			Sum += Temp / 1000;
			Temp %= 1000;
		}
		if (Temp >= 100)
		{
			Sum += Temp / 100;
			Temp %= 100;
		}
		if (Temp >= 10)
		{
			Sum += Temp / 10;
			Temp %= 10;
		}
		Sum += Temp;

		if (Sum <= 10000)
			bNum[Sum - 1] = false;
	}

	for (int i = 0; i < 10000; i++)
	{
		if (bNum[i])
			cout << Num[i] << endl;
	}
}