#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

vector<string> split(string& str){
    vector<string> value;
    char tmp[101];
    strcpy(tmp,str.c_str());
    char* ptr = strtok(tmp," ");
    while(ptr!=NULL){
        string str1  = string(ptr);
        ptr = strtok(NULL," ");
        value.push_back(str1);
    }
    return value;
}

vector<string> solution(vector<string> record) {
   vector<string> answer;
    map<string,string> m;
    for(int i=0;i<record.size();i++){
        string str = record[i];
        vector<string> line = split(str);
        map<string,string>::iterator it = m.find(line[1]);
        if(line[0]=="Enter"){
            if(it==m.end()){
                m.insert(make_pair(line[1],line[2]));
            }
            else{
                it->second = line[2];
            }
        }
        else if(line[0]=="Change"){
            it->second = line[2];
        }
    }

    for(int i=0;i<record.size();i++){
        string str = record[i];
        vector<string> line = split(str);
        string name = (*m.find(line[1])).second;
        if(line[0]=="Enter"){
            answer.push_back(name+"님이 들어왔습니다.");
        }
        else if(line[0]=="Leave"){
            answer.push_back(name+"님이 나갔습니다.");
        }
    }
    return answer;
}