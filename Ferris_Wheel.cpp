#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int l = 0, r = n - 1, ans = 0;
    while (l <= r)
    {
        if (arr[l] + arr[r] <= x)
        {
            ans++;
            l++;
            r--;
        }
        else
        {
            ans++;
            r--;
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
