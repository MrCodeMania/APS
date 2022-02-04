#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double A, B, V;

    scanf("%lf %lf %lf", &A, &B, &V);

    if (V - A > 0) {
        printf("%d", int(ceil((V - A) / (A - B))) + 1);
    }
    else
        printf("1");
}