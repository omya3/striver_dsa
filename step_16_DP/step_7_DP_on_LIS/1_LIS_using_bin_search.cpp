class Solution
{
private:
    int lowerBound(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1;
        int res = arr.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0; // Handle empty array edge case

        vector<int> lis;
        lis.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            int idx = lowerBound(lis, nums[i]);

            // If index equals size, nums[i] is larger than all elements in lis
            if (idx == lis.size())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                // Otherwise, replace the element at the found index
                lis[idx] = nums[i];
            }
        }
        // The size of the lis vector is your actual answer
        return lis.size();
    }
};
