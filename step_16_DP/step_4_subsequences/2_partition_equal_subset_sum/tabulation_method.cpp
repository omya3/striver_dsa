class Solution
{
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        if (sum == 0)
            return true;
        if (n == 0)
            return false;

        vector<bool> prev(sum + 1, false);
        vector<bool> curr(sum + 1, false);

        prev[0] = curr[0] = true;

        // Boundary check added here
        if (arr[0] <= sum)
        {
            prev[arr[0]] = true;
        }

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

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        if ((sum % 2) == 0)
        {
            return isSubsetSum(nums, sum / 2);
        }

        return false;
    }
};