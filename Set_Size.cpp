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

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<long long> gaps;
    gaps.reserve(max(0, n - 1));
    for (int i = 1; i < n; i++)
    {
        gaps.push_back(arr[i] - arr[i - 1]);
    }
    sort(gaps.begin(), gaps.end());

    vector<long long> prefix(gaps.size() + 1, 0);
    for (int i = 0; i < (int)gaps.size(); i++)
    {
        prefix[i + 1] = prefix[i] + gaps[i];
    }

    while (m--)
    {
        long long x;
        cin >> x;

        int cnt = upper_bound(gaps.begin(), gaps.end(), x) - gaps.begin();
        long long ans = prefix[cnt] + 1LL * ((int)gaps.size() - cnt) * x + x;
        cout << ans << '\n';
    }
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
