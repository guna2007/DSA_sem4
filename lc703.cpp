class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int rank;
    KthLargest(int k, vector<int> &nums)
    {
        rank = k;

        for (int i = 0; i < nums.size(); i++)
        {
            minheap.push(nums[i]);
            if (minheap.size() > k)
            {
                minheap.pop();
            }
        }
    }

    int add(int val)
    {
        minheap.push(val);
        if (minheap.size() > rank)
        {
            minheap.pop();
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */