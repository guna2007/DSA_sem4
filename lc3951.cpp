class Solution
{
public:
    long long minEnergy(int n, int brightness, vector<vector<int>> &intervals)
    {
        int m = intervals.size();
        sort(intervals.begin(), intervals.end());
        int len = 0;

        // find len of all intervals, check for overlapping using while loop
        // len += r-l+1 but if overlapping, then len += max(r, prev_r) - l + 1

        int i = 0;
        while (i < m)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];
            while (i + 1 < m && intervals[i + 1][0] <= r)
            {
                r = max(r, intervals[i + 1][1]);
                i++;
            }
            len += r - l + 1;
            i++;
        }

        int bulbs = (brightness + 2) / 3;
        return 1LL * bulbs * len;
    }
};