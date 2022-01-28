#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main() {
    
    int testcase;
    scanf("%d", &testcase);
    
    for(int t = 0; t < testcase; t++){
        bool visited[40001] = {false,};
        
        int M,N,x,y;
        scanf("%d %d %d %d", &M, &N, &x, &y);
        
        int input[4];
        input[0] = M; input[1] = N; input[2] = x; input[3] = y; 
        
        int little, big;
        
        if(M < N){
            little = 2; big = 3;
        }
        else {
            little = 3; big = 2;
        }
        
        int target = input[little];
        int time = input[little];
        int last = lcm(M,N);
        
        while(true){
            if(time > last){
                time = -1;
                break;
            }
            visited[target] = true;
            
            if(target == input[big])
                break;
            
            target += input[little - 2];
            if(target > input[big - 2])
                target -= input[big - 2];
            time += input[little - 2];
        }
        
        printf("%d\n", time);
    }
}