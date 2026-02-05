void fin_all_combs(int i, int n, vector<int> arr, int target, vector<int> ds, vector<vector<int>> &result)
{
    if (i == n)
    {
        if (target == 0)
        {
            result.push_back(ds);
        }
        return;
    }

    if (arr[i] <= target)
    {
        ds.push_back(arr[i]);
        fin_all_combs(i, n, arr, target - arr[i], ds, result);
        ds.pop_back();
    }
    
    fin_all_combs(i + 1, n, arr, target, ds, result);
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> result;
        fin_all_combs(0, candidates.size(), candidates, target, ds, result);
        return result;
    }
};