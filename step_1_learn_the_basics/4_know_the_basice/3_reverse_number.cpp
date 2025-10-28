#include <climits> // For INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        int reversed_int = 0;

        while (x != 0) {
            int digit = x % 10;

            // Overflow check for positive numbers
            if (reversed_int > INT_MAX / 10 || (reversed_int == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            // Overflow check for negative numbers
            if (reversed_int < INT_MIN / 10 || (reversed_int == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            reversed_int = reversed_int * 10 + digit;
            x /= 10;
        }

        return reversed_int;
    }
};