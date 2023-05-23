// author@nghethuat102, created on 2023-05-22  16:25:05
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector<int> row(n);
        for (int i = 0; i < n; ++i) {
            row[i] = i;
        }
        sort(row.rbegin(), row.rend(), [&](int x, int y) { return a[x][0] < a[y][0]; });
        vector<vector<vector<int>>> f(4, vector<vector<int>>(n, vector<int>(m)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                f[0][i][j] = a[row[i]][j];
                if (i > 0) {
                    f[0][i][j] = min(f[0][i][j], f[0][i - 1][j]);
                }
                if (j > 0) {
                    f[0][i][j] = min(f[0][i][j], f[0][i][j - 1]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j) {
                f[1][i][j] = a[row[i]][j];
                if (i > 0) {
                    f[1][i][j] = max(f[1][i][j], f[1][i - 1][j]);
                }
                if (j != m - 1) {
                    f[1][i][j] = max(f[1][i][j], f[1][i][j + 1]);
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                f[2][i][j] = a[row[i]][j];
                if (i != n - 1) {
                    f[2][i][j] = max(f[2][i][j], f[2][i + 1][j]);
                }
                if (j > 0) {
                    f[2][i][j] = max(f[2][i][j], f[2][i][j - 1]);
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                f[3][i][j] = a[row[i]][j];
                if (i != n - 1) {
                    f[3][i][j] = min(f[3][i][j], f[3][i + 1][j]);
                }
                if (j != m - 1) {
                    f[3][i][j] = min(f[3][i][j], f[3][i][j + 1]);
                }
            }
        }
        pair<string, int> result;
        for (int i = 0; i < n - 1 && result.first.empty(); ++i) {
            for (int j = 0; j < m - 1; ++j) {
                int x1 = f[0][i][j];
                int x2 = f[1][i][j + 1];
                int y1 = f[2][i + 1][j];
                int y2 = f[3][i + 1][j + 1];
                if (x1 > y1 && x2 < y2) {
                    result.first.assign(n, 'B');
                    for (int it = 0; it <= i; ++it) {
                        result.first[row[it]] = 'R';
                    }
                    result.second = j + 1;
                    break;
                }
            }
        }
        if (result.first.empty()) {
            cout << "NO\n";
        } else {
            cout << "YES\n" << result.first << " " << result.second << "\n";
        }
    }
    return 0;
}