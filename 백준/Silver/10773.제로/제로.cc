#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int Stack[100000];
int top = 0;

void Push(int x)
{
	Stack[top++] = x;
}

void Pop()
{
	if (top > 0)
		--top;
}

int main()
{
	int N;
	cin >> N;

	while (N--)
	{
		int Input;
		cin >> Input;

		if (Input == 0)
			Pop();
		else
			Push(Input);
	}

	int Sum = 0;
	for (int i = 0; i < top; i++)
		Sum += Stack[i];

	cout << Sum;
}