#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    // Helper function to count subarrays with AT MOST 'k' distinct integers
    int atMostK(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;

        int n = nums.size();
        int l = 0, r = 0, count = 0;
        unordered_map<int, int> mpp; // Frequency map to track distinct elements

        while (r < n)
        {
            mpp[nums[r]]++;

            // If distinct elements exceed k, shrink the window from the left
            while (mpp.size() > k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                {
                    mpp.erase(nums[l]); // Completely remove to keep mpp.size() accurate
                }
                l++;
            }

            // All subarrays ending at 'r' starting from any index between 'l' and 'r' are valid
            count += (r - l + 1);
            r++;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // Exactly(k) = AtMost(k) - AtMost(k - 1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
