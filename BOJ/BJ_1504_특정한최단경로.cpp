//
//  BJ_1504_특정한최단경로.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/24.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 987654321;
int N, E, v1, v2, ans = INF;
int sToV1, sToV2, v1ToV2, v2ToN, V2ToN;
vector<pair<int, int>> v[801];
int dist[801];

void dijkstra(int start){
    for (int i = 0; i <= N; i++)
        dist[i] = INF; // 초기화
    
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0,start }); // 현재까지 거리, 현재 위치
    while (!q.empty()) {
        int cur = q.top().second;
        int curDist = q.top().first;
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nextDist = v[cur][i].second;
            if (dist[next] > curDist + nextDist) {
                dist[next] = curDist + nextDist;
                q.push({ dist[next],next });
            }
        }
    }
}

int main(){
    cin >> N >> E;
    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    cin >> v1 >> v2;

    dijkstra(1);
    sToV1 = dist[v1];
    sToV2 = dist[v2];

    dijkstra(v1);
    v1ToV2 = dist[v2];
    v2ToN = dist[N];

    dijkstra(v2);
    V2ToN = dist[N];


    ans = min(ans,min(sToV1 + v1ToV2 + V2ToN,sToV2 + v1ToV2 + v2ToN));
    if (v1ToV2 == INF || ans == INF) cout << -1;
    else cout << ans;
}
