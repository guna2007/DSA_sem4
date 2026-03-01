class Solution
{
public:
    int maxArea(vector<int> &h)
    {
        int ans = 0, n = h.size(), curr = 0, l = 0, r = n - 1;
        while (l < r)
        {
            curr = (r - l) * min(h[l], h[r]);
            ans = max(ans, curr);
            if (h[l] <= h[r])
                l++;
            else
                r--;
        }

        return ans;
    }
};