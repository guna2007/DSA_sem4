class LRUCache
{
public:
    vector<pair<int, int>> cache;
    int c;
    LRUCache(int cap)
    {
        c = cap;
    }

    int get(int key)
    {
        for (int i = 0; i < cache.size(); i++)
        {
            if (key == cache[i].first)
            {
                int ans = cache[i].second;
                cache.erase(cache.begin() + i);
                cache.push_back({key, ans});
                return ans;
            }
        }
        return -1;
    }

    void put(int key, int value)
    {
        // first already present
        for (int i = 0; i < cache.size(); i++)
        {
            if (key == cache[i].first)
            {
                cache.erase(cache.begin() + i);
                break;
            }
        }

        if (cache.size() == c)
        {
            cache.erase(cache.begin());
        }

        cache.push_back({key, value});
    }
};

// optimised in o(1)
