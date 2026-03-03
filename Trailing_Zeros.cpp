#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    ll ans = 0;

    while (n > 0)
    {
        ans += n / 5;
        n /= 5;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;   // Make sure input actually provides t

    while (t--)
    {
        solve();
    }

    return 0;
}