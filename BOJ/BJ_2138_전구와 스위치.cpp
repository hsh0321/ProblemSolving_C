//
//  BJ_2138_전구와 스위치.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/06/07.
//
// https://henry121407.tistory.com/72

#include <iostream>
#include <string>
#include <algorithm>

#define INF 100001
using namespace std;
 
int n,ans=INF;
string s1,s2,e;
 
void go(string& s,int now,int cnt)
{
    if(now==n-1)
    {
        if(s[now-1]==e[now-1] && s[now]==e[now])
            ans=min(ans,cnt);
        for(int i=now-1;i<=now;i++)
            if(s[i]=='0') s[i]='1'; else s[i]='0';
        if(s[now-1]==e[now-1] && s[now]==e[now])
            ans=min(ans,cnt+1);
        return;
    }
    // 현재 스위치를 안 누른 경우
    if(s[now-1]==e[now-1]) go(s,now+1,cnt);
    // 현재 스위치를 누른 경우
    for(int i=now-1;i<=now+1;i++)
        if(s[i]=='0') s[i]='1'; else s[i]='0';
    if(s[now-1]==e[now-1]) go(s,now+1,cnt+1);
}
 
int main()
{
    cin>>n>>s1>>e;
    s2=s1;
    for(int i=0;i<=1;i++)
        if(s2[i]=='0') s2[i]='1'; else s2[i]='0';
    // 0번째 스위치 안 눌렀을 경우, 눌렀을 경우
    go(s1,1,0);
    go(s2,1,1);
    cout << (ans == INF ? -1:ans);
    
    return 0;
}
