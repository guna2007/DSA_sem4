#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll md = 998244353;

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

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // make len
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        ll x = a[i];
        if (x >= (ll)n - 1)
            b[i] = n;
        else
            b[i] = (int)x + 1;
    }

    sort(b.begin(), b.end());

    // make fact
    vector<ll> fc(n + 1), ic(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++)
        fc[i] = (fc[i - 1] * i) % md;

    ic[n] = pw(fc[n], md - 2);
    for (int i = n; i >= 1; i--)
        ic[i - 1] = (ic[i] * i) % md;

    // rook dp
    vector<ll> r(n + 1, 0);
    r[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int bi = b[i - 1];
        for (int j = i; j >= 1; j--)
        {
            if (bi >= j)
            {
                ll ad = (r[j - 1] * (ll)(bi - j + 1)) % md;
                r[j] += ad;
                if (r[j] >= md)
                    r[j] -= md;
            }
        }
    }

    // hit sum
    ll ans = 0;
    for (int j = k; j <= n; j++)
    {
        ll cur = r[j];
        cur = (cur * cb(j, k, fc, ic)) % md;
        cur = (cur * fc[n - j]) % md;

        if ((j - k) & 1)
        {
            ans -= cur;
            if (ans < 0)
                ans += md;
        }
        else
        {
            ans += cur;
            if (ans >= md)
                ans -= md;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}


