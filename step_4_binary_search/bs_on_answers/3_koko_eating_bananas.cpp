class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Fixed find_hours inline
            long long total_hours = 0;
            for (int pile : arr) {
                total_hours += (pile + mid - 1LL) / mid;
                if (total_hours > h) break;  // Early exit optimization
            }
            
            if (total_hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
