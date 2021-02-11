#include <iostream>
using namespace std;

int dp[10][101];

int main()
{

	int n;
	int sum = 0;

	cin >> n;

	for (int i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[0][i] = dp[1][i - 1];
			else if (j == 9)
				dp[9][i] = dp[8][i - 1];
			else
				dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % 1000000000;
		}
	}
	for (int i = 1; i < 10; i++)
		sum = (sum + dp[i][n]) % 1000000000;

	cout << sum;
}