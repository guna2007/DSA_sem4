class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        int ans = 0;
        for(int i = 0;i <= 10;i++)
        {
            if(n & (1 << i))
            {
                cnt++;
                if(cnt >= 2)
                {
                    ans++;
                }
            }
            else
                cnt = 0;
        }
        return (ans == 1);
    }
};