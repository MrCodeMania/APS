#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    
    vector<vector<string>> a_to_z;
    vector<string> answer;
    
    for(int i = 0; i < 26; i++)
    {
        vector<string> temp;
        a_to_z.push_back(temp);
    }
    
    for(int i = 0; i < strings.size(); i++)
        a_to_z[strings[i][n] - 97].push_back(strings[i]);
    
    for(int i = 0; i < 26; i++)
        sort(a_to_z[i].begin(), a_to_z[i].end());
    
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < a_to_z[i].size(); j++)
            answer.push_back(a_to_z[i][j]);
        
    return answer;
}