// author@nghethuat102, created on 2023-05-22  10:15:11
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        s = "x" + s + "y";
        int ab = 0;
        int ba = 0;
        for (int i = 2; i <= n; ++i) {
            if (s[i] == 'a' && s[i - 1] == 'b') {
                ++ba;
            }
            if (s[i] == 'b' && s[i - 1] == 'a') {
                ++ab;
            }
        }
        for (int i = 1; i <= n && ab != ba; ++i) {
            int more_ab = -1;
            int more_ba = -1;
            if (s[i] == 'a') {
                more_ab = (s[i - 1] == 'a' ? 1 : 0) - (s[i + 1] == 'b' ? 1 : 0);
                more_ba = (s[i + 1] == 'a' ? 1 : 0) - (s[i - 1] == 'b' ? 1 : 0);
            } else {
                more_ab = (s[i + 1] == 'b' ? 1 : 0) - (s[i - 1] == 'a' ? 1 : 0);
                more_ba = (s[i - 1] == 'b' ? 1 : 0) - (s[i + 1] == 'a' ? 1 : 0);
            }
            if (abs(ab - ba) > abs((ab + more_ab) - (ba + more_ba))) {
                s[i] = (s[i] == 'a' ? 'b' : 'a');
                ab += more_ab;
                ba += more_ba;
            }
        }
        cout << s.substr(1, n) << "\n";
    }
    return 0;
}