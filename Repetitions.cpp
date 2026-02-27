#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    int ans = 1;
    int res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            ans++;
        else
        {
            res = max(ans, res);
            ans = 1;
        }
    }
    res = max(ans, res);

    cout << res << endl;
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
