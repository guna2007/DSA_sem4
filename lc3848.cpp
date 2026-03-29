class Solution
{
public:
    int fact(int n)
    {
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans *= i;
        }
        return ans;
    }

    bool isDigitorialPermutation(int n)
    {
        // 1.map its digis
        // 2. find fact sum
        // 3.map that sums digis
        // 4.check both matches
        int temp = n;
        unordered_map<int, int> mp;
        while (temp > 0)
        {
            int digi = temp % 10;
            mp[digi]++;
            temp /= 10;
        }

        int sum = 0;
        for (auto &[val, freq] : mp)
        {
            sum += (fact(val) * freq);
        }

        temp = sum;

        while (temp > 0)
        {
            int digi = temp % 10;
            mp[digi]--;
            temp /= 10;
        }

        for (auto &[val, freq] : mp)
        {
            if (freq != 0)
                return false;
        }

        return true;
    }
};