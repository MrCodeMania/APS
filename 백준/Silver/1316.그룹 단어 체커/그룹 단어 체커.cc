#include <iostream>
#include <memory.h>

using namespace std;

bool character[26] = {0,};

int main() {
    int N;
    cin >> N;
    
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        memset(character,false, sizeof(character));
        
        string s;
        cin >> s;
        
        int idx = 0;
        for(; idx < s.size(); idx++){
            if(character[s[idx]-'a']){
                if(s[idx] != s[idx-1])
                    break;
            }
            else
                character[s[idx]-'a'] = true;
        }
        
        if(idx == s.size())
            cnt++;
    }
    
    cout << cnt;
}