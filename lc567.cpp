// fixed sliding window
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2)
            return false;
        unordered_map<char, int> freq1;
        for (char &x : s1)
        {
            freq1[x]++;
        }

        int l = 0;
        unordered_map<char, int> freq2;
        for (int i = 0; i < n1; i++)
        {
            freq2[s2[i]]++;
        }

        if (freq1 == freq2)
        {
            return true;
        }

        for (int r = n1; r < n2; r++)
        {
            freq2[s2[l]]--;
            if (freq2[s2[l]] == 0)
                freq2.erase(s2[l]);
            l++;
            freq2[s2[r]]++;
            if (freq1 == freq2)
            {
                return true;
            }
        }
        return false;
    }
};

// optimise using arrays ...

// now using variable window
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2)
            return false;

        int need[26] = {0};
        int window[26] = {0};

        for (char c : s1)
            need[c - 'a']++;

        int l = 0;

        for (int r = 0; r < n2; r++)
        {
            int idx = s2[r] - 'a';
            window[idx]++;

            while (window[idx] > need[idx])
            {
                window[s2[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == n1)
                return true;
        }

        return false;
    }
};