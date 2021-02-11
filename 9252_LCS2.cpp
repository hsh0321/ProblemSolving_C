#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(void) {
	string str1;
	string str2;
	string s;
	cin >> str1 >> str2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 1; i <= len1; i++)
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

	while (dp[len1][len2] != 0) {
		if (dp[len1][len2] == dp[len1][len2 - 1]) //¿ÞÂÊ ºñ±³
			len2--;
		else if (dp[len1][len2] == dp[len1 - 1][len2]) //À­ÂÊ ºñ±³
			len1--;
		else if (dp[len1][len2] - 1 == dp[len1 - 1][len2 - 1]) {
			s.push_back(str1[len1 - 1]);
			len1--;
			len2--;
		}
	}

	cout << dp[str1.size()][str2.size()] << '\n';

	int size = s.size();
	while (size--) {
		cout << s[size];
	}
	return 0;
}