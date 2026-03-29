class Solution
{
public:
    int scoreDifference(vector<int> &nums)
    {
        int n = nums.size();
        int first = 0, second = 0, isfirst = 1;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] % 2 == 1) ^ ((i + 1) % 6 == 0))
            {
                // swap
                isfirst = isfirst ^ 1;
            }

            if (isfirst)
                first += nums[i];
            else
                second += nums[i];
        }

        return first - second;
    }
};