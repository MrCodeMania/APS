#include <iostream>
#include <vector>

using namespace std;

class Sequence
{
private:
	vector<int> Vector;
	int N;
	int L;
public:
	Sequence(int n, int l);
	void GetSequence();
};

Sequence::Sequence(int n, int l)
{
	this->N = n;
	this->L = l;
	for (int i = 0; i < 100; i++)
		this->Vector.push_back(0);
}

void Sequence::GetSequence()
{
	if (this->N % 2 == 1 && this->L <= 2)
	{
		this->Vector[0] = this->N / 2;
		this->Vector[1] = this->Vector[0] + 1;

		cout << this->Vector[0] << " " << this->Vector[1] << " ";
	}
	else
	{
		int Count = 0;
		bool IsOk = false;

		for (int i = 2; i <= 100; i++)
		{
			if (this->N < i)
				break;
			int Center = this->N / i;
			int Sum = Center;
			Count = 0;
			IsOk = false;
			for (int j = 1; j <= ((i % 2 == 0) ? (i / 2) - 1 : i / 2); j++)
			{
				if (Center - j >= 0)
				{
					Sum += Center - j;
					this->Vector[Count++] = Center - j;
				}
				else break;
			}
			this->Vector[Count++] = Center;
			for (int j = 1; j <= i / 2; j++)
			{
				Sum += Center + j;
				this->Vector[Count++] = Center + j;
			}
			if (Sum == this->N && Count >= this->L)
			{
				IsOk = true;
				break;
			}
		}
		if (!IsOk)
			cout << "-1";
		else
		{
			int i = 0;
			int j = 0;

			if (Count % 2 == 0)
			{
				i = (Count / 2) - 2;
				j = (Count / 2) - 1;
			}
			else
			{
				i = (Count / 2) - 1;
				j = (Count / 2);
			}

			for (; i >= 0; i--)
				cout << this->Vector[i] << " ";
			for (; j < Count; j++)
				cout << this->Vector[j] << " ";
		}
	}
}

int main()
{
	int N, L;
	cin >> N >> L;

	Sequence S(N, L);

	S.GetSequence();
}