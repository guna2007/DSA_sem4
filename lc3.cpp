class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int l = 0, ans = 0;
        unordered_set<char> set;

        for (int r = 0; r < n; r++)
        {
            while(set.count(s[r]))
            {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            ans = max(ans, (int)set.size());
        }
        return ans;
    }
};

// optimal soln using map jump directly

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++)
        {
            if (mp.find(s[r]) != mp.end())
            {
                l = max(mp[s[r]] + 1, l);
                // l = mp[s[r]]+1;
            }
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};