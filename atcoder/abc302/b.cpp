// author@nghethuat102, created on 2023-05-20  19:17:12
#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    const string target = "snuke";
    function<bool(int, int, vector<pair<int, int>>&)> check = [&](int x, int y, vector<pair<int, int>>& ans) {
        for (int i = 0; i < 8; ++i) {
            int xx = x;
            int yy = y;
            bool good = true;
            vector<pair<int, int>> tmp;
            for (auto it : target) {
                tmp.emplace_back(xx, yy);
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] != it) {
                    good = false;
                    break;
                }
                xx += dx[i];
                yy += dy[i];
            }
            if (good) {
                ans = tmp;
                return true;
            }
        }
        return false;
    };
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (check(i, j, ans)) {
                for (auto it : ans) {
                    cout << it.first + 1 << " " << it.second + 1 << "\n";
                }
                return 0;
            }
        }
    }
    assert(false);
    return 0;
}