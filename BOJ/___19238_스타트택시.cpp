#include <iostream>
#include <queue>
#define WALL -999999
using namespace std;

int N, M, init_fuel;
int map[25][25];
int visit[25][25];
int dx[4] = { 0,-1,1,0 }, dy[4] = { -1,0,0,1 }; // 열 행

class Point {
public:
	int x, y, idx;
};

vector<Point> src, dst;

void clear() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = 0;
		}
	}
}

int bfs(Point p, int fuel, int cnt, int check) {
	queue<Point> q;
	q.push(p);
	visit[p.y][p.x] = 1;
	if (cnt % 2 == 0) { // 도착지랑 출발지랑 같을 때
		for (int i = 0; i < src.size(); i++) {
			if (src[i].y == WALL)continue;
			if (src[i].y == p.y && src[i].x == p.x) {
				int tmp = src[i].idx;
				src[i].x = WALL; src[i].y = WALL;
				--cnt;
				return bfs(p, fuel, cnt, -1 * tmp);
			}
		}
	}
	while (!q.empty()) {
		Point cur;
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Point nxt;
			nxt.x = cur.x + dx[i]; nxt.y = cur.y + dy[i];
			if (nxt.x <= 0 || nxt.y <= 0 || nxt.x > N || nxt.y > N)continue;
			if (map[nxt.y][nxt.x] == WALL)continue;
			if (visit[nxt.y][nxt.x] != 0)continue;

			visit[nxt.y][nxt.x] = visit[cur.y][cur.x] + 1;
			q.push(nxt);
			if (cnt % 2 == 0) { // 출발지
				for (int i = 0; i < src.size(); i++) {
					if (src[i].x == nxt.x && src[i].y == nxt.y) {

						fuel -= (visit[src[i].y][src[i].x] - 1);
						if (fuel <= 0) {
							return -1;
						}
						else {
							src[i].x = WALL; src[i].y = WALL;
							cnt--;
							clear();
							return bfs(nxt, fuel, cnt, -1 * src[i].idx);
						}
					}
				}
			}
			else { // 도착지
				for (int i = 0; i < dst.size(); i++) {
					if (dst[i].x == nxt.x && dst[i].y == nxt.y && check == dst[i].idx) { // 찾았을 때
						fuel -= (visit[nxt.y][nxt.x] - 1);
						if (fuel < 0) {
							return -1;
						}
						else {
							fuel += (2 * (visit[nxt.y][nxt.x] - 1));
							dst[i].x = WALL; dst[i].y = WALL;
							cnt--;
							if (cnt == 0)return fuel;
							clear();
							return bfs(nxt, fuel, cnt, 0);
						}
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M >> init_fuel;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)map[i][j] = WALL;
		}
	}

	Point start;
	cin >> start.y >> start.x; // y, x

	Point s, d;
	for (int i = 1; i <= M; i++) {
		cin >> s.y >> s.x >> d.y >> d.x;
		s.idx = i; d.idx = -i;
		src.push_back(s);
		dst.push_back(d);
	}

	cout << bfs(start, init_fuel, 2 * M, 0);

	return 0;
}