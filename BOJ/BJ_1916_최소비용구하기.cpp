//
//  BJ_1916_최소비용구하기.cpp
//  asddas
//
//  Created by 황성현 on 2021/03/28.
//

#include <iostream>
#include <queue>

#define INF 100000000;

using namespace std;


vector<pair<int,int>> graph[1001];

struct cmp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.second > p2.second;
    }
};


int d[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin >> N >> M;
    
    for(int i=0;i<=N;i++)
        d[i] = INF;
    
    
    for(int i=0;i<M;i++){
        int s,d,w;
        cin >> s >> d >> w;
        graph[s].push_back({d,w});
    }
    
    int start,end;
    cin >> start >> end;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({start,0});
    d[start] = 0;
    while(!pq.empty()){
        int cur = pq.top().first;
        int dist = pq.top().second;
        pq.pop();
        if(d[cur] < dist)continue;
        for(int i=0;i<graph[cur].size();i++){
            int nxt = graph[cur][i].first;
            int nxtDist = dist + graph[cur][i].second;
            if(nxtDist < d[nxt]){
                d[nxt] = nxtDist;
                pq.push({nxt,nxtDist});
            }
        }
    }
 
    cout << d[end] << endl;
}
