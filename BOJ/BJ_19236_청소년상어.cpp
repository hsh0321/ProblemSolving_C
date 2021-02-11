#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int answer;

class Fish {
public:
	bool isAlive = true;
	int x, y;
	int dir;
};

class Map {
public:
	Fish fish[17];
	Fish shark;
	int m[4][4];
	int cost = 0;
};

Map map;

int dx[8] = { 0,-1,-1,-1,0,1,1,1 }, dy[8] = { -1,-1,0,1,1,1,0,-1 }; //↑, ↖, ←, ↙, ↓, ↘, →, ↗ 

void print(Map m) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << m.m[i][j] << " ";
		}
		cout << " ";
		for (int j = 0; j < 4; j++) {
			if (m.m[i][j] == -1)cout << m.shark.dir << " ";
			else {
				cout << m.fish[m.m[i][j]].dir << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void fish_move(Map& myMap, int f) {
	int cur_dir = myMap.fish[f].dir;
	Fish tmp = myMap.fish[f];
	for (int i = 0; i < 8; i++, cur_dir++) {
		cur_dir %= 8;
		int nx = myMap.fish[f].x + dx[cur_dir];
		int ny = myMap.fish[f].y + dy[cur_dir];
		if (myMap.m[ny][nx] == -1)continue; // 상어
		if (nx < 0 || ny < 0 || nx > 3 || ny > 3)continue; // 공간 밖

		if (myMap.m[ny][nx] > 0) { // 물고기 위치 바꾸기
			int t = myMap.m[ny][nx]; // 바꿀 물고기 번호 
			swap(myMap.m[ny][nx], myMap.m[myMap.fish[f].y][myMap.fish[f].x]);
			swap(myMap.fish[t].x, myMap.fish[f].x);
			swap(myMap.fish[t].y, myMap.fish[f].y);
			myMap.fish[f].dir = cur_dir;
			break;
		}
		else if (myMap.m[ny][nx] == 0) {
			myMap.m[ny][nx] = f;
			myMap.fish[f].x = nx; myMap.fish[f].y = ny; myMap.fish[f].dir = cur_dir;

			myMap.m[tmp.y][tmp.x] = 0;
			break;
		}
		cout << "error";
	}
}

int bfs() {
	queue<Map> q;

	q.push(map);

	int maximum = 0;
	//print(map);
	while (!q.empty()) {
		Map cur = q.front();
		q.pop();
		for (int i = 1; i < 4; i++) {
			Map nxt;
			nxt = cur;

			for (int i = 1; i <= 16; i++) {
				if (nxt.fish[i].isAlive == true) {
					fish_move(nxt, i);
				}
			}
			;
			int nx = nxt.shark.x + (dx[nxt.shark.dir] * i);
			int ny = nxt.shark.y + (dy[nxt.shark.dir] * i);
			if (nx < 0 || nx > 3 || ny < 0 || ny > 3)continue; // 범위 밖
			if (nxt.m[ny][nx] == 0)continue; // 물고기 없음.

			nxt.shark.dir = nxt.fish[nxt.m[ny][nx]].dir; // 방향
			nxt.m[nxt.shark.y][nxt.shark.x] = 0;
			nxt.shark.x = nx; nxt.shark.y = ny; // 상어위치
			nxt.cost += nxt.m[ny][nx]; // 비용
			nxt.fish[nxt.m[ny][nx]].isAlive = false; // 죽음
			nxt.m[ny][nx] = -1; // 맵

			maximum = max(maximum, nxt.cost);

			//print(nxt);
			q.push(nxt);
		}
	}
	return maximum;
}


int main() {
	int a, b;
	int answer = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			map.fish[a].x = j; map.fish[a].y = i;
			map.fish[a].dir = b - 1;
			map.m[i][j] = a;
		}
	}

	// 초기 상태
	map.shark.dir = map.fish[map.m[0][0]].dir;
	map.shark.x = 0; map.shark.y = 0;
	map.fish[map.m[0][0]].isAlive = false;
	map.cost = map.m[0][0];
	map.m[0][0] = -1;

	cout << bfs();

	return 0;
}