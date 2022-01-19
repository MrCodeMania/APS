#include <iostream>
#include <vector>

using namespace std;

class Yoonori
{
private:
	vector<vector<int>> Array;
public:
	Yoonori();
	void SetValue(int i);
	void GetValue(int i);
};

Yoonori::Yoonori()
{
}

void Yoonori::SetValue(int i)
{
	vector<int> Temp;
	Temp.resize(4);
	this->Array.push_back(Temp);
	for (int j = 0; j < 4; j++)
	{
		int X;
		cin >> X;
		this->Array[i][j] = X;
	}
}

void Yoonori::GetValue(int i)
{
	int Count = 0;
	for (int j = 0; j < 4; j++)
	{
		if (this->Array[i][j] == 0)
			Count++;
	}
	
	if (Count == 0)
		cout << "E";
	else if (Count == 1)
		cout << "A";
	else if (Count == 2)
		cout << "B";
	else if (Count == 3)
		cout << "C";
	else cout << "D";
	
	cout << endl;
}
int main()
{
	Yoonori Y;
	
	for (int i = 0; i < 3; i++)
	{
		Y.SetValue(i);
		Y.GetValue(i);
	}

	return 0;
}