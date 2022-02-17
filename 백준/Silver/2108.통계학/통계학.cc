#include <iostream>
#include <cmath>

int cnt[8002] = { 0, };

int main() {

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        cnt[t + 4000]++;
    }

    int m = -9999;
    int x = 0;
    int sum = 0;
    int bin = 8001;
    int count = 0;

    for (int i = 0; i <= 8000; i++) {

        if (cnt[i]) {
            sum += cnt[i] * (i - 4000);

            if (m == -9999)
                m = i;

            if (count <= N / 2) {
                count += cnt[i];
                if (count > N / 2) {
                    count = i + 1000000;
                }
            }
            x = i;

            if (cnt[i] > cnt[bin])
                bin = i;
        }
    }

    // 2번째
    int time = 0;
    for (int i = 0; i <= 8000; i++) {
        if (cnt[i] == cnt[bin]) {
            time++;
            if (time == 2) {
                bin = i;
                break;
            }
        }
    }

    printf("%d\n%d\n%d\n%d", int(floor((sum / double(N)) + 0.5)), count - 1004000, bin - 4000, x - m);
}