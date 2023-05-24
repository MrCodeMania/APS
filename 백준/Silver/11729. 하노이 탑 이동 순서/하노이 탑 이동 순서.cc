#include <iostream>
#include <cmath>

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

int main() {

    int N;
    cin >> N;

    cout << int(pow(2, N)) - 1 << "\n";

    hanoi(N, 1, 2, 3);

    return 0;
}