#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0, zeros = 0, maxlen = 0;
        int n = nums.size();

        while (r < n)
        {
            // If current element is 0, increment zero counter
            if (nums[r] == 0)
            {
                zeros++;
            }

            // If zeros exceed k, shift left pointer by 1 step to maintain maximum window size
            if (zeros > k)
            {
                if (nums[l] == 0)
                {
                    zeros--;
                }
                l++;
            }

            // If the window is valid, record the maximum length
            if (zeros <= k)
            {
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }

            // Move right pointer forward
            r++;
        }

        return maxlen;
    }
};
