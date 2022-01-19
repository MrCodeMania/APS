#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SelectionSort
{
private:
	vector<int> data;
	int Size;
public:
	SelectionSort(string input, int n);
	void selection_sort(int left, int right);
	void print();
};

SelectionSort::SelectionSort(string input, int n)
{
	Size = n;

	for (int i = 0; i < input.size(); i++)
		data.push_back(input.at(i) - '0');
}

void SelectionSort::selection_sort(int left, int right)
{
	for (int i = 0; i < Size; i++)
	{
		int Most = data[i];
		int Mostj = 0;
		for (int j = i; j < Size; j++)
		{
			if (Most <= data[j])
			{
				Mostj = j;
				Most = data[j];
			}
		}
		int Temp = data[i];
		data[i] = data[Mostj];
		data[Mostj] = Temp;
	}
}

void SelectionSort::print()
{
	for (int i = 0; i < Size; i++)
		cout << data[i];
}


int main()
{
	string Input;
	getline(cin, Input, '\n');

	SelectionSort S(Input, Input.size());

	S.selection_sort(0, Input.size() - 1);
	S.print();

	return 0;
}