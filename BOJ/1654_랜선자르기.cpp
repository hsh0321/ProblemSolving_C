#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal(vector<long long> l, long long len) {
	int num = 0;
	for (int i = 0; i < l.size(); i++) {
		num += l[i] / len;
	}
	return num;
}

int main() {
	int k, n;
	cin >> k >> n;

	long long len;
	vector<long long> line;
	long long m = 0;
	while (k--) {
		cin >> len;
		line.push_back(len);
		m = max(m, len);
	}


	long long left = 1;
	long long right = m;
	long long ans = 0;
	//int line_num = 0;
	while (left <= right) // 이분 탐색
	{ // 어떤 수까지를 이어 써야 k번째 수가 나오는지 확인
		long long mid = (left + right) / 2;
		long long line_num = cal(line, mid);
		if (n > line_num)
		{
			right = mid - 1;
		}
		else if (line_num >= n)
		{
			left = mid + 1;
		}
	}
	cout << right;

}