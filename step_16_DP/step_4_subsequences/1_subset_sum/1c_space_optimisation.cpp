class Solution
{

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<bool> prev(sum + 1, 0);
        vector<bool> curr(sum + 1, 0);

        prev[0]= curr[0] = true;
        prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool not_take = prev[target];
                bool take = false;
                if (target >= arr[ind])
                {
                    take = prev[target - arr[ind]];
                }
                curr[target] = take | not_take;
            }
            prev = curr;
        }
        return prev[sum];
    }
};