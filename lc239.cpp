class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});

            while (!pq.empty() && pq.top().second <= i - k)
            {
                pq.pop();
            }

            if (i >= k - 1)
            {
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};

/// usng deque tc n

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {

            // remove indices outside window
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // maintain decreasing order
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            // window ready
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};