class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 1;
        int curr = 1;
        for (int num : set)
        {
            if (!set.count(num - 1))
            {
                int check = num + 1;
                while (set.count(check))
                {
                    curr++;
                    check++;
                }
                ans = max(ans, curr);
                curr = 1;
            }
        }
        return ans;
    }
};