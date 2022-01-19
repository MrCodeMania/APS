#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> Array;
	Array.push_back(1);

	int Target;
	cin >> Target;

	int ToNext = 6;
	int Count = 1;
    
    if(Target == 1)
        cout << 1;
    
    else
    {
	    for (int i = 1; Array[i - 1] <= 1000500000; i++)
	    {
	    	Array.push_back(Array[i - 1] + ToNext);
	        Count++;
		    ToNext += 6;
	    	
            if (Array[i - 1] < Target && Target <= Array[i])
	    	{
		    	cout << Count;
		    	break;
	    	}
        }
    }
	return 0;
}