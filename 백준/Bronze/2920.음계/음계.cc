#include <iostream>

using namespace std;

int main()
{
    int Prev = 0;
    int Num = 0;
    int Sorting = 0;
    int i = 1;
    
    cin >> Num;
    
    if(Num == 1)
        Sorting = 1;
    else if(Num == 8)
        Sorting = 2;
    else
        i = 8;
    
    for(; i < 8; i++)
    {
        Prev = Num;
        cin >> Num;
        
        if(Prev == (Num - 1))
        {   
            if(Sorting == 1)
                continue;
            else
            {
                Sorting = 0;
                break;
            }
        }
        else if(Prev == (Num + 1))
        {   
            if(Sorting == 2)
                continue;
            else
            {
                Sorting = 0;
                break;
            }
        }
        else
        {
            Sorting = 0;
            break;
        }
    }
    
    if(Sorting == 0)
        cout << "mixed";
    else if(Sorting == 1)
        cout << "ascending";
    else
        cout << "descending";
        
}