#include <iostream>

using namespace std;

int main() {
    while(true){
        int A, B, C;
        cin >> A >> B >> C;
        
        if(A == 0)
            break;
        
        if ((A * A + B * B == C * C) || (A * A + C * C == B * B) || (B * B + C * C == A * A))
            cout << "right" << endl;
        else cout << "wrong" << endl;
            
    }
}