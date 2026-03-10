class Solution
{
public:
    using ll = long long;
    ll check(int mid, vector<int> &piles)
    {
        ll h = 0;
        for (int &x : piles)
        {
            h += (1LL * x + mid - 1) / mid;
        }
        return h;
    }

    int minEatingSpeed(vector<int> &piles, int hours)
    {
        int l = 1, h = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (check(mid, piles) <= hours)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};