#include <iostream>
#include <vector>

using namespace std;

int countX[1001] = {0,};
int countY[1001] = {0,};

int main() {
    
    for(int i = 0; i < 3; i++){
        int a, b;
        cin >> a >> b;
    
        countX[a]++;
        countY[b]++;
    }
    
    for(int i = 0; i <= 1000; i++){
        if(countX[i] == 1){
            cout << i << " ";
            break;
        }
    }
    
    for(int i = 0; i <= 1000; i++){
        if(countY[i] == 1){
            cout << i;
            break;
        }
    }
}