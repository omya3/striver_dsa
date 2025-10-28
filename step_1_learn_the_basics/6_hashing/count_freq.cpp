class Solution {
    public:
        int maxFrequencyElements(vector<int>& nums) {
            unordered_map <int, int> umap;
    
            for(auto value: nums){
                umap[value]++;
            }
    
            int max = 0;
            for(auto it: umap){
                if(it.second>max){
                    max = it.second;
                }
            }
    
            int sum = 0;
            for(auto it: umap){
                if(it.second == max){
                    sum+=max;
                }
            }
    
            return sum;
        }
    };