
class TimeMap
{
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap()
    {
    }

    void set(string key, string value, int time)
    {
        mp[key].push_back({value, time});
    }

    string get(string key, int time)
    {
        vector<pair<string, int>> &arr = mp[key];
        int n = arr.size();
        int l = 0, r = n - 1;
        string res = "";
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid].second <= time)
            {
                res = arr[mid].first;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return res;
    }
};
