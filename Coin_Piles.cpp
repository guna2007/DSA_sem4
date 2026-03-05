#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll x, y;
    cin >> x >> y;

    if ((x + y) % 3 == 0 && max(x,y) <= 2 * min(x,y))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}