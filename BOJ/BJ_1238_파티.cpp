#include <iostream>
#include <queue>
#include <algorithm>
#define INF 99999999

using namespace std;

class node {
public:
	int n, weight;
};

int V, E, K;
int u, v, w;
vector<node> graph[10001];
int dist[1001][1001];

class cmp {
public:
	bool operator()(node n1, node n2) {
		return n1.weight > n2.weight;
	}
};

void dijkstra(int k) {
	priority_queue<node, vector<node>, cmp> pq;
	pq.push({ k,0 });
	while (!pq.empty()) {
		int n1 = pq.top().n, w1 = pq.top().weight;
		pq.pop();
		if (dist[k][n1] != INF)continue;
		dist[k][n1] = w1;
		for (int i = 0; i < graph[n1].size(); i++) {
			if (dist[k][graph[n1][i].n] != INF)continue;
			pq.push({ graph[n1][i].n,w1 + graph[n1][i].weight });
		}
	}
}

int answer[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> V >> E >> K; // 정점 간선 출발노드
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 1; i <= V; i++) {
		dijkstra(i);
	}

	int ans = 0;
	for (int i = 1; i <= V; i++) {
		answer[i] = dist[i][K] + dist[K][i];
		ans = max(ans, answer[i]);
	}

	cout << ans;
}