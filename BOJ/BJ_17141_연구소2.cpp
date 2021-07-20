//
//  연구소2.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/20.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[51][51];
int map2[51][51];
int visit[51][51];

int N,M;
int virus_num =0;
int empty_num = 0;
vector<pair<int,int>> virus;
vector<int> v;

int dr[4] = {1,-1,0,0},dc[4] = {0,0,1,-1};

int simulation(){
    int time = 0;
    int num = empty_num;
    
    queue<pair<int,int>> q;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            map[i][j] = map2[i][j];
    
    for(int i=0;i<virus_num;i++){
        if(!v[i]){ // 바이러스
            q.push(virus[i]);
            visit[virus[i].first][virus[i].second] = 1;
            
        }else{ // 바이러스 아님
            map[virus[i].first][virus[i].second] = 0;
            num++;
        }
    }
    
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            pair<int,int> nxt = {cur.first + dr[i],cur.second + dc[i]};
            if(nxt.first < 0 || nxt.first >= N || nxt.second < 0 || nxt.second >= N)continue;
            if(map[nxt.first][nxt.second] == 1)continue;
            if(visit[nxt.first][nxt.second] != 0)continue;
            visit[nxt.first][nxt.second] = visit[cur.first][cur.second] + 1;
            time = visit[nxt.first][nxt.second];
            q.push(nxt);
            num--;
        }
    }
    
//    cout << num << " " << time-1 << endl;
    if(num > 0)return -1;
    if(time == 0)return 0;
    return time-1;
}

int main(){
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map2[i][j];
            if(map2[i][j] == 2){
                virus.push_back({i,j});
                virus_num++;
            }else if(map2[i][j] == 0){
                empty_num++;
            }
        }
    }
    

    
    for(int i=0;i<M;i++)v.push_back(0);
    for(int i=0;i<virus_num-M;i++)v.push_back(1);
    
    
    int ans = 100000;
    do{
//        for(int i=0;i<v.size();i++)
//            cout << v[i] << " ";
//        cout << endl;
        
        int a = simulation();
        if(a != -1)ans = min(a,ans);
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                visit[i][j] = 0;
        
    }while(next_permutation(v.begin(),v.end()));
    
    if(ans == 100000)cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}
