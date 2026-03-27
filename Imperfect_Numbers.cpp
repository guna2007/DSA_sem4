#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    int ans = 1;
    if(n % 10 == 0) ans = 2;
    else if(n % 2 == 0 || n%5 == 0) ans = 0;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
