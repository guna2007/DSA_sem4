class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> freq;
        for (int i = 0; i < n; i++)
        {
            vector<int> ap(26);
            for (auto &c : strs[i])
            {
                ap[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++)
            {
                key += string(ap[i], i + 'a');
            }

            freq[key].push_back(strs[i]);
        }

        for (auto &[key, temp] : freq)
        {
            res.push_back(temp);
        }
        return res;
    }
};