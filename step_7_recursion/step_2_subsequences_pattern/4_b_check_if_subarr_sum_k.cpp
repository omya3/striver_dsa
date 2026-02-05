bool find_sub_sum(int i, vector<int> arr, int curr_sum, int target, int n)
{   
    if (curr_sum == target)
            return true;
            
    if (i == n)
    {
            return false;
    }

    bool l = find_sub_sum(i + 1, arr, curr_sum + arr[i], target, n);
    if(l) return true;
    bool r = find_sub_sum(i + 1, arr, curr_sum, target, n);
    if(r) return true;
    return false;
}

class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return find_sub_sum(0, arr, 0, k, n);  
        
    }
};