#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            if (a[i] - b[j] <= k)
            {
                i++;
                ans++;
            }
            j++;
        }
        else
        {
            if (b[j] - a[i] <= k)
            {
                j++;
                ans++;
            }
            i++;
        }
    }
    cout << ans;
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
