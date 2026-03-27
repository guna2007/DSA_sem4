#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n,k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    
    int ans = 0;
    
    for(int i = 0;i < n;i++)
    {
        for(int j = i+1;j < n;j++)
        {
            
            int cost = max(A[i],A[j]) - min(max(A[i],A[j])/2 , 100) + min(A[i],A[j]);
            if(cost <= k)
            {
                ans = max(ans, B[i] + B[j]);
            }
        }
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
