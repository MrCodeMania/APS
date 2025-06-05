#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end());


	for (int i = citations.size(); i >= 1; i--)
	{
		int index = citations.size() - 1;

		while (citations[index] >= i)
		{
			if (index == citations.size() - i)
			{
				answer = i;
				i = 0;
				break;
			}
			index--;
		}
	}
	return answer;
}