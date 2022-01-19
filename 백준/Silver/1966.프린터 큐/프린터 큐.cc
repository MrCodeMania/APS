#include <iostream>
#include <vector>

using namespace std;

class Queue
{
private:
	vector<int> Document;
public:
	Queue(int n);
	void Print();
};

Queue::Queue(int n)
{
}

void Queue::Print()
{
	int N;
	cin >> N;

	int Position;
	cin >> Position;

	int Time = 0;
	int Last = 0;
	int Order = 1;

	for (int i = 0; i < N; i++)
	{
		int Temp;
		cin >> Temp;
		Document.push_back(Temp);
	}

	while (true)
	{
		int First = 0 + Time;
		bool TorF = false;

		for (int i = 0 + Time; i < N + Last; i++)
		{
			if (Document[First] < Document[i])
			{
				TorF = true;
				break;
			}
		}

		if (TorF)
		{
			if (First == Position)
				Position = Document.size();
			Time++;
			Last++;
			Document.push_back(Document[First]);
		}
		else
		{
			if (First == Position)
				break;
			Time++;
			Order++;
		}
	}

	cout << Order << endl;
}

int main()
{
	int TestCase;
	cin >> TestCase;

	while (TestCase--)
	{
		Queue Q(3);
		Q.Print();
	}
}