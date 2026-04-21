class Solution
{

private:
    bool check_sum(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return arr[0] == target;

        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }

        bool not_take = check_sum(arr, ind - 1, target, dp);
        bool take = false;
        if (target >= arr[ind])
        {
            take = check_sum(arr, ind - 1, target - arr[ind], dp);
        }
        return dp[ind][target] = take | not_take;
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return check_sum(arr, arr.size() - 1, sum, dp);
    }
};