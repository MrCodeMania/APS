#include <iostream>

using namespace std;

class Stair
{
private:
	int Stairs[3];
	int UpMost[3] = { 0,0,0 };
	int UpLeast[3] = { 0,0,0 };
	int Num;
public:
	Stair(int n);
	void Descend();
};

Stair::Stair(int n)
{
	this->Num = n;
}

void Stair::Descend()
{
	int A, B, C, D;

	cin >> this->Stairs[0] >> this->Stairs[1] >> this->Stairs[2];

	this->UpMost[0] = this->Stairs[0];
	this->UpMost[1] = this->Stairs[1];
	this->UpMost[2] = this->Stairs[2];

	this->UpLeast[0] = this->Stairs[0];
	this->UpLeast[1] = this->Stairs[1];
	this->UpLeast[2] = this->Stairs[2];

	for(int i = 1; i < this->Num; i++)
	{
		cin >> this->Stairs[0] >> this->Stairs[1] >> this->Stairs[2];

		A = (this->UpMost[0] + this->Stairs[0]) < (this->UpMost[1] + this->Stairs[0]) ? this->UpMost[1] + this->Stairs[0] : this->UpMost[0] + this->Stairs[0];
		B = (this->UpMost[0] + this->Stairs[1]) < (this->UpMost[1] + this->Stairs[1]) ? this->UpMost[1] + this->Stairs[1] : this->UpMost[0] + this->Stairs[1];
		C = B < (this->UpMost[2] + this->Stairs[1]) ? (this->UpMost[2] + this->Stairs[1]) : B;
		D = (this->UpMost[2] + this->Stairs[2]) < (this->UpMost[1] + this->Stairs[2]) ? this->UpMost[1] + this->Stairs[2] : this->UpMost[2] + this->Stairs[2];

		this->UpMost[0] = A;
		this->UpMost[1] = C;
		this->UpMost[2] = D;

		A = (this->UpLeast[0] + this->Stairs[0]) > (this->UpLeast[1] + this->Stairs[0]) ? this->UpLeast[1] + this->Stairs[0] : this->UpLeast[0] + this->Stairs[0];
		B = (this->UpLeast[0] + this->Stairs[1]) > (this->UpLeast[1] + this->Stairs[1]) ? this->UpLeast[1] + this->Stairs[1] : this->UpLeast[0] + this->Stairs[1];
		C = B > (this->UpLeast[2] + this->Stairs[1]) ? (this->UpLeast[2] + this->Stairs[1]) : B;
		D = (this->UpLeast[2] + this->Stairs[2]) > (this->UpLeast[1] + this->Stairs[2]) ? this->UpLeast[1] + this->Stairs[2] : this->UpLeast[2] + this->Stairs[2];

		this->UpLeast[0] = A;
		this->UpLeast[1] = C;
		this->UpLeast[2] = D;
	}

	cout << ((this->UpMost[0] < this->UpMost[1] ? this->UpMost[1] : this->UpMost[0]) < this->UpMost[2] ? this->UpMost[2] : (this->UpMost[0] < this->UpMost[1] ? this->UpMost[1] : this->UpMost[0])) << " ";
	cout << ((this->UpLeast[0] > this->UpLeast[1] ? this->UpLeast[1] : this->UpLeast[0]) > this->UpLeast[2] ? this->UpLeast[2] : (this->UpLeast[0] > this->UpLeast[1] ? this->UpLeast[1] : this->UpLeast[0]));
}


int main()
{
	int Num;
	cin >> Num;

	Stair S(Num);
	
	S.Descend();

	return 0;
}