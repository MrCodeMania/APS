#include <iostream>
#include <queue>

using namespace std;

int box[100][100][100] = { 0, };
int numOfTomatoes = 0;
int dir[6][3] = { {1,0,0}, {-1,0,0}, {0,-1,0}, {0,1,0},{0,0,1},{0,0,-1} };

int main() {
    int N, M, H;
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
            }
        }
    }

    int Day = 0;
    queue<int> q;
    bool correct = false;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0)
                    numOfTomatoes++;
                else if (box[i][j][k] == 1) {
                    q.push(i);
                    q.push(j);
                    q.push(k);
                    correct = true;
                }
            }
        }
    }

    bool change = true;

    while (correct) {
        if (numOfTomatoes == 0)
            break;

        Day++;

        int Size = q.size();

        if (Size == 0) {
            change = false;
            break;
        }

        while (Size) {
            int i = q.front();
            q.pop();
            int j = q.front();
            q.pop();
            int k = q.front();
            q.pop();

            for (int r = 0; r < 6; r++) {
                int new_i = i + dir[r][0];
                int new_j = j + dir[r][1];
                int new_k = k + dir[r][2];

                if (!(new_i < 0 || new_i >= H ||
                    new_j < 0 || new_j >= N ||
                    new_k < 0 || new_k >= M)) {
                    if (box[new_i][new_j][new_k] == 0) {
                        box[new_i][new_j][new_k] = 1;
                        q.push(new_i);
                        q.push(new_j);
                        q.push(new_k);
                        numOfTomatoes--;
                    }
                        
                }

            }

            Size -= 3;
        }
    }

    if (!change || !correct)
        cout << -1;
    else
        cout << Day;
}