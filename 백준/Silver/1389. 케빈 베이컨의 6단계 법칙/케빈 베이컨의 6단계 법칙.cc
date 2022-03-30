#include <iostream>
#include <queue>

using namespace std;

int INF = 99999999;
int mem[100][100] = { 0, };

// floyd-warshall

int main() {
    int N, M;

    cin >> N >> M;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                mem[i][j] = 0;
            else
                mem[i][j] = INF;
        }
    }

    
    for (int i = 0; i < M; i++) {

        int A, B;
        cin >> A >> B;

        mem[A - 1][B - 1] = 1;
        mem[B - 1][A - 1] = 1;
    }
    
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mem[i][k] + mem[k][j] < mem[i][j])
                    mem[i][j] = mem[i][k] + mem[k][j];
            }
        }
    }

    int minMan = 0;
    int minSum = 99999999;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (i != j)
                sum += mem[i][j];
        }

        if (sum < minSum) {
            minMan = i;
            minSum = sum;
        }
            
    }
   

    printf("%d", minMan + 1);

    return 0;
}