#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector< vector< char > > board;
vector< vector< int > > sum;
int minV = 99999999;

void solution(string start) {
    sum.assign(N+1, vector<int>(M+1, 0));

    string correct = start;
    int idx = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            sum[i][j] = sum[i][j - 1];
            
            if (board[i-1][j-1] != correct[idx]) {
                sum[i][j] += 1;
            }
            
            idx = (idx + 1) % 2;
        }
        
        if (M % 2 == 0) {
            idx = (idx + 1) % 2;
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            sum[j][i] += sum[j - 1][i];    
        }
    }

    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            int value = sum[i][j] - sum[i-K][j] - sum[i][j-K] + sum[i-K][j-K];
            if (value < minV) {
                minV = value;
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        vector<char> v;
        for (int j = 0; j < M; j++) {
            char el;
            cin >> el;
            v.push_back(el);
        }
        board.push_back(v);
    }

    solution("BW");
    solution("WB");

    cout << minV << endl;

    return 0;
}
