class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, ans = 0;

        for (int r = l; r < n; r++)
        {
            if (nums[r] - nums[l] < 0)
            {
                l = r;
                continue;
            }
            ans = max(ans, nums[r] - nums[l]);
        }

        return ans;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& nums) {
//         int n = nums.size();
//         int mini = nums[0],ans = 0;

//         for(auto x : nums)
//         {
//             ans = max(ans,x - mini);
//             mini = min(mini,x);
//         }

//         return ans;

//     }
// };
