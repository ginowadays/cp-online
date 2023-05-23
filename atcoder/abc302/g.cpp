// author@nghethuat102, created on 2023-05-20  19:49:04
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(5, 0);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[a[i]]++;
    }
    for (int i = 1; i <= 4; ++i) {
        p[i] += p[i - 1];
    }
    vector<vector<int>> cnt(5, vector<int>(5, 0));
    for (int i = 0; i < n; ++i) {
        int pos = -1;
        for (int j = 1; j <= 4; ++j) {
            if (p[j - 1] <= i && i <= p[j] - 1) {
                pos = j;
                break;
            }
        }
        assert(pos != -1);
        if (pos != a[i]) {
            cnt[pos][a[i]]++;
        }
    }
    int ans = 0;
    // 2
    for (int x = 1; x <= 4; ++x) {
        for (int y = 1; y <= 4; ++y) {
            if (x == y) {
                continue;
            }
            while (cnt[x][y] > 0 && cnt[y][x] > 0) {
                cnt[x][y]--;
                cnt[y][x]--;
                ans++;
            }
        }
    }
    // 3
    for (int x = 1; x <= 4; ++x) {
        for (int y = 1; y <= 4; ++y) {
            for (int z = 1; z <= 4; ++z) {
                if (x == y || x == z || y == z) {
                    continue;
                }
                while (cnt[x][y] > 0 && cnt[y][z] > 0 && cnt[z][x] > 0) {
                    ++ans;
                    ++ans;
                    cnt[x][y]--;
                    cnt[y][z]--;
                    cnt[z][x]--;
                }
            }
        }
    }
    // 4
    for (int x = 1; x <= 4; ++x) {
        for (int y = 1; y <= 4; ++y) {
            for (int z = 1; z <= 4; ++z) {
                for (int t = 1; t <= 4; ++t) {
                    if (x == y || x == z || x == t || y == z || y == t || z == t) {
                        continue;
                    }
                    while (cnt[x][y] > 0 && cnt[y][z] > 0 && cnt[z][t] > 0 && cnt[t][x] > 0) {
                        ++ans;
                        ++ans;
                        ++ans;
                        cnt[x][y]--;
                        cnt[y][z]--;
                        cnt[z][t]--;
                        cnt[t][x]--;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

/**

1: 4
2: 1
3: 
4: 2

*/