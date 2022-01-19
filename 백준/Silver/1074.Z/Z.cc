#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    
    int pw = pow(2, N);
    int least = 0;
    
    while(pw > 2) {
        int square = pow(pw, 2);
        int mid = pw / 2;
        int quarter = square / 4;
        
        if(r < mid && c < mid)
            least = least;
        else if(r < mid && c >= mid) {
            least += quarter;
            c -= mid;
        }
        else if(r >= mid && c < mid) {
            least += quarter * 2;
            r -= mid;
        }
        else if(r >= mid && c >= mid) {
            least += quarter * 3;
            r -= mid; c -= mid;
        }
        
        pw /= 2;
    }
    
    if(r == 0 && c == 0)
        cout << least;
    else if(r == 0 && c == 1)
        cout << least + 1;
    else if(r == 1 && c == 0)
        cout << least + 2;
    else if(r == 1 && c == 1)
        cout << least + 3;
}