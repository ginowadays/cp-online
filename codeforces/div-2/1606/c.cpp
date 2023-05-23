// author@nghethuat102, created on 2023-05-22  10:40:10
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        ++k;
        vector<long long> a(n);
        vector<long long> p(10);
        p[0] = 1;
        for (int i = 1; i <= 9; ++i) {
            p[i] = p[i - 1] * 10;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long ans = 0;
        for (int i = 0; i < n - 1 && k > 0; ++i) {
            long long serve = p[a[i + 1] - a[i]] - 1;
            if (k <= serve) {
                ans += k * p[a[i]];
                k = 0;
            } else {
                ans += serve * p[a[i]];
                k -= serve;
            }
        }
        if (k > 0) {
            ans += k * p[a[n - 1]];
        }
        cout << ans << "\n";
    }
    return 0;
}