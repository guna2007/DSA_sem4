class Solution
{
public:
    int trap(vector<int> &h)
    {
        int n = h.size();
        int l = 0, r = n - 1, lmax = h[l], rmax = h[r];

        int ans = 0, curr = 0;

        while (l < r)
        {
            if (lmax < rmax)
            {
                l++;
                curr = lmax - h[l];
                if (curr < 0)
                    curr = 0;
                lmax = max(lmax, h[l]);
                ans += curr;
            }
            else
            {
                r--;
                curr = rmax - h[r];
                if (curr < 0)
                    curr = 0;
                rmax = max(rmax, h[r]);
                ans += curr;
            }
        }

        return ans;
    }
};