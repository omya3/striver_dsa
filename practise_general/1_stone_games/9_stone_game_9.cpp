#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Step 1: Count frequencies of remainders when divided by 3
        int count[3] = {0, 0, 0};
        for (int stone : stones) {
            count[stone % 3]++;
        }

        // Step 2: Case 1 - If count[0] is EVEN
        // The "Skip" buttons cancel each other out. 
        // Alice wins if she can choose a path (1 or 2) that has at least one stone,
        // AND there is a clear winner (neither count is 0).
        if (count[0] % 2 == 0) {
            return (count[1] > 0 && count[2] > 0);
        }

        // Step 3: Case 2 - If count[0] is ODD
        // Bob will use the last "Skip" button to flip the game order.
        // Alice wins only if the difference between type 1 and type 2 stones is strictly greater than 2.
        return (abs(count[1] - count[2]) > 2);
    }
};
