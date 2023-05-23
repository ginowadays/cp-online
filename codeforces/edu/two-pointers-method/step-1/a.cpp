// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
// author@nghethuat102, created on 2023-05-22  09:55:19
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : b) {
        cin >> i;
    }
    int i = 0;
    int na = a.size();
    int j = 0;
    int nb = b.size();
    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            cout << a[i++] << " ";
        } else {
            cout << b[j++] << " ";
        }
    }
    while (i < na) {
        cout << a[i++] << " ";
    }
    while (j < nb) {
        cout << b[j++] << " ";
    }
    cout << "\n";
    return 0;
}