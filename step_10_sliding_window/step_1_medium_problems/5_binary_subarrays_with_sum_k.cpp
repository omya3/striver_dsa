#include <vector>

using namespace std;

class Solution
{
private:
    // Helper function to count subarrays where sum <= goal
    int countSubarraysLessThanOrEqualTo(vector<int> &nums, int goal)
    {
        // Base case highlighted in green on the board
        if (goal < 0)
            return 0;

        int l = 0, r = 0, sum = 0;
        int cnt = 0;
        int n = nums.size();

        while (r < n)
        {
            sum += nums[r];

            // Shrink the window from the left if the sum exceeds the goal
            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }

            // Number of valid subarrays ending at index r is (r - l + 1)
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // Implementation of the core equation shown at the top right of the board
        return countSubarraysLessThanOrEqualTo(nums, goal) -
               countSubarraysLessThanOrEqualTo(nums, goal - 1);
    }
};
