class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        map<char, int> mp;
        for(auto ch: s){
            mp[ch]+=1;
        }

        for(auto pairs: mp){
            pq.push({pairs.second,pairs.first});
        }

        string new_string;

        // 1. Fix: Change from vector to a single pair
        pair<int, char> previous = {0, '#'}; 

        while(!pq.empty()){
            pair<int, char> ele = pq.top();
            pq.pop();

            new_string += ele.second;
            
            // 2. Fix: Only push the previous element if it still has a valid count
            if (previous.first > 0) {
                pq.push(previous);
            }

            // 3. Fix: Update previous or reset it if the current element is exhausted
            if (ele.first - 1 > 0) {
                previous = {ele.first - 1, ele.second};
            } else {
                previous = {0, '#'}; // Reset so it doesn't get re-pushed
            }
        }

        return new_string.size() == s.size() ? new_string : "";
    }
};
