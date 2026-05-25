class Solution
{

private:
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = 1e9;

        for (int k = i; k < j; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
            if (steps < mini)
                mini = steps;
        }
        return dp[i][j] = mini;
    }

public:
    int matrixMultiplication(vector<int> &arr)
    {
        // code here
        int N = arr.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(1, arr.size() - 1, arr, dp);
    }
};