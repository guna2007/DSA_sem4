class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        for(int i = 0;i < n;i++)
        {

            //for all jumps check with adj one for dups
            if(i > 0 && nums[i-1] == nums[i]) continue;

            //2 sum logic
            int j = i+1,k = n-1;
            int target = -1 * nums[i];
            while(j < k)
            {
                int sum = nums[j] + nums[k];
                if(sum == target) 
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && k+1 < n && nums[k] == nums[k-1] ) k--;
                    while(j < k  && j-1 >= 0 && nums[j] == nums[j+1] ) j++;
                    k--;
                    j++;

                }
                else if(sum > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }

        }
        return res;
    }
};