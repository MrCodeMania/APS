#include <iostream>
#include <vector>

using namespace std;

int time[10000] = {0,};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    int N;
    cin >> N;
  
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;
        time[t-1]++;
    }
    
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < time[i]; j++)
            cout << i + 1 << "\n";
    }
}