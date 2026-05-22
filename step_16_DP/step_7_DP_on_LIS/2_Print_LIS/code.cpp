class Solution
{
public:
    vector<int> getLIS(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};

        // dp[i] stores the length of LIS ending at index i
        vector<int> dp(n, 1);
        // hash[i] stores the previous element's index in the LIS
        vector<int> hash(n);

        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++)
        {
            hash[i] = i; // Initialize parent pointer to itself
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; // Track the backtracking path
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the subsequence
        vector<int> temp;
        temp.push_back(arr[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};
