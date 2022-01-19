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

int getGCD(int A, int B)
{
    int ReturnValue;
	
    for(int i = 1; i <= (A < B ? A : B); i++)
    {
        if(A % i == 0 && B % i == 0 )
            ReturnValue = i;    
    }

	return ReturnValue;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << getGCD(a,b) << endl << getLCM(a, b) ;
	
	return 0;
}