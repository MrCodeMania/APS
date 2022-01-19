#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
	int Top;
public:
	Stack(int n);
	void Push();
	void Pop();
	int GetSize();
};

Stack::Stack(int n)
{
	Top = 0;
}

void Stack::Push()
{
	Top++;
}

void Stack::Pop()
{
	Top--;
}

int Stack::GetSize()
{
	return Top;
}

int main()
{
	int TestCase;
	cin >> TestCase;

	while (TestCase)
	{
        TestCase--;
		Stack S(0);
		
		string sInput;
		cin >> sInput;
        
		for (int i = 0; i < sInput.size(); i++)
		{
			if (sInput[i] == '(')
				S.Push();
			else if (sInput[i] == ')')
				S.Pop();
			else
				break;
            
            if(S.GetSize() == -1)
                break;
		}

		if (S.GetSize() == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}