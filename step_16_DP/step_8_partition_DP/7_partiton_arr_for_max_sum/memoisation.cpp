class Solution
{

private:
    int partition(int ind, vector<int> &arr, int k, vector<int> &dp)
    {

        int n = arr.size();
        if (ind == n)
            return 0;

        int maxi = INT_MIN;
        int max_ele = INT_MIN;

        if (dp[ind] != -1)
            return dp[ind];

        for (int i = ind; i < min(n, ind + k); i++)
        {

            int len = i - ind + 1;
            max_ele = max(arr[i], max_ele);
            int sum = len * max_ele + partition(i + 1, arr, k, dp);
            maxi = max(maxi, sum);
        }
        return dp[ind] = maxi;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {

        vector<int> dp(arr.size(), -1);
        return partition(0, arr, k, dp);
    }
};