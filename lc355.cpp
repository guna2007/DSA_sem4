class Twitter
{
public:
    int time = 0;

    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId)
    {

        vector<pair<int, int>> temp;

        followers[userId].insert(userId);

        for (auto &id : followers[userId])
        {
            for (auto &tweet : tweets[id])
            {
                temp.push_back(tweet);
            }
        }

        sort(temp.rbegin(), temp.rend());

        vector<int> ans;

        for (int i = 0; i < min(10, (int)temp.size()); i++)
        {
            ans.push_back(temp[i].second);
        }

        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followers[followerId].erase(followeeId);
    }
};

// optimal pq

class Twitter
{
public:
    int time = 0;

    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId)
    {
        followers[userId].insert(userId);

        // {time, tweetId, userId, nextIndex}
        priority_queue<vector<int>> pq;

        // push latest tweet of every followed user
        for (auto user : followers[userId])
        {
            int n = tweets[user].size();

            if (n > 0)
            {
                auto &[t, tid] = tweets[user][n - 1];

                pq.push({t, tid, user, n - 2});
            }
        }

        vector<int> res;

        while (!pq.empty() && res.size() < 10)
        {
            auto curr = pq.top();
            pq.pop();

            int currTime = curr[0];
            int tweetId = curr[1];
            int user = curr[2];
            int nextIdx = curr[3];

            res.push_back(tweetId);

            // push next older tweet of same user
            if (nextIdx >= 0)
            {
                auto &[t, tid] = tweets[user][nextIdx];

                pq.push({t, tid, user, nextIdx - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) { followers[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) { followers[followerId].erase(followeeId); }
};