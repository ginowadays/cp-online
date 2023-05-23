// author@nghethuat102, created on 2023-05-20  19:37:59
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ans = n;
    vector<set<int>> s(n + 1);
    while (m--) {
        char type;
        cin >> type;
        if (type == '1') {
            int u, v;
            cin >> u >> v;
            s[u].insert(v);
            s[v].insert(u);
            if (s[u].size() == 1) {
                --ans;
            }
            if (s[v].size() == 1) {
                --ans;
            }
        } else {
            int u;
            cin >> u;
            if (!s[u].empty()) {
                for (auto v : s[u]) {
                    s[v].erase(u);
                    if (s[v].empty()) {
                        ++ans;
                    }
                }
                s[u].clear();
                ++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}