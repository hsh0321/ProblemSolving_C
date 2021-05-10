#include<iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int arr[200];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[200];
    int max = 0;
    for (int i = 0; i < n; i++) { 
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i]++;
            }
        }
        if (max < dp[i]) max = dp[i];
        
    }

    cout << n - max << '\n';
    return 0;
}
