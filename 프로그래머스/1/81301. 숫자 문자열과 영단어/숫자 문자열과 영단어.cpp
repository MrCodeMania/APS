#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    int level = 0;
    
    vector<int> store;
    
    map<string, int> m;
    
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    
    int i = 0;
    string key = "";
    
    while(i < s.size()){
        if(s[i] >= '0' && s[i] <= '9') {
            store.push_back(s[i] - '0');
        }
        else{
            key += s[i];
            if(m.find(key) != m.end()) {
                store.push_back(m[key]);
                key ="";
            }
        }
        i++;
        
    }
    
    for(int i = 0; i < store.size(); i++){
        answer += store[i] * pow(10,store.size() - 1 - i);
    }
    
    return answer;
}