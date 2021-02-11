#include <iostream>
#include <queue>
using namespace std;

class Bar {
public:
	vector<int> bar;
	int num;
};

queue<Bar> q;
vector<int> src, dst;

int L, n, n2;

vector<int> split(int idx, vector<int> v) {
	vector<int> m;
	for (int i = 0; i < idx; i++) {
		m.push_back(v[i]);
	}
	m.push_back(1); m.push_back(1);
	for (int i = idx + 1; i < v.size(); i++) {
		m.push_back(v[i]);
	}
	return m;
}

vector<int> merge(int idx, vector<int> v) {
	vector<int> m;
	for (int i = 0; i < idx; i++) {
		m.push_back(v[i]);
	}
	m.push_back(2);
	for (int i = idx + 2; i < v.size(); i++) {
		m.push_back(v[i]);
	}

	return m;
}

long long ans1 = 99999999, ans2;

void bfs() {
	q.push({ src,0 });

	while (!q.empty()) {
		Bar cur = q.front();
		if (dst == cur.bar) {
			ans1 = cur.num;
			ans2++;
		}
		q.pop();
		if (cur.num >= ans1)continue;
		for (int i = 0; i < cur.bar.size() - 1; i++) {
			Bar nxt;
			if (cur.bar[i] == 1 && cur.bar[i + 1] == 1) {
				nxt.bar = merge(i, cur.bar);
			}
			else if (cur.bar[i] == 2) {
				nxt.bar = split(i, cur.bar);
			}
			else {
				continue;
			}
			nxt.num = cur.num + 1;

			q.push(nxt);
		}
	}
}


int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	cin >> L >> n;
	int s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		src.push_back(s);
	}

	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> s;
		dst.push_back(s);
	}

	bfs();

	cout << ans1 << " " << ans2;

	return 0;
}