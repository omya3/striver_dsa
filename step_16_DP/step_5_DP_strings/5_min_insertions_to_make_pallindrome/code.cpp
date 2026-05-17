class Solution {

public:
    int lcs(string &s1, string &s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();

        // Create DP table initialized to 0
        // Size is (l1 + 1) x (l2 + 1) to handle the base case of empty strings
        vector<int> prev(l2 + 1, 0);

        // Fill the DP table
        for (int i = 1; i <= l1; i++)
        {
            vector<int> curr(l2 + 1, 0);
            for (int j = 1; j <= l2; j++)
            {
                // If characters match, add 1 to the previous diagonal state
                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                // If they don't match, take the maximum of skipping a character from s1 or s2
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        // The bottom-right cell contains the length of the LCS
        return prev[l2];
    }

public:
    int longestPalindromeSubseq(string s) {
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        return lcs(s, s_rev);
    }

public:
    int minInsertions(string s) {
        int n = s.length();
        int p = longestPalindromeSubseq(s);
        return n-p;
    }
};