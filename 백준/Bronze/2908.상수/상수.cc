#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B;

    scanf("%d %d", &A, &B);

    int d = 10;
    int win = 0;

    vector<int> va;
    vector<int> vb;

    for (int i = 2; i >= 0; i--) {

        va.push_back(int((A % d) / (d / 10)));
        vb.push_back(int((B % d) / (d / 10)));
        d *= 10;
    }


    for (int i = 0; i < 3; i++) {
        if (va[i] < vb[i]) {
            win = 2;
            break;
        }
        else if (va[i] > vb[i]) {
            win = 1;
            break;
        }
    }

    if (win == 2) {
        // B 거꾸로 출력
        for (int i = 0; i < 3; i++) {
            printf("%d", vb[i]);
        }
    }
    else {
        // A 거꾸로 출력
        for (int i = 0; i < 3; i++) {
            printf("%d", va[i]);
        }
    }
}