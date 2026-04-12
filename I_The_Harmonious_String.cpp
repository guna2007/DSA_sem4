#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmpf(const pair<int, int> &x, const pair<int, int> &y)
{
    if (x.first != y.first)
        return x.first > y.first;
    return x.second < y.second;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> fr(26, 0);
    for (char ch : s)
        fr[ch - 'a']++;

    int bkeep = -1;
    int bf = -1;
    vector<int> bp;

    // try m
    for (int m = 1; m <= 26; m++)
    {
        if (n % m)
            continue;

        int f = n / m;
        vector<pair<int, int>> v;

        for (int c = 0; c < 26; c++)
            v.push_back({min(fr[c], f), c});

        sort(v.begin(), v.end(), cmpf);

        int keep = 0;
        vector<int> p;
        for (int i = 0; i < m; i++)
        {
            keep += v[i].first;
            p.push_back(v[i].second);
        }

        if (keep > bkeep)
        {
            bkeep = keep;
            bf = f;
            bp = p;
        }
    }

    vector<int> ins(26, 0);
    for (int c : bp)
        ins[c] = 1;

    vector<int> kn(26, 0), kp(26, 0);
    for (int c : bp)
        kn[c] = min(fr[c], bf);

    string t = s;
    vector<int> cp;

    // keep good
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (ins[c] && kp[c] < kn[c])
        {
            kp[c]++;
        }
        else
        {
            cp.push_back(i);
        }
    }

    vector<char> ad;

    // fill need
    for (int c : bp)
    {
        int need = bf - kp[c];
        while (need--)
            ad.push_back(char('a' + c));
    }

    for (int i = 0; i < (int)cp.size(); i++)
        t[cp[i]] = ad[i];

    cout << (n - bkeep) << "\n";
    cout << t << "\n";
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
