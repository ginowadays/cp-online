// author@nghethuat102, created on 2023-05-20  19:24:47
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<bool>> good(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int it = 0; it < m; ++it) {
                cnt += (a[i][it] != a[j][it] ? 1 : 0);
            }
            good[i][j] = (cnt == 1);
        }
    }
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    while (true) {
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (!good[p[i - 1]][p[i]]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes\n";
            return 0;
        }
        if (!next_permutation(p.begin(), p.end())) {
            break;
        }
    }
    cout << "No\n";
    return 0;
}