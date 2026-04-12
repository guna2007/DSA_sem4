#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll md = 1000000007;

ll pw(ll a, ll e)
{
    ll r = 1;
    while (e > 0)
    {
        if (e & 1)
            r = (r * a) % md;
        a = (a * a) % md;
        e >>= 1;
    }
    return r;
}

ll cb(int n, int k, const vector<ll> &fc, const vector<ll> &ic)
{
    if (k < 0 || k > n)
        return 0;
    return (((fc[n] * ic[k]) % md) * ic[n - k]) % md;
}

ll getans(int n, int k, const vector<int> &a)
{
    // make fact
    vector<ll> fc(n + 1), ic(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++)
        fc[i] = (fc[i - 1] * i) % md;

    ic[n] = pw(fc[n], md - 2);
    for (int i = n; i >= 1; i--)
        ic[i - 1] = (ic[i] * i) % md;

    // count val
    map<int, int> mp;
    for (int x : a)
        mp[x]++;

    // count fr
    map<int, ll> fmp;
    for (auto &p : mp)
        fmp[p.second]++;

    vector<pair<int, ll>> v;
    for (auto &p : fmp)
        v.push_back(p);

    ll m = (ll)mp.size();

    // sum one
    ll t = 0;
    for (auto &p : v)
    {
        int f = p.first;
        ll c = p.second % md;
        t = (t + (c * cb(f, k, fc, ic)) % md) % md;
    }

    // sum pair
    ll s = 0;
    int z = (int)v.size();
    ll iv2 = pw(2, md - 2);
    for (int i = 0; i < z; i++)
    {
        int f1 = v[i].first;
        ll c1 = v[i].second % md;
        for (int j = i; j < z; j++)
        {
            int f2 = v[j].first;
            ll c2 = v[j].second % md;

            ll pr;
            if (i == j)
            {
                pr = (c1 * ((c1 - 1 + md) % md)) % md;
                pr = (pr * iv2) % md;
            }
            else
            {
                pr = (c1 * c2) % md;
            }

            ll w = 0;
            if (f1 + f2 <= n)
                w = cb(f1 + f2, k, fc, ic);
            s = (s + (pr * w) % md) % md;
        }
    }

    ll bad = (((m - 1 + md) % md) * t) % md;
    ll ans = (s - bad + md) % md;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << getans(n, k, a) << "\n";

    return 0;
}
