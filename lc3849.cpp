class Solution
{
public:
    string maximumXor(string s, string t)
    {
        vector<int> freq(2, 0);
        for (char c : t)
        {
            freq[c - '0']++;
        }

        string res = "";
        for (char c : s)
        {
            if (c == '1')
            {
                if (freq[0] != 0)
                {
                    res += '1';
                    freq[0]--;
                }
                else
                {
                    res += '0';
                    freq[1]--;
                }
            }
            else
            {
                if (freq[1] != 0)
                {
                    res += '1';
                    freq[1]--;
                }
                else
                {
                    res += '0';
                    freq[0]--;
                }
            }
        }

        return res;
    }
};