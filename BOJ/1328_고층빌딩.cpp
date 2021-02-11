#include<iostream>

using namespace std;

long int dp[101][101][101];

int main() {

	int N, L, R;

	cin >> N >> L >> R;

	dp[1][1][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			for (int k = 1; k <= R; k++) {
				dp[i][j][k] = dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1];
				dp[i][j][k] %= 1000000007;
			}
		}
	}

	cout << dp[N][L][R];

	return 0;
}