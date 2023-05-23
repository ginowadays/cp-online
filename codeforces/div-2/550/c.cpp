// author@nghethuat102, created on 2023-05-23  10:08:09
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    int n = (int)s.size();
    // 1
    for (int i = 0; i < n; ++i) {
        int num = s[i] - '0';
        if (num % 8 == 0) {
            cout << "YES\n" << num << "\n";
            return 0;
        }
    }
    // 2
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == '0') {
                continue;
            }
            int num = (s[i] - '0') * 10 + (s[j] - '0');
            if (num % 8 == 0) {
                cout << "YES\n" << num << "\n";
                return 0;
            }
        }
    }
    // 3
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int t = j + 1; t < n; ++t) {
                if (s[i] == '0') {
                    continue;
                }
                int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[t] - '0');
                if (num % 8 == 0) {
                    cout << "YES\n" << num << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}