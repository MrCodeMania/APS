#include <iostream>

using namespace std;

int main() {
    int stairs[303] = {0,};
    int maxScore[303] = {0,};
    
    int size;
    cin >> size;
    
    for(int i = 3; i < size + 3; i++) {
        cin >> stairs[i];
    }
    
    for(int i = 3; i < size + 3; i++){
        maxScore[i] = max(stairs[i] + stairs[i-1] + maxScore[i-3], stairs[i] + maxScore[i-2]);
    }
    
    cout << maxScore[size+2];
}