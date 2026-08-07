class Twitter {
private:
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,vector<pair<int,int>>>tweets;
    int cnt = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({cnt,tweetId});
        cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(const auto it : following[userId]) {
            if(it == userId) continue;
            for(const auto it2 : tweets[it]) {
                pq.push(it2);
            }
        }
        for(const auto it : tweets[userId]) {
            pq.push(it);
        }
        vector<int>ans;
        for(int i=0; i<10; i++) {
            if(pq.empty()) break;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
