class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            
            if(k>nums.size()) return {};
    
            map<int,int> mp;
    
            for(auto it: nums){
                if(mp.find(it)==mp.end()){
                    mp[it] = 1;
                }
                else{
                    mp[it]+=1;
                }
            }
    
            vector<pair<int, int>> in_count(mp.begin(), mp.end());
    
            auto cmp = [](const pair<int,int> &a, const pair<int, int> &b){
                return a.second<b.second;
            };
    
            priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq;
    
            for(const auto &pairs:in_count){
                cout<<pairs.first<<" "<<pairs.second<<endl;
                pq.push(pairs);
            }
    
            vector<int> output;
            for(int i=0; i<k; i++){
                cout<<pq.top().first<<" ";
                output.push_back(pq.top().first);
                pq.pop();
            }
    
            return output;
        }
    };

// above is my code but we can optimize it as follows
//
// Store everything and extract the best → max heap.
// Maintain only the best k and remove the weakest → min heap.

for (auto& [value, count] : frequency) {
    minHeap.push({count, value});

    if (minHeap.size() > k) {
        minHeap.pop();
    }
}