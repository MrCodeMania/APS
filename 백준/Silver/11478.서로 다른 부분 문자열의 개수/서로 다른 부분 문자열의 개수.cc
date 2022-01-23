#include <iostream>
#include <set>

using namespace std;

int main() {
    string S;
    cin >> S;
    
    string t;
    set<string> _set;
    
    for(int i = 0; i < S.size(); i++){
        for(int j = i; j < S.size(); j++){
            t += S[j];
            _set.insert(t);
        }
        t = "";
    }
    
    cout << _set.size();
}