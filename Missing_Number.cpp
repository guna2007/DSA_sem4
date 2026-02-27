#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> arr(n - 1);
    ll sum = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    ll original = (n * (n + 1)) / 2;
    ll ans = original - sum;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
