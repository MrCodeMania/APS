#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location)
{
	int Print = 0;
	int Large_Num_Loc = 0;
	int Large_Num = *max_element(priorities.begin(), priorities.end());
    
	while (Print < priorities.size())
	{
		int Last_Large_Num_Loc = Large_Num_Loc;
		
		for (int i = 0; i < priorities.size(); i++)
		{
			int index = Last_Large_Num_Loc + i < priorities.size() ? Last_Large_Num_Loc + i : Last_Large_Num_Loc + i - priorities.size();
			if (priorities[index] == Large_Num)
			{
                priorities[index] = 0;
				Large_Num_Loc = index;
				Print += 1;
				if (location == index)
					return Print;
			}
		}
		Large_Num = *max_element(priorities.begin(), priorities.end());
	}
}