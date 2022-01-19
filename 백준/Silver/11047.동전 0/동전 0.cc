#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    
    vector<int> Coins;
    int Count = 0;
    int j = N-1;
    
    for(int i = 0; i < N; i++)
    {
        int Temp;
        cin >> Temp;
        Coins.push_back(Temp);
    }
    
    while(K>0)
    {
        if(Coins[j] <= K)
        {
            K -= Coins[j];
            Count++;
            continue;
        }
        else
            j--;
    }
    
    cout << Count;
}