class Twitter {
public:

    // userId -> {tweetId, timestamp}
    map<int, vector<pair<int,int>>> mpp1;

    // followerId -> list of followees
    map<int, vector<int>> mpp2;

    int time;

    Twitter() {
        // Global timestamp taaki latest tweet identify kar sake
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        mpp1[userId].push_back({tweetId, time});

        // Agle tweet ke liye timestamp increase
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // Max heap: sabse latest timestamp wala tweet top par rahega
        priority_queue<pair<int,int>> maxHeap;  // {timestamp, tweetId}

        // Pehle user ke khud ke tweets heap me daalo
        for(auto &tweet : mpp1[userId])
        {
            int tid = tweet.first;
            int timestamp = tweet.second;

            maxHeap.push({timestamp, tid});
        }

        // User jin logon ko follow karta hai, unke tweets bhi heap me daalo
        for(int followee : mpp2[userId])
        {
            for(auto &tweet : mpp1[followee])
            {
                maxHeap.push({tweet.second, tweet.first});
            }
        }

        vector<int> res;

        // Heap se latest 10 tweets nikal lo
        while(!maxHeap.empty() && res.size() < 10)
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // Khud ko follow karne ki zarurat nahi
        if(followerId == followeeId) return;

        auto &vec = mpp2[followerId];

        // Agar pehle se follow nahi kar raha, tabhi followee add karo
        if(find(vec.begin(), vec.end(), followeeId) == vec.end())
        {
            vec.push_back(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = mpp2.find(followerId);

        if(it != mpp2.end())
        {
            auto& vec = it->second;

            // Followee ko follow list se remove kar do
            vec.erase(remove(vec.begin(), vec.end(), followeeId), vec.end());
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */