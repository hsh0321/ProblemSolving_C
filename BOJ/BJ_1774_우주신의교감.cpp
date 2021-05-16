#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
 
int N, M;
vector<pair<int, int>> pos;
double v[1001][1001];
int visited[1001];
double cost;
 
void prim(){
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    visited[1] = 1;
    for(int i = 2; i <= N; i++){
        int next = i;
        double nextCost = v[1][i];
        
        pq.push({nextCost, next});
    }
    
    while(!pq.empty()){
        int now = pq.top().second;
        double nowCost = pq.top().first;
        pq.pop();
        
        if(visited[now] == 0){
            visited[now] = 1;
            cost += nowCost;
        }
        else{
            continue;
        }
        
        for(int i = 1; i <= N; i++){
            int next = i;
            double nextCost = v[now][i];
            if(visited[next] == 0)pq.push({nextCost, next});
            
        }
    }
}
 
int main(){
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        int x, y;
        cin >> x >> y;
        
        pos.push_back({x, y});
    }
    
    for(int i = 0; i < pos.size(); i++){
        for(int j = 0; j < pos.size(); j++){
            if(i == j)continue;
            double weight = sqrt(pow(pos[i].first-pos[j].first, 2.0) + pow(pos[i].second-pos[j].second, 2.0));
            
            v[i+1][j+1] = weight;
        }
    }
    
    for(int i = 1; i <= M; i++){
        int src, dst;
        cin >> src >> dst;
        
        v[src][dst] = 0;
        v[dst][src] = 0;
    }
 
    prim();
    
    printf("%.2lf", cost);
        
    return 0;
}
