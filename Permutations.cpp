#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1;
        return;
    }

    if (n < 4)
    {
        cout << "NO SOLUTION";
        return;
    }
    else if (n == 4)
    {
        cout << "2 4 1 3";
        return;
    }

    vector<int> arr(n);
    int odds = (n + 1) / 2 + 1;
    int eve = 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = eve;
            eve++;
        }
        else
        {
            arr[i] = odds;
            odds++;
        }
    }

    for (int &x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

// void solve() {
//     int n;
//     cin >> n;

//     if (n == 1) {
//         cout << 1;
//         return;
//     }

//     if (n <= 3) {
//         cout << "NO SOLUTION";
//         return;
//     }

//     // print evens first
//     for (int i = 2; i <= n; i += 2)
//         cout << i << " ";

//     // then odds
//     for (int i = 1; i <= n; i += 2)
//         cout << i << " ";
// }

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
