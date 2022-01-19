#include <iostream>
#include <vector>

using namespace std;

class Swirl
{
private:
	vector<vector<int>> Vector;
	int R_Size;
	int C_Size;
public:
	Swirl(int r1, int c1, int r2, int c2);
	int GetMax();
	int GetSum(int n);
	void GetSwirl(int r1, int c1, int r2, int c2);
};

Swirl::Swirl(int r1, int c1, int r2, int c2)
{
	this->R_Size = r2 - r1 + 1;
	this->C_Size = c2 - c1 + 1;

	for (int i = 0; i < this->R_Size; i++)
	{
		vector<int> Temp;
		Temp.resize(C_Size);
		Vector.push_back(Temp);
	}

}

int Swirl::GetMax()
{
	int Max = 0;

	for (int Row = 0; Row < this->R_Size; Row++)
	{
		for (int Column = 0; Column < this->C_Size; Column++)
		{
			if (Max < this->Vector[Row][Column])
				Max = this->Vector[Row][Column];
		}
	}

	if (Max > 99999999)
		return 9;
	else if (Max > 9999999)
		return 8;
	else if (Max > 999999)
		return 7;
	else if (Max > 99999)
		return 6;
	else if (Max > 9999)
		return 5;
	else if (Max > 999)
		return 4;
	else if (Max > 99)
		return 3;
	else if (Max > 9)
		return 2;
	else
		return 1;
}

int Swirl::GetSum(int n)
{
	int i = n;
	int Sum = 0;
	while (i > 1)
	{
		Sum += i - 1;
		i--;
	}
	return Sum;
}

void Swirl::GetSwirl(int r1, int c1, int r2, int c2)
{
	int Tempc = c1;

	for (int i = 0;i < this->R_Size; i++)
	{
		for (int j = 0; j < this->C_Size;j++)
		{
			if (r1 == 0 && c1 == 0)
			{
				this->Vector[i][j] = 1;
			}
			if (r1 == 0 || c1 == 0)
			{
				if (c1 <0)
					this->Vector[i][j] = (8 * GetSum(abs(c1))) + (5 * abs(c1)) + 1;
				else if (c1 > 0)
					this->Vector[i][j] = (8 * GetSum(abs(c1))) + (1 * abs(c1)) + 1;
				else if (r1 <0)
					this->Vector[i][j] = (8 * GetSum(abs(r1))) + (3 * abs(r1)) + 1;
				else if (r1 > 0)
					this->Vector[i][j] = (8 * GetSum(abs(r1))) + (7 * abs(r1)) + 1;
			}
			else if (c1 < 0)
			{
				if (r1 < c1)
					this->Vector[i][j] = (8 * GetSum(abs(r1))) + (4 * abs(r1)) + (r1 - c1) + 1;
				else if(r1 > abs(c1))
					this->Vector[i][j] = (8 * GetSum(abs(r1))) + (6 * abs(r1)) + (r1 + c1) + 1;
				else
					this->Vector[i][j] = (8 * GetSum(abs(c1))) + (4 * abs(c1)) - (c1 - r1) + 1;
			}
			else if (c1 > 0)
			{
				if (r1 < 0)
				{
					if (abs(r1) > c1)
						this->Vector[i][j] = (8 * GetSum(abs(r1))) + (2 * abs(r1)) - (c1 + r1) + 1;
					else if (abs(r1) <= c1)
						this->Vector[i][j] = (8 * GetSum(abs(c1))) + (2 * abs(c1)) - (c1 + r1) + 1;
				}

				else if (r1 == c1)
					this->Vector[i][j] = (8 * GetSum(r1)) + (8 * r1) + 1;
				else if (r1 == c1 - 1)
					this->Vector[i][j] = (8 * GetSum(abs(c1 - 1))) + (8 * abs(c1 - 1)) + (c1 - r1) + 1;
				else if (r1 < c1)
					this->Vector[i][j] = (8 * GetSum(c1 - 1)) + (8 * abs(c1 - 1)) + (c1 - r1) + 1;
				else if (r1 > c1)
					this->Vector[i][j] = (8 * GetSum(r1)) + (8 * r1) - (r1 - c1) + 1;
			}
				
			c1++;
		}
		r1++;
		c1 = Tempc;
	}

	int MaxLength = this->GetMax();

	vector<vector<int>> CountVector;
	for (int i = 0; i < R_Size; i++)
	{
		vector<int> Temp;
		Temp.resize(C_Size);
		CountVector.push_back(Temp);
	}

	for (int Row = 0; Row < R_Size; Row++)
	{
		for (int Column = 0; Column < C_Size; Column++)
		{
			if (this->Vector[Row][Column] > 99999999)
				CountVector[Row][Column] = 9;
			else if (this->Vector[Row][Column] > 9999999)
				CountVector[Row][Column] = 8;
			else if (this->Vector[Row][Column] > 999999)
				CountVector[Row][Column] = 7;
			else if (this->Vector[Row][Column] > 99999)
				CountVector[Row][Column] = 6;
			else if (this->Vector[Row][Column] > 9999)
				CountVector[Row][Column] = 5;
			else if (this->Vector[Row][Column] > 999)
				CountVector[Row][Column] = 4;
			else if (this->Vector[Row][Column] > 99)
				CountVector[Row][Column] = 3;
			else if (this->Vector[Row][Column] > 9)
				CountVector[Row][Column] = 2;
			else
				CountVector[Row][Column] = 1;

			switch (MaxLength - CountVector[Row][Column])
			{
			case 1: cout << " "; break;
			case 2: cout << "  "; break;
			case 3: cout << "   "; break;
			case 4: cout << "    "; break;
			case 5: cout << "     "; break;
			case 6: cout << "      "; break;
			case 7: cout << "       "; break;
			case 8: cout << "        "; break;
			default: break;
			}

			cout << this->Vector[Row][Column] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int r1;
	cin >> r1;
	int c1;
	cin >> c1;
	int r2;
	cin >> r2;
	int c2;
	cin >> c2;

	Swirl S(r1,c1,r2,c2);
	
	S.GetSwirl(r1,c1,r2,c2);

	return 0;
}