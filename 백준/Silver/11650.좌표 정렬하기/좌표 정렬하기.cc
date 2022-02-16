#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int N;
    scanf("%d", &N);
    
    vector<pair<int,int>> v;
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        
        v.push_back(make_pair(a,b));
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < N; i++){
        printf("%d %d\n",v[i].first,v[i].second);
    }
}