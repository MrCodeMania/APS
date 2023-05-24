#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void move(int from, int to) {
    cout << from << " " << to << "\n";
}

void hanoi(int N, int from, int via, int to) {
    if (N == 1) {
        move(from, to);
    }
    else {
        hanoi(N - 1, from, to, via);
        move(from, to);
        hanoi(N - 1, via, from, to);
    }

}

void strMul(int N) {
    string s = to_string(int(pow(2, 20)));
    string p;

    int count;

    for (int i = 0; i < N - 20; i++) {
        p = "0";
        count = 1;
        
        for (int j = s.size(); j--; j >= 0) {
            int num = s[j] - '0';
            num *= 2;
            
            int temp = num + (p[p.size() - count] - '0');
            
            p = p.substr(1,p.size());
            p = to_string(temp) + p;
            
            count++;
            
            if (temp < 10 && j != 0) {
                p = "0" + p;
            }
        }
        
        s = p;
    }

    s[s.size() - 1] = s[s.size() - 1] - 1;

    cout << s << "\n";
}

int main() {

    int N;
    cin >> N;

    if (N <= 20) {
        cout << int(pow(2, N)) - 1 << "\n";

        hanoi(N, 1, 2, 3);
    }
    else {
        strMul(N);
    }

    return 0;
}