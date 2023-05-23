// author@nghethuat102, created on 2023-05-23  09:54:42
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    for (auto it : {make_pair("AB", "BA"), make_pair("BA", "AB")}) {
        int ns = (int)s.size();
        bool good = false;
        for (int i = 1; i < ns && !good; ++i) {
            if (s[i - 1] == it.first[0] && s[i] == it.first[1]) {
                for (int j = i + 2; j < ns; ++j) {
                    if (s[j - 1] == it.second[0] && s[j] == it.second[1]) {
                        good = true;
                        break;
                    }
                }
            }
        }
        if (good) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}