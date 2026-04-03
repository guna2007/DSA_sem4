#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int check(vector<int> &arr, int mid)
{
    int res = 0;
    for (int &i : arr)
    {
        res += i / mid;
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;

    int l = 1, r = accumulate(arr.begin(), arr.end(), 0) / m;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(arr, mid) >= m)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

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
