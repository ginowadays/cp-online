// author@nghethuat102, created on 2023-05-22  19:50:50
#include <bits/stdc++.h>
using namespace std;

struct OP {
    int u;
    int v;
    int lab_u;
    int lab_v;
    int cnt_u;
    int result;
    int tt;

    OP(int u, int v, int lab_u, int lab_v, int cnt_u, int result)
        : u(u), v(v), lab_u(lab_u), lab_v(lab_v), cnt_u(cnt_u), result(result), tt(1) {
    }

    OP(int u, int cnt_u, int result) : u(u), cnt_u(cnt_u), result(result), tt(2) {
    }
};

struct DSU {
    int result;
    vector<int> lab;
    vector<int> cnt;
    stack<OP> history;

    DSU(int n) {
        lab.resize(n, -1);
        cnt.assign(n, 0);
        result = 0;
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            history.push(OP(u, cnt[u], result));
            result -= min(-lab[u], cnt[u]);
            cnt[u]++;
            result += min(-lab[u], cnt[u]);
        } else {
            if (lab[u] > lab[v]) {
                swap(u, v);
            }
            history.push(OP(u, v, lab[u], lab[v], cnt[u], result));
            result -= min(-lab[u], cnt[u]);
            result -= min(-lab[v], cnt[v]);
            lab[u] += lab[v];
            lab[v] = u;
            cnt[u] += cnt[v] + 1;
            result += min(-lab[u], cnt[u]);
        }
    }

    int find(int u) {
        return lab[u] < 0 ? u : find(lab[u]);
    }

    void rollback() {
        assert(history.size());
        auto it = history.top();
        history.pop();
        if (it.tt == 1) {
            int u = it.u;
            int v = it.v;
            cnt[u] = it.cnt_u;
            lab[u] = it.lab_u;
            lab[v] = it.lab_v;
            result = it.result;
        } else {
            result = it.result;
            cnt[it.u] = it.cnt_u;
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first;
        --a[i].second;
    }
    vector<vector<int>> e(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> result(n);

    DSU dsu(n);

    function<void(int, int)> dfs = [&](int u, int par_u) {
        dsu.merge(a[u].first, a[u].second);
        result[u] = dsu.result;
        for (auto v : e[u]) {
            if (v != par_u) {
                dfs(v, u);
            }
        }
        dsu.rollback();
    };

    dfs(0, -1);

    for (int i = 1; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}