/* 부분합 모듈러 연산으로 구해놓고 
Sum 5~7 == 0 -> (Sum 0~7 - Sum 0~4) mod N
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> input(N + 1, 0);

    for(int i = 1; i <= N; i++){
        cin >> input[i];
    }

    vector<ll> sum(N + 1, 0);

    ll answer = 0;

    for(int i = 1; i <= N; i++){
        sum[i] = (sum[i-1] % M + input[i] % M) % M;
        if(sum[i] == 0){
            answer++;
        }
            
    }

    map<int, ll> count;

    for(int i = 1; i <= N; i++){
        if(count.find(sum[i]) != count.end()){
            count[sum[i]]++;
        }
        else{
            count[sum[i]] = 1;
        }
    }
    
    for(int i = 0; i <= M; i++){
        if(count.find(i) != count.end()){
            answer += (count[i] * (count[i] - 1)) / 2;

        }
    }

    cout << answer << "\n";
    
    return 0;
}