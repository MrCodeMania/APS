#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int count = 0;
    
    for(int i = 0; i < s.size();i++) {
        if(s[i] == 'c' && i < s.size() - 1) {
            if(s[i+1] == '=' || s[i+1] == '-'){
                count++;
                i++;
                continue;
            }
        }
        if(s[i] == 'd' && i < s.size() - 1) {
            if(s[i+1] == '-'){
                count++;
                i++;
                continue;
            }
        }
        if(s[i] == 'd' && i < s.size() - 2) {
            if(s[i+1] == 'z' && s[i+2] == '='){
                count++;
                i+=2;
                continue;
            }
        }
        
        if(s[i] == 'l' && i < s.size() - 1) {
            if(s[i+1] == 'j'){
                count++;
                i++;
                continue;
            }
        }
        
        if(s[i] == 'n' && i < s.size() - 1) {
            if(s[i+1] == 'j'){
                count++;
                i++;
                continue;
            }
        }
        
        if(s[i] == 's' && i < s.size() - 1) {
            if(s[i+1] == '='){
                count++;
                i++;
                continue;
            }
        }
        
        if(s[i] == 'z' && i < s.size() - 1) {
            if(s[i+1] == '='){
                count++;
                i++;
                continue;
            }
        }
        
        count++;
        
    }
    
    cout << count << endl;
}