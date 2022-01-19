#include <iostream>
#include <string>

using namespace std;

int main()
{
	string Input;
	getline(cin, Input, '\n');

    bool OK = true;
	int iCount = 0;

	for (int i = 0; i < Input.size(); i++)
	{
        if(Input[i] == ' ')
            OK = true;
		if (Input[i] != ' ')
        {
            if(OK)
            {    
                iCount++;
                OK = false;
            }
        }   
        
	}

	cout << iCount;

	return 0;
}