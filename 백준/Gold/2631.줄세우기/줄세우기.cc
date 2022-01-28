#include <iostream>

using namespace std;

int dp[200] = { 0, };
int children[200] = { 0, };

int main()
{
    // DP 3 -> 5 -> 6
    // 증가하는 부분 수열의 길이가 가장 긴 것
    // 앞부터 시작
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &children[i]);
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (children[i] > children[j] && dp[i] < (dp[j] + 1)) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int longest = 0;

    for (int i = 0; i < N; i++) {
        if (longest < dp[i])
            longest = dp[i];
    }

    cout << N - longest;
}