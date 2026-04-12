#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

ll addm(ll a, ll b, ll m)
{
    if (a >= m - b)
        return a - (m - b);
    return a + b;
}

ll mulm(ll a, ll b, ll m)
{
    ll r = 0;
    a %= m;
    b %= m;
    while (b > 0)
    {
        if (b & 1)
            r = addm(r, a, m);
        b >>= 1;
        if (b)
            a = addm(a, a, m);
    }
    return r;
}

ll pmm(ll a, ll e, ll m)
{
    ll r = 1 % m;
    while (e > 0)
    {
        if (e & 1)
            r = mulm(r, a, m);
        a = mulm(a, a, m);
        e >>= 1;
    }
    return r;
}

bool ispm(ll n)
{
    if (n < 2)
        return false;
    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n % p == 0)
            return n == p;
    }

    ll d = n - 1;
    int s = 0;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }

    ll tst[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (ll a : tst)
    {
        if (a % n == 0)
            continue;
        ll x = pmm(a % n, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool ok = false;
        for (int r = 1; r < s; r++)
        {
            x = mulm(x, x, n);
            if (x == n - 1)
            {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rho(ll n)
{
    if (n % 2 == 0)
        return 2;
    if (n % 3 == 0)
        return 3;

    while (true)
    {
        ll c = (ll)(rng() % (unsigned long long)(n - 1)) + 1;
        ll x = (ll)(rng() % (unsigned long long)(n - 2)) + 2;
        ll y = x;
        ll d = 1;

        while (d == 1)
        {
            x = (mulm(x, x, n) + c) % n;
            y = (mulm(y, y, n) + c) % n;
            y = (mulm(y, y, n) + c) % n;
            ll dif = x > y ? x - y : y - x;
            d = __gcd(dif, n);
        }
        if (d != n)
            return d;
    }
}

void fct(ll n, vector<ll> &f)
{
    if (n == 1)
        return;
    if (ispm(n))
    {
        f.push_back(n);
        return;
    }
    ll d = rho(n);
    fct(d, f);
    fct(n / d, f);
}

ll c3(ll x)
{
    if (x < 3)
        return 0;
    return x * (x - 1) * (x - 2) / 6;
}

bool can(ll lim, const vector<ll> &s, const vector<int> &mk, int m)
{
    int ms = 1 << m;
    vector<ll> ex(ms, 0);
    ll cnt = 0;

    // pick count
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] <= lim)
        {
            ex[mk[i]]++;
            cnt++;
        }
    }

    if (cnt < 3)
        return false;

    vector<ll> sb = ex;

    // sos sum
    for (int b = 0; b < m; b++)
    {
        for (int ms2 = 0; ms2 < ms; ms2++)
        {
            if (ms2 & (1 << b))
                sb[ms2] += sb[ms2 ^ (1 << b)];
        }
    }

    ll tot = 0;

    // ie sum
    for (int sub = 0; sub < ms; sub++)
    {
        ll w = c3(sb[sub]);
        int bt = __builtin_popcount((unsigned)sub);
        if (((m - bt) & 1) == 0)
            tot += w;
        else
            tot -= w;
    }

    return tot > 0;
}

void solve()
{
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> s(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> s[i] >> a[i];

    vector<ll> f;
    fct(x, f);
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());

    int m = (int)f.size();
    int ful = (1 << m) - 1;

    vector<int> mk(n, 0);
    for (int i = 0; i < n; i++)
    {
        int ms = 0;
        for (int b = 0; b < m; b++)
        {
            if (a[i] % f[b] == 0)
                ms |= (1 << b);
        }
        mk[i] = ms;
    }

    bool cov = false;

    // quick fail
    {
        int all = 0;
        for (int i = 0; i < n; i++)
            all |= mk[i];
        cov = (all == ful);
    }

    if (!cov)
    {
        cout << -1 << "\n";
        return;
    }

    ll lo = (ll)1e18, hi = 0;
    for (int i = 0; i < n; i++)
    {
        lo = min(lo, s[i]);
        hi = max(hi, s[i]);
    }

    if (!can(hi, s, mk, m))
    {
        cout << -1 << "\n";
        return;
    }

    // bin ans
    while (lo < hi)
    {
        ll md = lo + (hi - lo) / 2;
        if (can(md, s, mk, m))
            hi = md;
        else
            lo = md + 1;
    }

    cout << lo << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
