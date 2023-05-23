// author@nghethuat102, created on 2023-05-20  19:14:09
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long a, b;
  cin >> a >> b;
  cout << a / b + (a % b ? 1 : 0) << "\n";
  return 0;
}