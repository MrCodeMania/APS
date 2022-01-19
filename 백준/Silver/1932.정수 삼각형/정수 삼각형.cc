#include <iostream>

using namespace std;

int Tri[500][500] = {0,};

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            cin >> Tri[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0)
                Tri[i][j] = Tri[i-1][j] + Tri[i][j];
            else
                Tri[i][j] += Tri[i-1][j-1] > Tri[i-1][j] ? Tri[i-1][j-1] : Tri[i-1][j]; 
        }
    }
    
    int Max = 0;
    for(int i = 0; i < N; i++) {
        if(Max < Tri[N-1][i])
            Max = Tri[N-1][i];
    }
    
    cout << Max;
}