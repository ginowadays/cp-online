// author@nghethuat102, created on 2023-05-22  20:48:30
#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long sum = 0;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if ((sum % n) * (n - 2) % n) {
            cout << "0\n";
            continue;
        }
        sum = sum - ((sum / n) * (n - 2) + (sum % n) * (n - 2) / n);

        map<long long, int> cnt;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += cnt[sum - a[i]];
            cnt[a[i]]++;
        }
        cout << ans << "\n";
    }
    return 0;
}