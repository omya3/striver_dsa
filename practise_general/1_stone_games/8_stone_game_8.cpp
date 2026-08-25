// Recursive solution

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SolutionBruteForce {
public:
    vector<int> pref;
    int n;

    // solve(i) means: "What is the max score difference the current player 
    // can get if the previous player stopped at index i?"
    int solve(int i) {
        // BASE CASE: If we are at the last element, no more moves can be made.
        if (i == n - 1) {
            return 0; 
        }

        int max_diff = INT_MIN;

        // EXPANSION: Try every possible next split point 'j' from i+1 to the end.
        // solve(i) = max( pref[i+1]-solve(i+1), pref[i+2]-solve(i+2), ... )
        for (int j = i + 1; j < n; ++j) {
            // Current player gets pref[j] points. 
            // Opponent gets solve(j) points from that point forward.
            int current_move_diff = pref[j] - solve(j);
            
            // Track the maximum difference possible
            max_diff = max(max_diff, current_move_diff);
        }

        return max_diff;
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        pref.resize(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        // Alice starts first. She must choose an initial index j >= 1.
        // This is equivalent to pretending a "fake" previous move happened at index 0.
        return solve(0);
    }
};


// using dp to avoid redundant solving of problems

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SolutionMemoized {
public:
    vector<int> pref;
    vector<int> dp; // Array to store and reuse our calculations
    int n;

    int solve(int i) {
        // BASE CASE
        if (i == n - 1) {
            return 0; 
        }

        // REUSE: If solve(i) was already calculated, return it instantly!
        if (dp[i] != INT_MIN) {
            return dp[i];
        }

        int max_diff = INT_MIN;

        // Still looping through every option, but children states are now cached
        for (int j = i + 1; j < n; ++j) {
            int current_move_diff = pref[j] - solve(j); // Reuses values here
            max_diff = max(max_diff, current_move_diff);
        }

        // STORE: Save the result in the dp array before returning
        return dp[i] = max_diff;
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        pref.resize(n);
        
        // Initialize dp cache with INT_MIN (meaning "not calculated yet")
        dp.assign(n, INT_MIN); 
        
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        return solve(0);
    }
};

// O(n) solution obtained by observing the expansion of equations

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SolutionOptimizedRecursion {
public:
    vector<int> pref;
    vector<int> dp;
    int n;

    int solve(int i) {
        // MATHEMATICAL BREAKTHROUGH:
        // We expanded the loop and noticed:
        // solve(i)   = max( pref[i+1]-solve(i+1), pref[i+2]-solve(i+2), ... )
        // solve(i+1) = max(                       pref[i+2]-solve(i+2), ... )
        //
        // Substituting solve(i+1) into solve(i) yields:
        // solve(i)   = max( pref[i+1] - solve(i+1), solve(i+1) )

        // BASE CASE: At the second-to-last index, the only choice left is taking everything.
        if (i == n - 2) {
            return pref[n - 1];
        }

        if (dp[i] != INT_MIN) {
            return dp[i];
        }

        // Option A: Stop at the very next index (i + 1)
        int take_next = pref[i + 1] - solve(i + 1);

        // Option B: Skip the next index and pass the decision down
        int skip_next = solve(i + 1);

        // Store and return the max of both options
        return dp[i] = max(take_next, skip_next);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        pref.resize(n);
        dp.assign(n, INT_MIN);
        
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        return solve(0);
    }
};



// Since solve(i) only depends on solve(i+1),
//  we don't need recursion or a dp array. 
//  We can calculate it working backwards using a single integer variable.

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> pref;
    vector<int> dp;
    int n;

    int solve(int i) {
        /*
        ===========================================================================
        THE INNER LOOP ELIMINATION BREAKTHROUGH:
        
        Let's write out the max_diff calculations explicitly:
        solve(i) = max {
            pref[i+1] - solve(i+1)
            pref[i+2] - solve(i+2)
            ...
            pref[n-1] - solve(n-1)
        }

        Now look at the calculation for the very next state, solve(i + 1):
        solve(i+1) = max {
            pref[i+2] - solve(i+2)
            ...
            pref[n-1] - solve(n-1)
        }

        Notice that lines 2 through the end of solve(i) match solve(i+1) perfectly!
        Since solve(i+1) already finds the maximum of those exact rows, we can 
        substitute it directly back into solve(i):
        
        solve(i) = max( pref[i+1] - solve(i+1), solve(i+1) )
        ===========================================================================
        */

        // BASE CASE: At the second-to-last index, the only choice left is taking everything.
        if (i == n - 2) {
            return pref[n - 1];
        }

        // Return cached result if already calculated
        if (dp[i] != INT_MIN) {
            return dp[i];
        }

        // Option A: Stop at the very next index (i + 1)
        int take_next = pref[i + 1] - solve(i + 1);

        // Option B: Skip the next index and pass the decision down
        int skip_next = solve(i + 1);

        // Store and return the max of both options without using a loop
        return dp[i] = max(take_next, skip_next);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        pref.resize(n);
        dp.assign(n, INT_MIN);
        
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        // Alice starts by picking an index >= 1. 
        // solve(0) ensures the first real option evaluated inside solve() is index 1.
        return solve(0);
    }
};
