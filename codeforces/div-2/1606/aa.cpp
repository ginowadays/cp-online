// author@nghethuat102, created on 2023-05-22  11:20:20
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s[0] != s.back()) {
            cout << s.back() << s.substr(1) << "\n";
        } else {
            cout << s << "\n";
        }
    }
    return 0;
}