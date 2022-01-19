#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int A[100000] = {0,};

int main() {
    stack<int> s;
    vector<string> v;
    int num = 1;
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> A[i];
    
    bool flag = true;
    
    for(int i = 0; i < N; i++) {
        flag = true;
        if(num <= A[i]) {
            while(A[i] >= num){
                s.push(num++);
                v.push_back("+");
            }
        }
        while(s.size()){

            if(s.top() == A[i]){
                
                s.pop();
                v.push_back("-");
                flag = false;
                break;
            }
            
            s.pop();
            v.push_back("-");
        }
        if(flag)
            break;
    }
    
    if(flag)
        cout << "NO";
    else {
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << "\n";
    }
            
}