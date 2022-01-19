#include <cstdio>

#define min(a,b) ((a)<(b))?(a):(b)

#define INF 987654321

int main(){

    int T;

    scanf("%d", &T);


    while (T--){

        int K;

        int dp[501][501] = { 0 };

        int sum[501] = { 0 };

        int c[501];


        scanf("%d", &K);

        for (int k = 1; k <= K; k++){

            scanf("%d", &c[k]);

            sum[k] += sum[k - 1] + c[k];

        }


        for (int dia = 0; dia <= K; dia++){        //끝나는 지점

            for (int n = 1; n <= K; n++){

                int m = n + dia;

                if (n == m || m > K)

                    continue;

                dp[n][m] = INF;

                for (int k = n; k < m; k++)

                    dp[n][m] = min(dp[n][m], dp[n][k] + dp[k + 1][m] + sum[m] - sum[n - 1]);

            }

        }

        printf("%d\n", dp[1][K]);

    }

    return 0;

}
