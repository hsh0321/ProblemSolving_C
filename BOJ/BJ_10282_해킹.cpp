#include <bits/stdc++.h>
using namespace std;
int tt, n, connect, hacked, a, b, s;
vector<pair<int, int>> g[10001];
int d[10001];
const int INF=1e9;
 
void dijk() {
    priority_queue<pair<int, int>>pq;
    for (int i = 1; i <= n; i++) d[i] = INF;
    d[hacked] = 0; pq.push({ 0, hacked });
    while (!pq.empty()) {
        int x = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (d[x] != cost) continue;
        for (auto nxt : g[x]) {
            int nx = nxt.first;
            int nd = nxt.second + cost;
            if (d[nx] > nd) {
                d[nx] = nd;
                pq.push({ -d[nx], nx });
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> tt;
    while (tt--) {
        for (int i = 1; i <= n; i++) g[i].clear();        
        cin >> n >> connect >> hacked;
        while (connect--) {
            cin >> a >> b >> s;
            g[b].push_back({ a, s });
        }
        dijk();
        int cnt = 0; int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] == INF) continue;
            cnt++;
            ans = max(ans, d[i]);                    
        }
        cout << cnt << ' ' << ans << '\n';
    }
}
