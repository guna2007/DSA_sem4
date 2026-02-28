#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll ans = 0;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
            continue;
        ans += arr[i - 1] - arr[i];
        arr[i] = arr[i - 1];
    }
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
