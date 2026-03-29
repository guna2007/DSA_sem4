// optimal
class Solution
{
public:
    int search(vector<int> &nums, int k)
    {
        int n = nums.size();

        int l = 0, r = n - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == k)
                return mid;
            if (nums[l] <= nums[mid])
            {
                if (k >= nums[l] && k <= nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (nums[mid] <= nums[r])
            {
                if (k >= nums[mid] && k <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};

// 2pass

class Solution
{
public:
    int bs(vector<int> &arr, int l, int r, int k)
    {

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == k)
                return mid;
            else if (arr[mid] > k)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int> &arr, int k)
    {
        // find first ele a i <= a[n-1]
        int n = arr.size();
        int l = 0, r = n - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (arr[mid] <= arr[r])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        // now l gives point of deflection
        int lres = bs(arr, 0, l - 1, k);
        int rres = bs(arr, l, n - 1, k);

        if (lres != -1)
            return lres;
        else
            return rres;
    }
};
