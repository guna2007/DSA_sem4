#include <bits/stdc++.h>
using namespace std;

// Type Aliases for speed and clarity
using ll = long long;
using lli = long long int;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

// Common Macros
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define el '\n'
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second

// Constants
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7; // Standard modulo value for CodeChef tasks

// Logic for a single test case
void solve()
{
    // 1. Read Inputs
    int n;
    cin >> n;
    string s;
    cin >> s;
    int as = 0, bs= 0;
    for(auto x : s)
    {
        if(x == 'a') as++;
        else bs++;
    }
    cout<<as<<" "<<bs<<el;
}

int main()
{
    // Optimize standard I/O operations for performance
    fast_io;

    // Handle multiple test cases (standard for CodeChef)
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
