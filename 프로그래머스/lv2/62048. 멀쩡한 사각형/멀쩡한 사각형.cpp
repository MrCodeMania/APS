#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

long long gcd(long long a, long long b) {
	return a % b == 0 ? b : gcd(b, a % b);
}
long long solution(int w, int h) {
	long long w_long = w;
    long long h_long = h;
    
    long long whole = w_long * h_long;
	long long broken = w + h - gcd(w_long, h_long);
	return whole - broken;
}