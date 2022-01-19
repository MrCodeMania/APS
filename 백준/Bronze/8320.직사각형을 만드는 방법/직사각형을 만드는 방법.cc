#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int Count = N;
    
    for(int i = 2; i < N; i++)
       for(int j = i; (i * j) <= N; j++)
           Count++;
 
    cout << Count;
}