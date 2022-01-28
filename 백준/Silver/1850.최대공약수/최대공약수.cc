#include <cstdio>
#include <iostream>

long long gcd(long long A, long long B) {
    while (B != 0) {
        long long R = A % B;
        A = B;
        B = R;
    }
    return A;
}

int main() {
    long long A, B;
    scanf("%lld %lld", &A, &B);
    
    for (int i = gcd(A, B); i > 0; i--)
        printf("1");
}