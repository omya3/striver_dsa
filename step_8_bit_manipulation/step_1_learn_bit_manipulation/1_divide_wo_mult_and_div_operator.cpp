class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow: INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        bool positive = !((dividend < 0) ^ (divisor < 0)); // same sign -> positive

        // Convert to positive magnitudes in long long (avoid abs(int))
        long long n = dividend;
        long long d = divisor;
        if (n < 0) n = -n;   // negation in long long
        if (d < 0) d = -d;   // negation in long long

        int ans = 0;

        while (n >= d) {
            long long temp = d;
            int multiple = 1;

            // Double temp and multiple while we can
            while ((temp << 1) <= n) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            ans += multiple;
        }

        return positive ? ans : -ans;
    }
};
