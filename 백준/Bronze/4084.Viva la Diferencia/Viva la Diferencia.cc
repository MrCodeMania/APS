#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    long long a, b, c, d;
    long long t_a, t_b, t_c, t_d;
    
    while(1)
    {
        int Count = 0;
        cin >> a >> b >> c >> d;
        
        if(a == 0 && b == 0 && c == 0 && d == 0)
            break;
        
        do
        {
            
            t_a = abs(a-b);
            t_b = abs(b-c);
            t_c = abs(c-d);
            t_d = abs(d-a);
        
            if((t_a == t_b) && (t_b == t_c) && (t_c == t_d))
            {
                if(Count != 0)
                    Count++;
                break;
            }
            
            Count++;
        
            a = t_a;
            b = t_b;
            c = t_c;
            d = t_d;
        
        }while(1);
        
        cout << Count << endl;
    }
    
    return 0;
}
    