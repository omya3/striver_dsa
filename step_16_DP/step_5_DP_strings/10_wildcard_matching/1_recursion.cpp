#include <string>

using namespace std;

class Solution {
private:
    bool domatch(int i, int j, string &s, string &p) {
        // Base Case 1: Both string and pattern are completely exhausted
        if (i < 0 && j < 0) {
            return true;
        }

        // Base Case 2: Pattern is exhausted, but string still has characters left
        if (j < 0 && i >= 0) {
            return false;
        }

        // Base Case 3: String is exhausted, but pattern still has characters left.
        // The remaining pattern prefix (from 0 to j) MUST be entirely '*' to match an empty string.
        if (j >= 0 && i < 0) { // FIXED: Changed => to >=
            for (int l = 0; l <= j; l++) {
                if (p[l] != '*') return false;
            }
            return true;
        }

        // Scenario A: Perfect match or '?' matching any single character
        if (s[i] == p[j] || p[j] == '?') {
            return domatch(i - 1, j - 1, s, p);
        }
        
        // Scenario B: We hit a '*' wildcard character
        else if (p[j] == '*') { // FIXED: Explicitly wrap the wildcard logic here
            // Two choices: 
            // 1. Act as if '*' matches 0 characters: domatch(i, j - 1)
            // 2. Act as if '*' matches current character: domatch(i - 1, j)
            return domatch(i, j - 1, s, p) || domatch(i - 1, j, s, p);
        }
        
        // Scenario C: Strict character mismatch (e.g., 'a' vs 'b')
        return false;
    }

public:
    bool isMatch(string s, string p) {
        // FIXED: Added return keyword
        return domatch(s.size() - 1, p.size() - 1, s, p);
    }
};
