#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < N; i++){
        int s;
        scanf("%d",&s);
        pq.push(s);
    }
    
    for(int j = 0; j < K - 1; j++){
        pq.pop();
    }
    
    printf("%d", pq.top());
    
    return 0;
}