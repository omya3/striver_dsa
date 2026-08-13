#include <string>

using namespace std;

class Solution {
private:
    string helper(string s) {
        int m = s.size();
        // Fix 5: Use string conversion for the character literal
        if (m == 1) {
            return "1" + string(1, s[0]); 
        }

        int curr_cnt = 1;
        char curr_char = s[0];
        string opt_str = ""; // Fix 3: Changed type from char to string

        for (int i = 1; i < m; i++) {
            if (s[i] == s[i - 1]) {
                curr_cnt += 1;
            }
            else {
                // Fix 4: Convert the integer count to a string
                opt_str += to_string(curr_cnt);
                opt_str += curr_char;
                curr_char = s[i];
                curr_cnt = 1; // Fix 1: Fixed the variable name typo
            }
        }
        
        // Fix 2: Append the very last group after the loop finishes
        opt_str += to_string(curr_cnt);
        opt_str += curr_char;

        return opt_str;
    }

public:
    string countAndSay(int n) {
        // Fix 6: Handle the base case directly for n = 1
        if (n == 1) return "1";
        
        string st = "1";
        // Loop runs exactly n - 1 times to generate the nth term
        for (int i = 2; i <= n; i++) {
            st = helper(st);
        }
        return st;
    }
};
