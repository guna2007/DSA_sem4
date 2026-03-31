class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        if (n1 == 0)
        {
            if (n2 % 2 != 0)
                return nums2[n2 / 2];
            return (nums2[n2 / 2 - 1] + nums2[n2 / 2]) / 2.0;
        }

        int l = 0, r = n1, h = (n1 + n2 + 1) / 2;

        double ans = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;

            int l1 = (m > 0) ? nums1[m - 1] : INT_MIN;
            int l2 = (h - m > 0) ? nums2[h - m - 1] : INT_MIN;

            int r1 = (m < n1) ? nums1[m] : INT_MAX;
            int r2 = (h - m < n2) ? nums2[h - m] : INT_MAX;

            int maxl = max(l1, l2);
            int minr = min(r1, r2);

            if (maxl <= minr)
            {
                if ((n1 + n2) % 2 != 0)
                {
                    ans = maxl;
                }
                else
                {
                    ans = (maxl + minr) / 2.0;
                }
                r = m - 1;
            }
            else if (l1 > r2)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return ans;
    }
};
