#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int c_count = 0;
    int z_count = 0;
    for(int i = 0; i < 6; i++){
        if(lottos[i] == 0)
            z_count++;
        else{
            for(int j = 0; j < 6; j++){
                if(lottos[i] == win_nums[j])
                    c_count++;
            }
        }
    }
    
    int count = 7 - (c_count + z_count);
    if(count > 6)
        count = 6;
    
    answer.push_back(count);
    
    count = 7 - c_count;
    if(count > 6)
        count = 6;
    
    answer.push_back(count);
    
    return answer;
}