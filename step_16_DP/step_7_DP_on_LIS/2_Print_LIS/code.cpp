class Solution
{
public:
    vector<int> getLIS(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++)
        {
            hash[i] = 1;
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(), temp.end());

        for (auto it : temp)
            cout << it << " ";
            
        cout << endl;
        return maxi;
    }
};