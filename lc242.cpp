class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (n != m)
            return false;
        vector<int> freq(27, 0);

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 27; i++)
        {
            if (freq[i] != 0)
                return false;
        }
        return true;
    }
};
