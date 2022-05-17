#include <string>
#include <vector>

using namespace std;

//가장 작은 숫자 큐를 통해 그보다 큰값이 나왔다면
//pop을 하고 그 인덱스의 길이를 그만, 다음 작은 숫자도 비교
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++)
    {
        bool Great = true;
        for(int j = i+1;j < prices.size();j++)
        {
            if(prices[i] > prices[j])
            {
                Great = false;
                answer.push_back(j - i);
                break;
            }
        }
        if(Great)
            answer.push_back(prices.size() - i - 1);
    }
    
    return answer;
}