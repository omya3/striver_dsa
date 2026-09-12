#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
    /*
     * Recursive helper to compute the minimum edit distance.
     * 'i' tracks the current character pointer in word1.
     * 'j' tracks the current character pointer in word2.
     * Pass 'word1' and 'word2' by reference (&) to avoid duplicating strings in memory.
     */
    int editor(int i, int j, const string &word1, const string &word2, vector<vector<int>> &dp)
    {

        // --- BASE CASES ---

        // Case A: Both words are exhausted at the same time. No steps needed.
        if (i < 0 && j < 0)
            return 0;

        // Case B: word2 is empty, but word1 still has characters.
        // We must DELETE all remaining (i + 1) characters from word1 to match word2.
        if (j < 0 && i >= 0)
            return i + 1;

        // Case C: word1 is empty, but word2 still has characters.
        // We must INSERT all remaining (j + 1) characters into word1 to match word2.
        if (i < 0 && j >= 0)
            return j + 1;

        if (dp[i][j] != -1)
            return dp[i][j];
        // --- RECURSIVE TRANSITIONS ---

        // Match Scenario: Characters are identical.
        // Cost is 0. Move both pointers backward to evaluate the remaining prefixes.
        if (word1[i] == word2[j])
        {
            return dp[i][j] = 0 + editor(i - 1, j - 1, word1, word2, dp);
        }

        // Mismatch Scenario: We must choose the path that yields the absolute minimum cost.
        else
        {
            return dp[i][j] = min({// 1. INSERTION OPERATION:
                                   // Act as if we inserted word2[j] at the end of word1.
                                   // This satisfies word2[j], so 'j' moves backward, but 'i' stays in place.
                                   1 + editor(i, j - 1, word1, word2, dp),

                                   // 2. DELETION OPERATION:
                                   // Remove word1[i] completely.
                                   // This consumes word1[i], so 'i' moves backward, but 'j' stays in place.
                                   1 + editor(i - 1, j, word1, word2, dp),

                                   // 3. REPLACEMENT OPERATION:
                                   // Force word1[i] to change into word2[j].
                                   // This satisfies both positions, so both 'i' and 'j' move backward.
                                   1 + editor(i - 1, j - 1, word1, word2, dp)});
        }
    }

public:
    int minDistance(string word1, string word2)
    {
        // FIXED: Shifted starting parameters to (size - 1) to respect 0-based string index rules.
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return editor(word1.size() - 1, word2.size() - 1, word1, word2, dp);
    }
};
