#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//겹치면 이어라
// -20 ~ +15
// -18 ~ -13
// -14 ~ -5

// 진입 지점을 기준으로 내림차순 정렬
// 카메라 가능 - 카메라 가능
// 다음 지역도 가능한지
// 가능하면 추가

int solution(vector<vector<int>> routes) {
	int answer = 0;
	bool Visit[10000] = { false, };

	sort(routes.begin(), routes.end());

	int StartPoint, EndPoint;
	bool Breaks = true;

	while (true)
	{
		Breaks = false;

		for (int i = 0; i < routes.size(); i++)
		{
			if (Visit[i])
				continue;
			else if (!Visit[i] && !Breaks)
			{
				Breaks = true;
				Visit[i] = true;
				StartPoint = routes[i][0];
				EndPoint = routes[i][1];
			}
			else if (routes[i][0] > EndPoint)
				break;
			else if (routes[i][0] >= StartPoint && routes[i][0] <= EndPoint || routes[i][1] >= StartPoint && routes[i][1] <= EndPoint)
			{
				Visit[i] = true;
				StartPoint = routes[i][0];
				EndPoint = routes[i][1] > EndPoint ? EndPoint : routes[i][1];
			}
		}

		if (!Breaks)
			break;

		answer++;
	}
	return answer;
}

int main()
{
	solution(vector<vector<int>>({ { -2, -1 }, {1,2},{-3, 0} }));
/*
	print(solution([[-2, -1], [1, 2], [-3, 0]])) #2
		print(solution([[0, 0], ])) #1
		print(solution([[0, 1], [0, 1], [1, 2]])) #1
		print(solution([[0, 1], [2, 3], [4, 5], [6, 7]])) #4
		print(solution([[-20, -15], [-14, -5], [-18, -13], [-5, -3]])) #2
		print(solution([[-20, 15], [-14, -5], [-18, -13], [-5, -3]])) #2
		print(solution([[-20, 15], [-20, -15], [-14, -5], [-18, -13], [-5, -3]])) #2*/
}