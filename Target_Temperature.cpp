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
    
    int maxi = *max_element(arr.begin(),arr.end());
    
    sort(arr.begin(),arr.end());
    
    for(int i = 1;i < n;i++)
    {
        if(arr[i] == arr[i-1] && arr[i] != maxi)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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
