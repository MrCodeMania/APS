#include <iostream>

int main (){
    int time[42] = {0,};
    for (int i = 0; i < 10; i++){
        int a;
        scanf("%d",&a);
        
        time[a%42]++;
    }
    
    int count = 0;
    
    for(int i = 0; i < 42; i++)
        if(time[i])
            count++;
    
    printf("%d", count);
}