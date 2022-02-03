#include <iostream>

using namespace std;

int main() {
    int N;
    scanf("%d",&N);
    
    int minV = 99999999;
    for(int i = 0; i <= N / 5; i++){
        for(int j = 0; j <= N / 3; j++){
            if(5 * i + 3 * j == N){
                if(i + j < minV)
                    minV = i + j;
            }
        }
    }
    
    if(minV == 99999999)
        printf("-1");
    else
        printf("%d", minV);
}