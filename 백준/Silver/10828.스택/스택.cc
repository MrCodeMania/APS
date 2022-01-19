#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int Stack[10000];
int top = 0;
void Push(int x)
{
	Stack[top++] = x;
}

void Top()
{
	if (top > 0)
		printf("%d\n", Stack[top - 1]);
	else
		printf("-1\n");
}

void Size()
{
	printf("%d\n", top);
}

void Empty()
{
	if (top > 0)
		printf("0\n");
	else
		printf("1\n");
}

void Pop()
{
	if (top > 0)
	{
		printf("%d\n", Stack[--top]);
	}
	else
		printf("-1\n");
}



int main()
{
	int N;
	scanf(" %d", &N);

	while (N--)
	{
		string Command = "";
		cin >> Command;

		
		if (Command[2] == 's')
		{
			int Digit;
			cin >> Digit;
			Push(Digit);
		}
		else if (Command[0] == 't')
			Top();
		else if (Command[0] == 's')
			Size();
		else if (Command[0] == 'e')
			Empty();
		else
			Pop();
			
	}


}