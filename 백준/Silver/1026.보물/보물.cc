#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A[50];
	int B[50];

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = N; i < 50; i++)
		A[i] = 1000;
	for (int i = 0; i < N; i++)
		cin >> B[i];
	for (int i = N; i < 50; i++)
		B[i] = 1000;

	sort(A,A + 50);
	sort(B,B + 50);

	int S = 0;
    
	for (int i = 0; i < N; i++)
		S += A[i] * B[N - i - 1];

	cout << S;

	return 0;
}