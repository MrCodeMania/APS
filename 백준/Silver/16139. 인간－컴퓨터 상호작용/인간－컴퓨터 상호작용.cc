#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;
 
vector<string> split(string str, char Delimiter) {
    stringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
 
    vector<string> result;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result;
}

int main(){
    string s;
    int q;
    string input;

    cin >> s;
    cin >> q;

    vector<vector<int> > sum;

    for(int i = 0; i < 26; i++){
        vector<int> v(s.size(), 0);
        sum.push_back(v);

        for(int j = 0; j < s.size(); j++){
            if(j != 0){
                sum[i][j] = sum[i][j-1];
            }

            if(s[j] == 'a' + i){
                sum[i][j]++;
            }
        }
    }

    cin.ignore();
    
    for(int i = 0; i < q; i++){
        
        getline(cin,input, '\n');

        vector<string> v = split(input, ' ');
        

        int alphaNum = v[0][0] - 'a';
        int startNum = stoi(v[1]);
        int endNum = stoi(v[2]);
        
        if(startNum == 0){
            cout << sum[alphaNum][endNum] << endl; 
        }
        else {
            cout << sum[alphaNum][endNum] - sum[alphaNum][startNum - 1] << endl; 
        }
    }
}

