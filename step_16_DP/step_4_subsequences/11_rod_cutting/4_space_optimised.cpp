class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        // dp[i] stores the max profit obtainable for a rod of length i
        vector<int> dp(n + 1, 0);

        // Compute max profit for every rod length from 1 to n
        for (int i = 1; i <= n; i++) {
            int max_val = INT_MIN;
            for (int j = 0; j < i; j++) {
                max_val = max(max_val, price[j] + dp[i - (j + 1)]);
            }
            dp[i] = max_val;
        }

        return dp[n];
    }
};
