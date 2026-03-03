class Solution
{
public:
    int maxf(unordered_map<char, int> &freq)
    {
        int ans = 0;
        for (auto &[c, x] : freq)
        {
            ans = max(ans, x);
        }
        return ans;
    }

    int characterReplacement(string s, int k)
    {
        int n = s.length();

        int l = 0, ans = 0;
        unordered_map<char, int> freq;

        for (int r = 0; r < n; r++)
        {
            freq[s[r]]++;

            int maxi = maxf(freq);
            while (r - l + 1 - maxi > k)
            {
                freq[s[l]]--;
                l++;
                maxi = maxf(freq);
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// optimal soln
class Solution
{
public:
    // optimal without 26.n just n
    int characterReplacement(string s, int k)
    {
        int freq[26] = {0}; // 26 * 4 bytes = 104 bytes

        int l = 0, ans = 0;
        int maxi = 0;

        for (int r = 0; r < s.size(); r++)
        {
            int idx = s[r] - 'A';
            freq[idx]++;
            maxi = max(maxi, freq[idx]);

            while (r - l + 1 - maxi > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};