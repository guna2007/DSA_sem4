class Solution
{
public:
    vector<int> minDistinctFreqPair(vector<int> &nums)
    {
        int freq[101] = {0};
        for (auto &x : nums)
        {
            freq[x]++;
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (freq[nums[i]] != freq[nums[j]] && nums[i] < nums[j])
                {
                    return {nums[i], nums[j]};
                }
            }
        }

        return {-1, -1};
    }
};