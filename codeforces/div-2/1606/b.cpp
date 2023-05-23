// author@nghethuat102, created on 2023-05-22  10:29:13
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long cur = 1;
        long long ans = 0;
        while (cur < min(n, k)) {
            cur <<= 1;
            ans++;
        }
        long long rem = max(0LL, n - cur);
        ans += (rem / k) + (rem % k ? 1 : 0);
        cout << ans << "\n";
    }
    return 0;
}