#include <iostream>
#include <vector>

using namespace std;

class Less
{
private:
	vector<int> Array;
	int Target;
public:
	Less(int n, int x);
	void PrintLess();
};

Less::Less(int n, int x)
{
	this->Target = x;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		this->Array.push_back(temp);
	}
}

void Less::PrintLess()
{
	for (int i = 0; i < this->Array.size(); i++)
	{
		if (this->Target > this->Array[i])
			cout << this->Array[i] << " ";
	}
}

int main()
{
	int N;
	cin >> N;

	int X;
	cin >> X;

	Less Line(N, X);
	Line.PrintLess();

	return 0;
}