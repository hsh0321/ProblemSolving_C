#include <iostream>
#include <algorithm>
using namespace std;

int map[2][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		int a2, b2, c2;
		a2 = max(map[0][0], map[0][1]) + a;
		b2 = max(max(map[0][0], map[0][1]), map[0][2]) + b;
		c2 = max(map[0][1], map[0][2]) + c;

		map[0][0] = a2; map[0][1] = b2; map[0][2] = c2;

		int a3, b3, c3;
		a3 = min(map[1][0], map[1][1]) + a;
		b3 = min(min(map[1][0], map[1][1]), map[1][2]) + b;
		c3 = min(map[1][1], map[1][2]) + c;

		map[1][0] = a3; map[1][1] = b3; map[1][2] = c3;
	}

	cout << max(max(map[0][0], map[0][1]), map[0][2]) << " " << min(min(map[1][0], map[1][1]), map[1][2]);

	return 0;
}