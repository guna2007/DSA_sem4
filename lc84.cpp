class Solution
{
public:
    vector<int> pse(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> nse(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
                res[i] = n;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ps = pse(nums);
        vector<int> ns = nse(nums);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int area = nums[i] * (ns[i] - ps[i] - 1);
            ans = max(ans, area);
        }

        // for(int x : ns)
        // {
        //     cout<<x<<" ";
        // }
        return ans;
    }
};

//////////optimized code : single pass stack solution//////////
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        stack<pair<int, int>> stack; // pair: (index, height)

        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i])
            {
                pair<int, int> top = stack.top();
                int index = top.first;
                int height = top.second;
                maxArea = max(maxArea, height * (i - index));
                start = index;
                stack.pop();
            }
            stack.push({start, heights[i]});
        }

        while (!stack.empty())
        {
            int index = stack.top().first;
            int height = stack.top().second;
            maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));
            stack.pop();
        }
        return maxArea;
    }
};