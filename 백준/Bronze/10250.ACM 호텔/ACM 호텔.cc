#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    
    while(testcase--)
    {
        int W,H;
        cin >> H >> W;
        
        int N;
        cin >> N;
        
        int cnt = 0;
        int i,j;
        bool BreakPoint = false;
        
        for(i = 1; i <= W; i++)
        {
            for(j = 1; j <= H; j++)
            {
                if(++cnt == N)
                    BreakPoint = true;
                if(BreakPoint)
                    break;
            }
            if(BreakPoint)
                break;
        }
        
        if(i < 10)
            cout << j << "0" << i << endl;
        else
            cout << j << i << endl;
    }
}