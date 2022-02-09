#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x,y,w,h;
    scanf("%d %d %d %d", &x,&y,&w,&h);
    
    printf("%d", min(x,min(y,min(h - y, w - x))));
}