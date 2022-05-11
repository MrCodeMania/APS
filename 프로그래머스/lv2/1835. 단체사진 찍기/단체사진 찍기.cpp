#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<char, int> pos;
string friends = "ACFJMNRT";

int cnt = 0;

void DFS(int time, vector<string> data) {
    if (time == 8) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i][3] == '=') {
                if (abs(pos[data[i][0]] - pos[data[i][2]]) != (data[i][4] - '0') + 1)
                    return;
            }
            else if (data[i][3] == '>') {
                if (abs(pos[data[i][0]] - pos[data[i][2]]) <= (data[i][4] - '0') + 1)
                    return;
            }
            else if (data[i][3] == '<') {
                if (abs(pos[data[i][0]] - pos[data[i][2]]) >= (data[i][4] - '0') + 1)
                    return;

            }
        }
        cnt++;
        return;
    }

    for (int i = 0; i < friends.size(); i++) {
        if (pos[friends[i]] == -1) {
            pos[friends[i]] = time;
            DFS(time + 1, data);
            pos[friends[i]] = -1;
        }
    }

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    friends = "ACFJMNRT";
    cnt = 0;
    
    for (int i = 0; i < friends.size(); i++)
        pos[friends[i]] = -1;


    DFS(0, data);

    return cnt;
}

int main() {
    solution(2, vector<string>{"N~F=0", "R~T>2"});
}