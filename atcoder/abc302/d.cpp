// author@nghethuat102, created on 2023-05-20  19:30:16
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    long long d;
    cin >> n >> m >> d;
    vector<long long> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<long long> b(m);
    for (auto& i : b) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = -1;
    for (auto i : a) {
        {
            auto it = lower_bound(b.begin(), b.end(), i - d);
            if (it != b.end()) {
                auto value = *it;
                if (i - d <= value && value <= i + d) {
                    ans = max(ans, i + value);
                }
            }
        }
        {
            auto it = upper_bound(b.begin(), b.end(), i + d);
            if (it != b.begin()) {
                --it;
                auto value = *it;
                if (i - d <= value && value <= i + d) {
                    ans = max(ans, i + value);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}