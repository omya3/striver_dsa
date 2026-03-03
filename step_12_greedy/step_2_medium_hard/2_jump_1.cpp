#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int max_end = 0;              // furthest index reachable so far

        for (int i = 0; i < n; i++)
        {
            if (i > max_end)          // can't even reach this index
                return false;

            max_end = max(max_end, i + nums[i]);
            if (max_end >= n - 1)     // can reach or pass last index
                return true;
        }
        return true;                  // loop finished without blocking
    }
};
