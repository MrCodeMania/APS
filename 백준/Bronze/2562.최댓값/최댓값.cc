#include <iostream>

using namespace std;

int natural[9];

int main() {
    for(int i = 0; i < 9; i++)
        scanf("%d",&natural[i]);
    
    int max = 0;
    
    for(int i = 0; i < 9; i++)
        if(natural[i] > natural[max])
            max = i;
        
    printf("%d\n%d",natural[max],max+1);
    
}