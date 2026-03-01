#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x, y;
    cin >> x >> y;

    ll i = max(x, y);
    ll j = i * i - i + 1;

    ll ans = j;

    if (x > y)
    {
        if (x % 2 == 0)
            ans += x - y;
        else
            ans += y - x;
    }
    else
    {
        if (y % 2 == 0)
            ans += x - y;
        else
            ans += y - x;
    }

    cout << ans << endl;
}

// ll f(ll y, ll x) {
//     ll m = max(y, x);
//     ll r = (m - 1) * (m - 1);
//     if (m % 2 == 0) {
//         r += y + m - x;
//     } else {
//         r += x + m - y;
//     }
//     return r;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
