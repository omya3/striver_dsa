class Solution {
    public:
      int mostFreqEle(vector<int>& nums) {
          // code here
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
      
              int max_element = INT_MIN;
              for(auto it: umap){
                  if(it.second == max && max_element < it.first){
                      max_element = it.first;
                  }
              }
      
              return max_element;
          }
      
  };