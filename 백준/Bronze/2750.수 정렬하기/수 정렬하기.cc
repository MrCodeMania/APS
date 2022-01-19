#include <iostream>
#include <vector>

using namespace std;

class QuickSort
{
private:
	vector<int> data;
	int Size;
public:
	QuickSort(int n);
	void quick_sort(int left, int right);
	void print();
};

QuickSort::QuickSort(int n)
{
	Size = n;
	for (int i = 0; i < Size; i++)
	{
		int x;
		cin >> x;
		data.push_back(x);
	}
}

void QuickSort::quick_sort(int left, int right)
{
	int i, j, key, temp;
	if (left < right)
	{
		i = left + 1;
		j = right;
		key = data[left];
		while (i <= j)
		{
			while (data[i] < key)
			{				
				i++;
				if (i == data.size())
					break;
			}
			while (data[j] > key)
			{
				j--;
				if (j == 0)
					break;
			}
			
			if (i <= j)
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}

		temp = data[left];
		data[left] = data[j];
		data[j] = temp;

		quick_sort(left, j - 1);
		quick_sort(j + 1, right);
	}
}

void QuickSort::print()
{
	for (int i = 0; i < Size; i++)
	{
		cout << data[i] << endl;
	}

}


int main()
{
	int Size;
	cin >> Size;

	QuickSort Q(Size);

	Q.quick_sort(0,Size-1);
	Q.print();

	return 0;
}