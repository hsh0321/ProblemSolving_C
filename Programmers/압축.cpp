#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
 
    unordered_map<string,int> map;
    
    char tmp = 'A';
    
    int num = 1;
    for(num=1;num<=26;num++){
        string s;
        s.push_back(tmp);
        map[s] = num;
        tmp++;
    }
    
    string w,c,wc;
    for(int i=0;i<msg.size();i++){
        w = "";
        w.push_back(msg[i]);
        int j=i+1;
        while(map[w] != 0){ // 맵에 존재하지 않을 때 까지
            w.push_back(msg[j++]);
        }
        if(w.size() >= 3){
            i += w.size()-2;
        }
        map[w] = num;
        num++;
        cout << w << endl;
        
        w.pop_back(); // 한글자 제거
        answer.push_back(map[w]);
    }
    
    return answer;
}
