#include <string>
#include <vector>

using namespace std;

int map[101][101] = { 0, };

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int cnt = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j] = cnt++;
        }
    }


    for (int i = 0; i < queries.size(); i++) {

        int min = 99999999;
        
        for(int j = queries[i][0] - 1; j <= queries[i][2] - 1; j++){
            for(int k = queries[i][1] - 1; k <= queries[i][3] - 1; k++){
                if(j == queries[i][0] - 1 || j == queries[i][2] - 1){
                    
                        if(min > map[j][k])
                            min = map[j][k];
                    
                }
                if(k == queries[i][1] - 1 || k == queries[i][3] - 1){
                
                        if(min > map[j][k])
                            min = map[j][k];
                }
            }   
        }

        int temp_11 = map[queries[i][0] - 1][queries[i][1] - 1];
        int temp_1 = map[queries[i][0] - 1][queries[i][3] - 1];
        int temp_5 = map[queries[i][2] - 1][queries[i][3] - 1];

        for (int j = queries[i][0]; j < queries[i][2]; j++) {
            map[j - 1][queries[i][1] - 1] = map[j][queries[i][1] - 1];
        }
        
        for (int j = queries[i][3] - 1; j >= queries[i][1] + 1; j--) {
            map[queries[i][0] - 1][j] = map[queries[i][0] - 1][j - 1];
        }
        map[queries[i][0] - 1][queries[i][1]] = temp_11;

        for (int j = queries[i][2] - 1; j >= queries[i][0] + 1; j--) {
            map[j][queries[i][3] - 1] = map[j - 1][queries[i][3] - 1];
        }
        map[queries[i][0]][queries[i][3] - 1] = temp_1;

   
        for (int j = queries[i][1]; j < queries[i][3] - 1; j++) {
            map[queries[i][2] - 1][j - 1] = map[queries[i][2] - 1][j];
        }
        map[queries[i][2] - 1][queries[i][3] - 2] = temp_5;

        answer.push_back(min);


     
    }

    return answer;
}