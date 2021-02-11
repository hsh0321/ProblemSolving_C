#include <iostream>
#include <queue>
using namespace std;

int N, M, k; // 맵 상어수 이동수

struct shark {
	bool isAlive = true;
	int x, y; // 위치
	int cDir; // 현재 방향
	int pDir[5][5];
};

struct smell {
	int sNum;
	int x, y;
	int sec;
};

int map[21][21];
int time[21][21];

shark s[400];
int dx[5] = { 0, 0,0,-1,1 }, dy[5] = { 0,-1,1,0,0 }; // 상 하 좌 우

void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << " // ";
		for (int j = 0; j < N; j++) {
			cout << time[i][j] << " ";
		}
		cout << endl;
	}

}


bool colider(int n) {
	for (int i = 1; i < n; i++) {
		if (s[n].x == s[i].x && s[n].y == s[i].y) {
			s[n].isAlive = false;
			//충돌
			return true;
		}
	}
	return false;
}

void move(int n) {
	smell prev;
	prev.x = 0; prev.y = 0; prev.sec = 0; prev.sNum = 0;
	int dir;
	bool b = false;
	for (int i = 0; i < 4; i++) {
		smell tmp;
		tmp.sNum = n;
		tmp.x = s[n].x + dx[s[n].pDir[s[n].cDir][i]];
		tmp.y = s[n].y + dy[s[n].pDir[s[n].cDir][i]];
		if (map[tmp.y][tmp.x] == 0 && tmp.y >= 0 && tmp.x >= 0 && tmp.y < N && tmp.x < N) { // 냄새 없는 곳 + 맵 안
			s[n].x = tmp.x; s[n].y = tmp.y;
			s[n].cDir = s[n].pDir[s[n].cDir][i];
			if (colider(n) == true) {
				s[n].isAlive = false;
				return;
			}

			return;
		}
		else if (map[tmp.y][tmp.x] == n && b == false) {
			prev = tmp;
			b = true;
		}
	}

	if (prev.x - s[n].x == -1) {
		s[n].cDir = 3;
	}
	else if (prev.x - s[n].x == 0) {
		if (s[n].y - prev.y == 1) {
			s[n].cDir = 1;
		}
		else {
			s[n].cDir = 2;
		}
	}
	else {
		s[n].cDir = 4;
	}
	s[n].x = prev.x; s[n].y = prev.y;
}

void timer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (time[i][j] != 0) {
				time[i][j] -= 1;
				if (time[i][j] == 0) {
					map[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M >> k;

	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				s[map[i][j]].x = j; s[map[i][j]].y = i;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> s[i].cDir;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j < 5; j++) { // 상1하2좌3우4 
			for (int k = 0; k < 4; k++) { // 우선순위 
				cin >> s[i].pDir[j][k];
			}
		}
	}

	int sec = 0;
	int nofS = M; // 남은 상어

	

	for (;;) {
		for (int i = 1; i <= M; i++) { // 제자리 냄새 채우기
			if (s[i].isAlive) {
				//if (colider(i) == true) {
				//	continue;
				//}
				smell tmp;
				tmp.sec = sec; tmp.sNum = i; tmp.x = s[i].x; tmp.y = s[i].y;
				time[tmp.y][tmp.x] = k;
				map[tmp.y][tmp.x] = tmp.sNum;

				move(i);
			}
		}

		timer();
		//printMap();
		//cout << endl;

		sec++;
		if (sec > 1000)break;
		int k = 0;
		for (int i = 2; i <= M; i++) { // 2번상어부터 생존검사
			if (s[i].isAlive == true)break;
			else {
				k++;
			}
		}
		if (k == M - 1) break;
	}

	if (sec > 1000) {
		cout << -1;
	}
	else {
		cout << sec;
	}
	return 0;
}