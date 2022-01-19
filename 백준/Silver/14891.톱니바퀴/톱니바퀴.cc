#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Gear
{
private:
	int Status[8];
	int Top = 0;
	int Right = 2;
	int Left = 6;
public:
	Gear();
	int GetLeft();
	int GetRight();
	int GetScore();
	void Clockwise(int clockwise);
};

Gear::Gear()
{
	string sInput;
	cin >> sInput;
	
	for (int i = 0; i < 8; i++)
		this->Status[i] = sInput[i] - '0';
}

int Gear::GetLeft()
{
	return this->Status[this->Left];
}

int Gear::GetRight()
{
	return this->Status[this->Right];
}

int Gear::GetScore()
{
	return this->Status[this->Top];
}

void Gear::Clockwise(int clockwise)
{
	if (clockwise == 1)
	{
		if (--this->Right == -1)
			this->Right = 7;
		if (--this->Left == -1)
			this->Left = 7;
		if (--this->Top == -1)
			this->Top = 7;
	}

	else
	{
		if (++this->Right == 8)
			this->Right = 0;
		if (++this->Left == 8)
			this->Left = 0;
		if (++this->Top == 8)
			this->Top = 0;
	
	}
}

void Rotate(Gear g[], int num, int dir, bool visit[])
{
	visit[num] = true;

	if (num > 0)
	{
		if (!visit[num - 1] && g[num].GetLeft() != g[num - 1].GetRight())
			Rotate(g, num - 1, -dir, visit);
	}
	if (num < 3)
	{
		if (!visit[num + 1] && g[num].GetRight() != g[num + 1].GetLeft())
			Rotate(g, num + 1, -dir, visit);
	}

	g[num].Clockwise(dir);
}

int main()
{
	Gear Gears[4];

	int K;
	cin >> K;

	while (K--)
	{
		int Number, Dir;
		cin >> Number >> Dir;

		bool Visit[4] = { false, };

		Rotate(Gears, Number - 1, Dir, Visit);
	}

	int Sum = 0;
	for (int i = 0; i < 4; i++)
		Sum += Gears[i].GetScore() * pow(2,i);

	cout << Sum << endl;
}