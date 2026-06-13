#include <bits/stdc++.h>
using namespace std;

// Type Aliases for speed and clarity
using ll = long long;
using lli = long long int;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

// Common Macros
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define el '\n'
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second

const int MAXN = 200000 + 5;
const ll MOD = 998244353;

vll fact(MAXN), invFact(MAXN);

ll modPow(ll a, ll b)
{
    ll res = 1;

    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

void precompute()
{
    fact[0] = 1;

    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[MAXN - 1] = modPow(fact[MAXN - 1], MOD - 2);

    for (int i = MAXN - 2; i >= 0; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r)
{
    if (r < 0 || r > n)
    {
        return 0;
    }

    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

// Logic for a single test case
void solve()
{
    int n, k;
    cin >> n >> k;

    ll ans = 0;

    for (int i = 1; i <= k; i++)
    {
        ll waysPrefix =
            (modPow(i, k) - modPow(i - 1, k) + MOD) % MOD;

        ll waysSuffix =
            nCr(n - i, n - k);

        ans =
            (ans + waysPrefix * waysSuffix) % MOD;
    }

    cout << ans << el;
}

int main()
{
    fast_io;

    precompute();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}