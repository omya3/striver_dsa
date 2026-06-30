#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int l = 0, r = 0, maxlen = 0;
        int n = fruits.size();
        unordered_map<int, int> mpp; // Maps fruit type to its frequency in current window

        while (r < n)
        {
            // Add the current fruit to the map
            mpp[fruits[r]]++;

            // If we have more than 2 types of fruits, shift the left pointer once
            if (mpp.size() > 2)
            {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                {
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            // If the window is valid (has <= 2 types), update the max length
            if (mpp.size() <= 2)
            {
                maxlen = max(maxlen, r - l + 1);
            }

            // Move the right pointer forward
            r++;
        }

        return maxlen;
    }
};
