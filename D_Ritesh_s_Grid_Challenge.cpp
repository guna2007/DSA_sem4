#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    // no 1 2 4
    if (n == 1 || n == 2 || n == 4)
    {
        cout << 0 << "\n";
        return;
    }

    // fix n 3
    if (n == 3)
    {
        cout << 1 << "\n";
        cout << "-1 1 1\n";
        cout << "1 -1 1\n";
        cout << "-1 1 1\n";
        return;
    }

    // all 1
    vector<vector<int>> a(n, vector<int>(n, 1));

    // daig -1
    for (int i = 0; i < n; i++)
    {
        a[i][i] = -1;
        a[i][n - 1 - i] = -1;
    }

    cout << 1 << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j)
                cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
