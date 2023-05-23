// author@nghethuat102, created on 2023-05-22  18:05:50
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n + m);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int u = i + m;
    for (int j = 0; j < x; ++j) {
      int v;
      cin >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
  }
  return 0;
}