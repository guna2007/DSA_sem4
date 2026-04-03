#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++)
    {
        mp[arr[i] - i]++;
    }
    int ans = 0;
    for(auto it : mp)    {
        int x = it.second;
        ans += (x * (x - 1)) / 2;
    }
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
