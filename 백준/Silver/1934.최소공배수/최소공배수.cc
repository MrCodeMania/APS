#include <iostream>

using namespace std;

int getLCM(int A, int B)
{
	int mulA = A;
	int mulB = B;
	int mulLeast = A * B;
	int ReturnValue;
	while (true)
	{
		if ((mulLeast > mulA) && (mulLeast > mulB))
		{
			if (mulA < mulB)
				mulA += A;
			else if (mulA == mulB)
			{
				ReturnValue = mulA;
				break;
			}
			else
				mulB += B;
		}
		else
		{
			ReturnValue = mulLeast;
			break;
		}
	}

	return ReturnValue;
}

int main()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		int a, b;
		cin >> a >> b;

		cout << getLCM(a, b) << endl;
	}
	return 0;
}