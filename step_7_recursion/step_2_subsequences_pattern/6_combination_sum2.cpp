void find_all_combs(int ind, int n, vector<int> candidates, int target, vector<int> &ds, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(ds);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        if (i > ind && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        ds.push_back(candidates[i]);
        find_all_combs(i + 1, n, candidates, target - candidates[i], ds, result);
        ds.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        find_all_combs(0, candidates.size(), candidates, target, ds, result);
        return result;
    }
};