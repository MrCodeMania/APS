#include <iostream>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int mi = 1000000;
    int ma = -1000000;
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;
        
        if(t < mi)
            mi = t;
        if(t > ma)
            ma = t;
    }
    
    cout << mi << " " << ma;
}