// author@nghethuat102, created on 2023-05-23  10:16:39
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n + 2);
    vector<int> h(n + 2);
    x[0] = -2e9 - 10;
    x[n + 1] = 2e9 + 10;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> h[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (x[i] - h[i] > x[i - 1]) {
            ++ans;
            continue;
        }
        if (x[i] + h[i] < x[i + 1]) {
            ++ans;
            x[i] += h[i];
            continue;
        }
    }
    cout << ans << "\n";
    return 0;
}