#include <iostream>
using namespace std;
void find_all_combs(int ind, vector<int> candidates, vector<int> &ds, vector<vector<int>> &result)
{
    result.push_back(ds);
    for (int i = ind; i < candidates.size(); i++)
    {
        if (i > ind && candidates[i] == candidates[i - 1])
            continue;

        ds.push_back(candidates[i]);
        find_all_combs(i + 1, candidates, ds, result);
        ds.pop_back();
    }
}

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates)
    {
        vector<int> ds;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        find_all_combs(0, candidates, ds, result);
        return result;
    }
};