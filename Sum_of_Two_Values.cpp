#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<ll, ll> mp; // val,idx

    for (ll i = 0; i < n; i++)
    {
        ll diff = x - arr[i];
        if (mp.find(diff) != mp.end())
        {
            cout << mp[diff] + 1 << " " << i + 1;
            return;
        }
        mp[arr[i]] = i;
    }

    cout << "IMPOSSIBLE";
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
