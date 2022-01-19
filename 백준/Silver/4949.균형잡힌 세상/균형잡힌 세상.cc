#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

char Stack[101];
int top = 0;

void Push(char x)
{
	Stack[top++] = x;
}

void Pop()
{
	--top;
}

int main()
{
	while (true)
	{
		top = 0;
		string sInput;
		getline(cin,sInput,'\n');

		if (sInput[0] == '.' && sInput.size() == 1)
			break;

		bool YorN = true;
		int Count = 0;
		
		for (int i = 0; i < sInput.size(); i++)
		{
			if (sInput[i] == '(' || sInput[i] == '[')
			{
				Push(sInput[i]);
				Count++;
			}
			else if (sInput[i] == ')' || sInput[i] == ']')
			{
				Count--;

				if (top > 0)
				{
					if (Stack[top - 1] == '(' && sInput[i] == ')')
						Pop();
					else if (Stack[top - 1] == '[' && sInput[i] == ']')
						Pop();
					else
					{
						YorN = false;
						break;
					}
				}
				else
				{
					YorN = false;
					break;
				}
			}
		}

		if (Count != 0 || !YorN)
			printf("no\n");
		else
			printf("yes\n");
	}
}