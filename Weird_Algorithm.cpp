#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    ll res = n;
    while (res != 1)
    {
        cout << res << " ";
        if (res % 2 == 0)
            res /= 2;
        else
        {
            res *= 3;
            res++;
        }
    }
    cout << 1;
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
