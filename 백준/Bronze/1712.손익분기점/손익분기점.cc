#include <iostream>

using namespace std;

int main(){
    int A, B, C;
    scanf("%d %d %d",&A,&B,&C);
    
    if(B >= C){
        printf("-1");
    }
    else {
        long long result = C-B;
        
        printf("%d",(A / result) + 1);
    }
    
}