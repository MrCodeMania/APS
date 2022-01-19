#include <iostream>
#include <vector>

using namespace std;

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
    int n;
    cin >> n;
    
    vector<int> Ring;
    
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;        
        Ring.push_back(x);
    }
    
    
    for(int i = 1; i < n; i++)
    {
        int x = Ring[0] / getGCD(Ring[0],Ring[i]);
        int y = Ring[i] / getGCD(Ring[0],Ring[i]);
        
        if(x%y == 0)
        {
            x /= y;
            y /= y;
        }            
        cout << x << "/" << y << endl;
       
    }
    
	return 0;
}