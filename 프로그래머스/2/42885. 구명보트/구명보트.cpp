#include <string>
#include <vector>

using namespace std;

class Heap
{
private:
	int Space[50001] = {};
	bool MaxHeap = true;
	int N = 0;
public:
	Heap(int n, bool max);
	void Push(int supplies);
	void Pop();
	int GetSize();
	int Front();
};

Heap::Heap(int n, bool max)
{
	this->MaxHeap = max;
	if (!max)
	{
		for (int i = 0; i < 50001; i++)
		{
			this->Space[i] = 256;
		}
	}
}

void Heap::Push(int supplies)
{
	this->N++;
	Space[this->N] = supplies;
	int i = this->N;

	if (this->MaxHeap)
	{

		while (i != 1)
		{
			if (Space[i] >= Space[i / 2])
				swap(Space[i], Space[i / 2]);
			else
				break;

			i /= 2;
		}
	}
	else
	{

		while (i != 1)
		{
			if (Space[i] <= Space[i / 2])
				swap(Space[i], Space[i / 2]);
			else
				break;

			i /= 2;
		}
	}
}

void Heap::Pop()
{
	if (this->MaxHeap)
	{
		Space[1] = -1;
		swap(Space[1], Space[this->N]);
		int i = 1;

		while (i * 2 <= this->N)
		{
			if (Space[i] < Space[i * 2] && Space[i * 2] >= Space[i * 2 + 1])
			{
				swap(Space[i], Space[i * 2]);
				i *= 2;
			}
			else if (Space[i] < Space[i * 2 + 1] && Space[i * 2] < Space[i * 2 + 1])
			{
				swap(Space[i], Space[i * 2 + 1]);
				i = i * 2 + 1;
			}
			else
				break;
		}
	}

	else
	{
		Space[1] = 256;
		swap(Space[1], Space[this->N]);
		int i = 1;

		while (i * 2 <= this->N)
		{
			if (Space[i] > Space[i * 2] && Space[i * 2] <= Space[i * 2 + 1])
			{
				swap(Space[i], Space[i * 2]);
				i *= 2;
			}
			else if (Space[i] > Space[i * 2 + 1] && Space[i * 2] > Space[i * 2 + 1])
			{
				swap(Space[i], Space[i * 2 + 1]);
				i = i * 2 + 1;
			}
			else
				break;
		}
	}

	this->N--;
}

int Heap::GetSize()
{
	return this->N;
}

int Heap::Front()
{
	return this->Space[1];
}


int solution(vector<int> people, int limit) {
	int answer = 0;

	Heap MaxHeap(people.size(), true);
	Heap MinHeap(people.size(), false);

	for (int i = 0; i < people.size(); i++)
	{
		MaxHeap.Push(people[i]);
		MinHeap.Push(people[i]);
	}

	int Count = 0;

	while (Count != people.size())
	{
		short Sum = MaxHeap.Front();
		MaxHeap.Pop();

		Count++;
		answer++;

		if ((Sum + MinHeap.Front()) <= limit && Count != people.size())
		{
			Sum += MinHeap.Front();
			MinHeap.Pop();
			Count++;
		}
	}

	return answer;
}