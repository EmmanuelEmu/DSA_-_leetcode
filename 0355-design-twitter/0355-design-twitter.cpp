class Twitter {
public:
    int time = 0;

    vector<vector<pair<int,int>>> tweets; // user → {time, tweetId}
    vector<unordered_set<int>> followees;

    Twitter() {
        tweets.resize(1001);
        followees.resize(1001);
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        // push own tweets
        for (auto &t : tweets[userId]) pq.push(t);

        // push followee tweets
        for (int f : followees[userId])
            for (auto &t : tweets[f]) pq.push(t);

        vector<int> ans;
        int cnt = 0;

        while (!pq.empty() && cnt < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
