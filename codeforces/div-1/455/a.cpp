// author@nghethuat102, created on 2023-05-23  09:45:12
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    const int m = 100000;
    vector<int> a(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        a[val]++;
    }
    vector<vector<long long>> dp(m + 1, vector<long long>(2));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + 1LL * i * a[i];
    }
    cout << max(dp[m][0], dp[m][1]) << "\n";
    return 0;   
}