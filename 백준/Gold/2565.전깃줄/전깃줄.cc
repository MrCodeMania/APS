// 전깃줄을 끊는 것보다
// 전깃줄을 최대한 많이 잇는다.

// 앞 전봇대를 기준으로 정렬하고
// 뒷 전봇대의 LIS를 구하는 것이 풀이법

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<pair<int,int>> Line;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		pair<int,int> Temp;
        cin>> Temp.first;
        cin>> Temp.second;

		Line.push_back(Temp);
	}

	sort(Line.begin(), Line.end());

	// LIS
	int DP[100] = { 0, };
	int Max = 0;
	for (int i = 1; i < N; i++)
	{
		int Last = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (DP[Last] <= DP[j] && Line[j].second < Line[i].second)
				Last = j;
		}
        if (Last != i)
	    	DP[i] = DP[Last] + 1;

		if (DP[i] > Max)
			Max = DP[i];
	}

	cout <<  N - (Max + 1) << endl;
}
