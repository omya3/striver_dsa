#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0, maxSum = 0;

        // Step 1: Calculate the sum of the first k cards from the left
        for (int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];
        }
        maxSum = lsum;

        // Step 2: Shift cards from the left to the right one by one
        int rindex = n - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rindex];
            rindex = rindex - 1;

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};
