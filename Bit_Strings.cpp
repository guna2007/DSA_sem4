#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ll power(ll base, ll exp, ll mod)
// {
//     ll result = 1;
//     base %= mod;
//     while (exp > 0)
//     {
//         if (exp & 1)
//         {
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         exp >>= 1;
//     }
//     return result;
// }
ll mod = 1e9 + 7;

ll power(ll x,ll n)
{
    ll ans = 1;

    while(n > 0)
    {
        if(n % 2 == 1)
        {
            ans = (ans * x) % mod;
            n = n-1;
        }
        else
        {
            x = ( x * x) % mod;
            n = n/2;
        }
    }

    return ans;
}

void solve()
{
    ll n;
    cin >> n;

    ll ans = power(2, n);
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
