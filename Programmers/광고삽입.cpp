#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<pair<int,int>> timeline;
unordered_map<int,int> num;

int arr[362440];

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    for(int i=0;i<logs.size();i++){
        int start,end;
        start = stoi(logs[i].substr(0,2))*3600 + stoi(logs[i].substr(3,2))*60 + stoi(logs[i].substr(6,2));
        end = stoi(logs[i].substr(9,2))*3600 + stoi(logs[i].substr(12,2))*60 + stoi(logs[i].substr(15,2));
        for(int i=start;i<end;i++){
            arr[i]++;
        }
        timeline.push_back({start,end});
    }
    
    sort(timeline.begin(),timeline.end());

    
    int p_time = stoi(play_time.substr(0,2))*3600 + stoi(play_time.substr(3,2))*60 + stoi(play_time.substr(6,2));
    int a_time = stoi(adv_time.substr(0,2))*3600 + stoi(adv_time.substr(3,2))*60 + stoi(adv_time.substr(6,2));
    
    int left = 0,right = p_time - a_time;
    
    long long maxsum = 0;
    int result = 0;
    
    for(int i=0;i<a_time;i++)maxsum += arr[i];
    
    long long sum = maxsum;    
    for(int i = a_time; i < p_time; i++){
        sum += arr[i] - arr[i - a_time];
        if(maxsum < sum) {
            maxsum = sum;
            result = i - a_time + 1;
        }
    }

    string s,m,h;
    s = to_string(result % 60);
    if(s.size() == 1)s = "0" + s;
    result /= 60;
    
    m = to_string(result % 60);
    if(m.size() == 1)m = "0" + m;
    result /= 60;
    
    h = to_string(result);
    if(h.size() == 1)h = "0" + h;
    answer = h + ":" + m + ":" + s;
    
    return answer;
}
