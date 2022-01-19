#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N = 0;
int maxV = pow(3,7);
int paper[3000][3000] = {0,};
int cnt[3] = {0,};

void solution(int sStart, int sEnd, int eStart, int eEnd) {
    int num = paper[sStart][sEnd];
    
    for(int i = sStart; i < eStart; i++){
        for(int j = sEnd; j < eEnd; j++){
            if(num != paper[i][j]) {
                solution(sStart, sEnd, sStart + ((eStart - sStart) / 3), sEnd + ((eEnd - sEnd) / 3));
                solution(sStart + ((eStart - sStart) / 3), sEnd, sStart + ((eStart - sStart) / 3) * 2, sEnd + ((eEnd - sEnd) / 3));
                solution(sStart + ((eStart - sStart) / 3) * 2, sEnd, sStart + ((eStart - sStart) / 3) * 3, sEnd + ((eEnd - sEnd) / 3));
                solution(sStart + ((eStart - sStart) / 3) * 2, sEnd + ((eEnd - sEnd) / 3), sStart + ((eStart - sStart) / 3) * 3, sEnd + ((eEnd - sEnd) / 3) * 2);
                solution(sStart, sEnd + ((eEnd - sEnd) / 3), sStart + ((eStart - sStart) / 3), sEnd + ((eEnd - sEnd) / 3) * 2);
                solution(sStart, sEnd + ((eEnd - sEnd) / 3) * 2, sStart + ((eStart - sStart) / 3), sEnd + ((eEnd - sEnd) / 3) * 3);
                solution(sStart + ((eStart - sStart) / 3), sEnd + ((eEnd - sEnd) / 3) * 2, sStart + ((eStart - sStart) / 3) * 2, sEnd + ((eEnd - sEnd) / 3) * 3);
                solution(sStart + ((eStart - sStart) / 3) * 2, sEnd + ((eEnd - sEnd) / 3) * 2, sStart + ((eStart - sStart) / 3) * 3, sEnd + ((eEnd - sEnd) / 3) * 3);
                solution(sStart + ((eStart - sStart) / 3), sEnd + ((eEnd - sEnd) / 3), sStart + ((eStart - sStart) / 3) * 2, sEnd + ((eEnd - sEnd) / 3) * 2);
                return;
            }
        }
    }
    
    cnt[num+1]++;
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> paper[i][j];
    
    solution(0,0, N, N);
    
    for(int i = 0; i < 3; i++)
        cout << cnt[i] << endl;
    
    return 0;
}