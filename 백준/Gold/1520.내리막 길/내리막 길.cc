#include <iostream>

using namespace std;

int dp[500][500] = {0,};
int map[500][500] = {0,};
int d[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};

int DFS(int r, int c, int m, int n) {
    if(r == m - 1 && c == n - 1)
        return 1;
    if(dp[r][c] != -1) return dp[r][c];
    
    dp[r][c] = 0;
    
    for(int i = 0; i < 4; i++){
        int newR = r + d[i][0];
        int newC = c + d[i][1];

        if(newR >= 0 && newR < m && newC >= 0 && newC < n){
            if(map[newR][newC] < map[r][c]){
                dp[r][c] += DFS(newR, newC, m, n);
            }
        }
    }
    
    return dp[r][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout << DFS(0, 0, M, N) << endl;
}