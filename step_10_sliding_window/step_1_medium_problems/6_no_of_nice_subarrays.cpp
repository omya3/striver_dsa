#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to count subarrays containing at most 'goal' odd numbers
    int countSubarraysWithAtMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int l = 0, r = 0, sum = 0;
        int cnt = 0;
        int n = nums.size();
        
        while (r < n) {
            // As shown on the board: sum += (nums[r] % 2)
            sum += (nums[r] % 2);
            
            // Shrink window if the count of odd numbers exceeds our goal
            while (sum > goal) {
                sum -= (nums[l] % 2);
                l++;
            }
            
            // Add the number of valid subarrays ending at index r
            cnt += (r - l + 1);
            r++;
        }
        
        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Total nice subarrays = (At most k odd numbers) - (At most k - 1 odd numbers)
        return countSubarraysWithAtMost(nums, k) - countSubarraysWithAtMost(nums, k - 1);
    }
};
