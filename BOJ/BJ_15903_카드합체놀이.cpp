#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

int n, m;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int cost;

	for (int i = 0; i < n; i++) {
		cin >> cost;
		pq.push(cost);
	}

	for (int i = 0; i < m; i++) {
		ll a, b;
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}

	ll answer = 0;
	for (int i = 0; i < n; i++) {
		answer += pq.top();
		pq.pop();
	}

	cout << answer;
}