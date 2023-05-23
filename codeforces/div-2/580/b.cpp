// author@nghethuat102, created on 2023-05-23  10:32:20
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    long long d;
    cin >> n >> d;
    vector<pair<int, int>> a(n);
    for (auto& i : a) {
        cin >> i.first >> i.second;
    }
    sort(a.begin(), a.end());
    int j = 0;
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i].second;
        while (j <= i && a[j].first + d <= a[i].first) {
            sum -= a[j].second;
            ++j;
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}