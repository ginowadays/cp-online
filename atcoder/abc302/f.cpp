// author@nghethuat102, created on 2023-05-20  20:05:46
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<set<int>> a(n);
    vector<set<int>> b(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            int val;
            cin >> val;
            --val;
            a[i].insert(val);
            b[val].insert(i);
        }
    }
    vector<bool> init(n);
    vector<bool> good(n);
    for (int i = 0; i < n; ++i) {
        good[i] = a[i].find(m - 1) != a[i].end();
        init[i] = a[i].find(0) != a[i].end();
    }
    vector<int> sub[2];
    int pre = 0;
    int cur = 1;
    vector<int> dp(n, -1);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (init[i]) {
            q.push(i);
            dp[i] = 0;
            for (auto j : a[i]) {
                b[j].erase(i);
            }
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto i : a[u]) {
            while (!b[i].empty()) {
                auto v = *b[i].begin();
                assert(dp[v] == -1);
                dp[v] = dp[u] + 1;
                q.push(v);
                for (auto j : a[v]) {
                    b[j].erase(v);
                }
            }
        }
    }
    int ans = (int)1e9;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            ans = min(ans, dp[i]);
        }
    }
    cout << (ans == (int)1e9 ? -1 : ans) << "\n";
    return 0;
}