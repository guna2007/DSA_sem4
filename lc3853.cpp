class Solution
{
public:
    void shift(string &s, int idx)
    {
        int n = s.length();
        for (int i = idx + 1; i < n; i++)
        {
            s[i - 1] = s[i];
        }
        s.resize(n - 1);
    }

    string mergeCharacters(string s, int k)
    {

        vector<int> freq(26, -1);

        for (int i = 0; i < s.length(); i++)
        {
            if (freq[s[i] - 'a'] == -1)
            {
                freq[s[i] - 'a'] = i;
                continue;
            }
            if (i - freq[s[i] - 'a'] <= k)
            {
                shift(s, i);
                i--;
            }
            else
            {
                freq[s[i] - 'a'] = i;
            }
        }

        return s;
    }
};