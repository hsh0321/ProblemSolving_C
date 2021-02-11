#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, s;
	
	cin >> n >> s;

	vector<int> v;
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	int answer = 0;

	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))sum += v[j];
		}
		if (sum == s)answer++;
	}

	
	cout << answer << '\n';
}
