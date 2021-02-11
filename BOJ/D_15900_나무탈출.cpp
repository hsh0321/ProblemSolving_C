#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, result;
vector<vector<int>> adj;
int visited[500002];
bool flag = false;

void bfs() {
	visited[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		bool notleaf = false;
		int curr = q.front();
		q.pop();
		for (auto next : adj[curr]) {
			if (visited[next] == 0) {
				visited[next] = visited[curr] + 1;
				notleaf = true;
				q.push(next);
			}
		}
		if (!notleaf) result = result + visited[curr] - 1;
	}

}
int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	adj.resize(N + 1);
	int T = N - 1;
	while (T--) {
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}
	bfs();
	if (result % 2 == 1) cout << "Yes" << '\n';
	else cout << "No" << '\n';

	return 0;
}