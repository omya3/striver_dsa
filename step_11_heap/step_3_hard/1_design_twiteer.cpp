#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>
#include <algorithm>

using HeapTuple = std::tuple<int, int, int, int>; // {count, tweetId, followeeId, index}

class Twitter {
private:
    int count;
    // Map a user to the set of users they are following
    std::unordered_map<int, std::unordered_set<int>> followMap;
    // Map a user to a list of their tweets as pairs: {timestamp_count, tweetId}
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweetMap;

public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // C++ vectors use push_back
        tweetMap[userId].push_back({count, tweetId});
        count -= 1; // Decrementing makes newer tweets have smaller numbers (perfect for Min-Heap)
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> res;
        std::priority_queue<HeapTuple, std::vector<HeapTuple>, std::greater<HeapTuple>> pq;

        // A user always follows themselves implicitly to see their own tweets
        followMap[userId].insert(userId);

        // Iterate through all people this user follows
        for (auto followeeId : followMap[userId]) {
            if (tweetMap.find(followeeId) != tweetMap.end() && !tweetMap[followeeId].empty()) {
                int index = tweetMap[followeeId].size() - 1;
                // Correct C++ Structured Binding syntax
                auto [tweetCount, tweetId] = tweetMap[followeeId][index];
                pq.push({tweetCount, tweetId, followeeId, index - 1});
            }
        }

        // Merge up to 10 most recent tweets
        while (!pq.empty() && res.size() < 10) {
            auto [tweetCount, tweetId, followeeId, index] = pq.top();
            pq.pop();

            res.push_back(tweetId);
            
            // If this followee has more tweets, push the next most recent one into the heap
            if (index >= 0) {
                auto [nextCount, nextTweetId] = tweetMap[followeeId][index];
                pq.push({nextCount, nextTweetId, followeeId, index - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // FollowerId adds followeeId to their list
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // A user cannot unfollow themselves according to LeetCode constraints
        if (followerId == followeeId) return; 
        
        // C++ sets use .erase() to remove elements
        if (followMap[followerId].find(followeeId) != followMap[followerId].end()) {
            followMap[followerId].erase(followeeId);
        }
    }
};
