class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int t)
    {
        // find row
        int m = mat.size();
        int n = mat[0].size();

        // bs on rows
        int l = 0, h = m - 1;
        int r = -1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (mat[mid][n - 1] >= t && mat[mid][0] <= t)
            {
                r = mid;
                break;
            }
            if (mat[mid][n - 1] > t)
            {
                h = mid - 1;
            }
            else
                l = mid + 1;
        }

        if (r == -1)
            return false;

        // bs on rth col
        l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (mat[r][mid] == t)
            {
                return true;
            }
            if (mat[r][mid] > t)
            {
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return false;
    }
};

////////////////

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int t)
    {

        int m = mat.size();
        int n = mat[0].size();

        int l = 0, h = m * n - 1;

        while (l <= h)
        {

            int mid = l + (h - l) / 2;

            int val = mat[mid / n][mid % n];

            if (val == t)
                return true;
            else if (val > t)
                h = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};