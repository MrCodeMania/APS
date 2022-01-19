#include <iostream>
#include <string>

using namespace std;

class QuadTree
{
private:
	int** Image;
	int N;
public:
	QuadTree(int n);
	int First_Search(int size);
	void Divide(int size, int row, int col);
};

QuadTree::QuadTree(int n)
{
	this->N = n;

	Image = new int*[n];
	for (int i = 0; i < n; i++)
	{
		Image[i] = new int[n];
		string Input = "";
		getline(cin, Input);

		for (int j = 0; j < n; j++)
			Image[i][j] = int(Input[j]) - 48;
	}
}

int QuadTree::First_Search(int size)
{
	bool IsOne = true;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Image[0][0] != Image[i][j])
				IsOne = false;
		}
	}

	if (IsOne)
	{
		cout << Image[0][0];
		return 1;
	}
	else
		return 0;
}

void QuadTree::Divide(int size, int row, int col)
{
	if (size == 0)
		return;

	cout << "(";
	bool IsOne = true;
	for (int i = row; i < row + size; i++)
	{
		if (!IsOne)
			break;
		for (int j = col; j < col + size; j++)
		{
			if (Image[row][col] != Image[i][j])
			{
				Divide(size / 2, row, col);
				IsOne = false;
				break;
			}
		}
	}
		
	if (IsOne)
		cout << Image[row][col];

	IsOne = true;

	for (int i = row; i < row + size; i++)
	{
		if (!IsOne)
			break;
		for (int j = col + size; j < col + size * 2; j++)
		{
			if (Image[row][col + size] != Image[i][j])
			{
				Divide(size / 2, row, col + size);
				IsOne = false;
				break;
			}
		}
	}

	if (IsOne)
		cout << Image[row][col + size];

	IsOne = true;

	for (int i = row + size; i < row + size * 2; i++)
	{
		if (!IsOne)
			break;
		for (int j = col; j < col + size; j++)
		{
			if (Image[row + size][col] != Image[i][j])
			{
				Divide(size / 2, row + size, col);
				IsOne = false;
				break;
			}
		}
	}

	if (IsOne)
		cout << Image[row + size][col];

	IsOne = true;

	for (int i = row + size; i < row + size * 2; i++)
	{
		if (!IsOne)
			break;
		for (int j = col + size; j < col + size * 2; j++)
		{
			if (Image[row + size][col + size] != Image[i][j])
			{
				Divide(size / 2, row + size, col + size);
				IsOne = false;
				break;
			}
		}
	}

	if (IsOne)
		cout << Image[row + size][col + size];

	cout << ")";
}

int main()
{
	cin.tie(NULL);

	int N;
	cin >> N;
	cin.ignore();

	QuadTree Q(N);

	if (!Q.First_Search(N))
		Q.Divide(N / 2, 0, 0);

	return 0;

}