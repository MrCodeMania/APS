#include <iostream>
#include <vector>

using namespace std;

int M, N;
bool visit[8] = {false,};

void DFS(int time, vector<int> v){
    
    if(time == N){
        for(int i = 0; i < v.size(); i++){
            printf("%d ",v[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i = 0; i < M; i++){
        if(!visit[i]){
            visit[i] = true;
            v.push_back(i+1);
            DFS(time + 1, v);
            v.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    
    scanf("%d %d", &M, &N);
    
    vector<int> v;        
    
    DFS(0, v);
}