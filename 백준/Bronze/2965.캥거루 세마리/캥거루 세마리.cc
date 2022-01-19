#include <iostream>
#include <vector>

using namespace std;

class Kangaroo
{
private:
	int Left = 0;
	int Center = 0;
	int Right = 0;
public:
	int Count = 0;
	Kangaroo();
	bool Jump();
};

Kangaroo::Kangaroo()
{

	for (int i = 0; i< 3; i++)
	{
		int n;
		cin >> n;

		if (n > this->Left)
			this->Left = n;

		if (this->Left > this->Center)
		{
			int Temp = this->Center;
			this->Center = Left;
			this->Left = Temp;
		}

		if (this->Center > this->Right)
		{
			int Temp = this->Right;
			this->Right = this->Center;
			this->Center = Temp;
		}
	}

	if (this->Left > this->Center)
	{
		int Temp = this->Center;
		this->Center = Left;
		this->Left = Temp;
	}

	if (this->Center > this->Right)
	{
		int Temp = this->Right;
		this->Right = this->Center;
		this->Center = Temp;
	}
}

bool Kangaroo::Jump()
{
	//왼쪽차클경우
	if ((this->Center - this->Left) >(this->Right - this->Center))
	{
		this->Right = this->Center;
		this->Center = this->Left + 1;
		this->Count++;
	}
	else if (((this->Center - this->Left) == 1) && ((this->Right - this->Center) == 1))
	{
		return false;
	}
	//오른차클경우
	else
	{
		this->Left = this->Center;
		this->Center = this->Right - 1;
		this->Count++;
	}
	return true;
}

int main()
{
	Kangaroo K;
	while (K.Jump())
	{
	}

	cout << K.Count;

	return 0;
}