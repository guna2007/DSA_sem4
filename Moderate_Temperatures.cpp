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
    
    int maxi = *std::max_element(arr.begin(), arr.end());
    int mini = *std::min_element(arr.begin(), arr.end());
    int ans = 0;
    for(int x : arr)
    {
        if(x != maxi && x != mini) ans++;
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
