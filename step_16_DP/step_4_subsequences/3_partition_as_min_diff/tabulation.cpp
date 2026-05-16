class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n2 = nums.size();
        int n = n2 / 2;
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        vector<vector<int>> left(n + 1), right(n + 1);

        for (int i = 0; i < (1 << n); i++) {
            int count = 0, sumL = 0, sumR = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    count++;
                    sumL += nums[j];
                    sumR += nums[j + n];
                }
            }
            left[count].push_back(sumL);
            right[count].push_back(sumR);
        }

        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int minDiff = INT_MAX;

        // Iterate through subset sizes k from the left half
        for (int k = 0; k <= n; k++) {
            int rCount = n - k; // We need n-k elements from the right half
            for (int sumL : left[k]) {
                // Target for right half to reach totalSum/2
                int target = (totalSum / 2) - sumL;
                auto& rSums = right[rCount];
                
                // Binary search for the closest sum in the right half
                auto it = lower_bound(rSums.begin(), rSums.end(), target);
                
                if (it != rSums.end()) {
                    int s1 = sumL + *it;
                    minDiff = min(minDiff, abs(totalSum - 2 * s1));
                }
                if (it != rSums.begin()) {
                    int s1 = sumL + *prev(it);
                    minDiff = min(minDiff, abs(totalSum - 2 * s1));
                }
            }
        }
        return minDiff;
    }
};
