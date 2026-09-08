# Dynamic Programming Template Book

## How to use this book

For every DP problem, identify these five things before coding:

1. **State:** what does `dp[...]` mean?
2. **Transition:** what choices are available?
3. **Base case:** what is the smallest valid state?
4. **Order:** recursion direction or tabulation loop direction.
5. **Answer:** which final state is returned?

First form the recursive state and transition. Then write memoization, tabulation, and space optimization only after the dependencies are clear.

## How to derive a DP solution

Do not begin with "Which template is this?" Begin with: **if I make one decision now, what smaller version of the same problem remains?**

### The five questions

| Question | How to find it |
| --- | --- |
| State | Pause halfway through. What minimum information is needed to make every future decision correctly? |
| Transition | List every legal immediate choice, then write the smaller state after that choice. |
| Base case | Shrink the state until no decision remains; answer that smallest case directly. |
| Order | Fill a table only after the states it reads: smaller indices first, or shorter intervals first. |
| Answer | Return the state that represents the untouched original problem. |

Useful state clues:

- Array decision: current index, `ind`.
- Subset/knapsack: current index and remaining target, `ind, target`.
- Grid: `row, col`.
- Strings: prefix lengths, `i, j`.
- Stocks: `ind, buy, cap`.
- Interval split: `i, j`.

For every new problem, begin with:

~~~cpp
// State:
// Choices:
// Base case:
// Tabulation order:
// Answer state:
~~~
## 1. One-dimensional DP

### Recognition clue

At index `i`, the decision depends only on a few earlier indices: climb, jump, rob, or take/skip.

### Take / not-take invariant

**Problem model:** At every index, take the current value or skip it. Taking it rules out the adjacent value.

**Derivation:** State `dp[ind]` is the best answer for `0..ind`. Choices are skip (`dp[ind - 1]`) or take (`arr[ind] + dp[ind - 2]`). The base is one element or no elements. Because dependencies are leftward, loop left to right. The answer is `dp[n - 1]`.

`dp[i]` is the best answer using elements from `0` through `i`.

~~~cpp
long long solve(int ind, vector<int>& arr, vector<long long>& dp) {
    if (ind == 0) return arr[0];
    if (ind < 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    long long notTake = solve(ind - 1, arr, dp);
    long long take = arr[ind] + solve(ind - 2, arr, dp);

    return dp[ind] = max(take, notTake);
}
~~~

### Space-optimized skeleton

~~~cpp
long long maximumNonAdjacentSum(vector<int>& arr) {
    long long prev2 = 0;
    long long prev = arr[0];

    for (int ind = 1; ind < (int)arr.size(); ind++) {
        long long take = arr[ind] + prev2;
        long long notTake = prev;
        long long curr = max(take, notTake);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}
~~~

### Variants

- **Climbing Stairs:** `dp[i] = dp[i - 1] + dp[i - 2]`.
- **Frog Jump:** minimize cost from `i - 1` or `i - 2`.
- **Frog Jump K:** loop over all reachable previous jumps.
- **House Robber II:** solve `[0, n - 2]` and `[1, n - 1]`, then take the maximum.

### Common bugs

- Forgetting the `ind < 0` base case.
- Using `arr[0]` for an empty input.
- For circular arrays, allowing both first and last elements.

### Representative problems

Frog Jump, Maximum Sum of Non-adjacent Elements, House Robber.

---

## 2. Grid DP

### Recognition clue

The state is a grid cell, or a small set of cells. Movement is restricted to stated directions.

### Count paths / minimum paths

**Problem model:** With right/down moves, the final move into a cell came from above or from the left.

**Derivation:** State `dp[row][col]` is the number of ways, or minimum cost, to reach this cell. Combine the two incoming choices. The start cell is the base. Fill top-left to bottom-right because top and left are needed first. The answer is `dp[n - 1][m - 1]`.

`dp[row][col]` means the answer on reaching cell `(row, col)`.

~~~cpp
const int INF = 1000000000;

for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
        if (row == 0 && col == 0) {
            dp[row][col] = grid[row][col];
            continue;
        }

        int up = row > 0 ? dp[row - 1][col] : INF;
        int left = col > 0 ? dp[row][col - 1] : INF;
        dp[row][col] = grid[row][col] + min(up, left);
    }
}
~~~

For **counting paths**, use `0` outside the grid instead of `INF`, and add transitions. For **obstacles**, set a blocked cell to `0` before using transitions.

### Triangle DP

Build from the bottom because every cell depends on the two cells below it.

~~~cpp
vector<int> front = triangle[n - 1];

for (int row = n - 2; row >= 0; row--) {
    vector<int> curr(row + 1);

    for (int col = 0; col <= row; col++) {
        curr[col] = triangle[row][col] + min(front[col], front[col + 1]);
    }
    front = curr;
}

return front[0];
~~~

### Two-agent grid DP

**Problem model:** Two agents move down together. Both columns affect the future, so the state needs both positions.

**Derivation:** State `dp[row][col1][col2]` is the best collection from this row. Try all nine pairs of next moves. The last row is the base, collecting a shared cell once. Current row reads next row, so recurse forward or tabulate bottom-up. The answer is `dp[0][0][m - 1]`.

Use this for **Ninja and his Friends**.

State: `dp[row][col1][col2]` is the maximum chocolates from this row onward when the agents are at `col1` and `col2`.

~~~cpp
int solve(int row, int col1, int col2, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
    int n = grid.size();
    int m = grid[0].size();

    if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return -1000000000;

    if (row == n - 1) {
        return col1 == col2 ? grid[row][col1]
                            : grid[row][col1] + grid[row][col2];
    }

    if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

    int best = -1000000000;
    for (int move1 = -1; move1 <= 1; move1++) {
        for (int move2 = -1; move2 <= 1; move2++) {
            int gain = col1 == col2 ? grid[row][col1]
                                    : grid[row][col1] + grid[row][col2];
            best = max(best, gain + solve(row + 1, col1 + move1, col2 + move2,
                                          grid, dp));
        }
    }
    return dp[row][col1][col2] = best;
}
~~~

### Common bugs

- Using `0` for invalid moves in a maximization problem that may contain negative values.
- Counting a cell twice when both agents stand on it.
- Mixing whether the current cell is counted before or after recursion.

### Representative problems

Unique Paths, Unique Paths II, Minimum Falling Path Sum, Triangle, Ninja and his Friends.

---

## 3. Subsequences: 0/1 Knapsack Family

### Recognition clue

Choose or skip every array element once. A target or capacity is constrained.

### Boolean subset sum

**Problem model:** Each number can be selected once or skipped, and selecting it reduces the target.

**Derivation:** State `dp[ind][target]` asks whether values `0..ind` make target. Skip the current value or take it and solve `target - arr[ind]`. Target `0` is always possible. Each item uses a previous-item row; in one array, loop target backward to prevent reuse. The answer is `dp[n - 1][target]`.

State: `dp[ind][target]` = can elements `0..ind` make `target`?

~~~cpp
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<bool> prev(sum + 1, false), curr(sum + 1, false);

    prev[0] = true;
    if (arr[0] <= sum) prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        curr[0] = true;

        for (int target = 1; target <= sum; target++) {
            bool notTake = prev[target];
            bool take = target >= arr[ind] && prev[target - arr[ind]];
            curr[target] = take || notTake;
        }
        prev = curr;
    }
    return prev[sum];
}
~~~

### One-array 0/1 optimization

Iterate target **backward**. That prevents one item being reused.

~~~cpp
vector<bool> dp(target + 1, false);
dp[0] = true;

for (int value : arr) {
    for (int sum = target; sum >= value; sum--) {
        dp[sum] = dp[sum] || dp[sum - value];
    }
}
~~~

### Counting subsets

`dp[ind][target]` counts ways to make `target`. Use `long long` and a modulus when required.

~~~cpp
const int MOD = 1000000007;
vector<long long> dp(target + 1, 0);
dp[0] = 1;

for (int value : arr) {
    for (int sum = target; sum >= value; sum--) {
        dp[sum] = (dp[sum] + dp[sum - value]) % MOD;
    }
}
~~~

For the zero-valued-element version, remember that `arr[0] == 0` gives two ways to form target `0`: take or skip it.

### Difference transformation

For desired difference `d`:

~~~text
target = (totalSum - d) / 2
~~~

It is impossible when `totalSum - d < 0` or it is odd. Count subsets with sum `target`.

### Representative problems

Subset Sum Equal to Target, Partition Equal Subset Sum, Minimum Subset Sum Difference, Count Subsets with Sum K, Target Sum.

---

## 4. Unbounded Knapsack Family

### Recognition clue

An item may be reused any number of times: coins, cuts, and unlimited choices.

### Key difference

**Problem model:** Unlike 0/1 knapsack, selecting an item does not remove it from future choices. A rod may reuse a cut length.

**Derivation:** State `dp[capacity]` is the best value for this capacity. Taking a length leaves `capacity - length` and the same length remains usable. Capacity `0` is the base. Loop capacity forward to allow reuse. Return the entry for the original capacity.

In a one-dimensional loop, iterate capacity **forward**. Forward iteration permits using the current item again.

~~~cpp
int unboundedKnapsack(vector<int>& value, vector<int>& weight, int capacity) {
    vector<int> dp(capacity + 1, 0);

    for (int ind = 0; ind < (int)value.size(); ind++) {
        for (int cap = weight[ind]; cap <= capacity; cap++) {
            dp[cap] = max(dp[cap], value[ind] + dp[cap - weight[ind]]);
        }
    }
    return dp[capacity];
}
~~~

### Rod Cutting

Rod Cutting is unbounded knapsack:

- item length = `len`;
- item value = `price[len - 1]`;
- capacity = rod length `n`.

~~~cpp
int cutRod(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);

    for (int len = 1; len <= n; len++) {
        for (int rod = len; rod <= n; rod++) {
            dp[rod] = max(dp[rod], price[len - 1] + dp[rod - len]);
        }
    }
    return dp[n];
}
~~~

### Common bugs

- Iterating backward and accidentally turning it into 0/1 knapsack.
- Not allowing the `take` transition to remain on the same item.

### Representative problems

Minimum Coins, Coin Change II, Unbounded Knapsack, Rod Cutting.

---

## 5. DP on Strings

### Recognition clue

The state is determined by prefixes of one or two strings.

### Longest Common Subsequence

**Problem model:** Compare final characters of two prefixes. A match can join the subsequence; on a mismatch, one final character must be discarded.

**Derivation:** State `dp[i][j]` is LCS length for the first `i` and `j` characters. Match uses diagonal plus one; mismatch tries discarding either final character. Empty prefix gives `0`. Fill increasing prefix lengths. The full-string answer is `dp[n][m]`.

State: `dp[i][j]` = LCS length of the first `i` characters of `s` and the first `j` characters of `t`.

~~~cpp
int longestCommonSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
~~~

### LCS derivatives

- Print LCS: backtrack from `dp[n][m]`.
- Longest common substring: mismatch becomes `0`; track a global maximum.
- Longest palindromic subsequence: `LCS(s, reverse(s))`.
- Minimum insertions for palindrome: `n - LPS`.
- Minimum insertions/deletions from `s` to `t`: `n + m - 2 * LCS`.
- Shortest common supersequence: backtrack through the LCS table and append leftovers.

### Distinct Subsequences

**Problem model:** Count how many ways deleting characters from the source leaves exactly the target.

**Derivation:** State `dp[i][j]` is ways for first `i` source characters to form first `j` target characters. You may always skip the source character; matching characters may also be used. Empty target has one way. In one-row form, loop `j` backward to use each source character once. Return ways for the full target.

State: ways for the first `i` characters of `s` to form the first `j` characters of `t`.

~~~cpp
long long numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<long long> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp[m];
}
~~~

The `j` loop is backward, so `s[i - 1]` is used at most once in a row.

### Edit Distance

**Problem model:** When final characters differ, the final operation is insert, delete, or replace.

**Derivation:** State `dp[i][j]` is minimum operations from the first `i` source characters to first `j` target characters. Equal characters use diagonal; otherwise try all three edits. Empty source needs inserts and empty target needs deletes. Fill top-left to bottom-right. The answer is `dp[n][m]`.

State: minimum operations to convert `s[0..i)` into `t[0..j)`.

~~~cpp
for (int i = 0; i <= n; i++) dp[i][0] = i;
for (int j = 0; j <= m; j++) dp[0][j] = j;

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (s[i - 1] == t[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
        } else {
            int insertChar = dp[i][j - 1];
            int deleteChar = dp[i - 1][j];
            int replaceChar = dp[i - 1][j - 1];
            dp[i][j] = 1 + min({insertChar, deleteChar, replaceChar});
        }
    }
}
~~~

### Wildcard Matching

**Problem model:** `?` consumes one text character. `*` either consumes no character or consumes one and remains active.

**Derivation:** State `dp[i][j]` says whether pattern prefix `i` matches text prefix `j`. Normal matches and `?` use diagonal. A `*` tries empty use or one-character use. Empty-text matching needs an all-stars pattern prefix. The full match is the final table cell.

`?` matches one character. `*` matches empty or many characters.

~~~cpp
bool allStars(string& pattern, int length) {
    for (int i = 0; i < length; i++) {
        if (pattern[i] != '*') return false;
    }
    return true;
}

dp[0][0] = true;
for (int i = 1; i <= n; i++) dp[i][0] = allStars(pattern, i);

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
            dp[i][j] = dp[i - 1][j - 1];
        } else if (pattern[i - 1] == '*') {
            dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
}
~~~

### Common bugs

- Confusing prefix length `i` with string index `i - 1`.
- Missing base-row and base-column initialization.
- Using `int` where a count can overflow.

---

## 6. Stock DP

### Recognition clue

At each day, buy, sell, or skip. Holding status is part of the state.

### At most K transactions

**Problem model:** The future changes based on the day, whether a stock is held, and how many sales remain.

**Derivation:** State `dp[ind][buy][cap]` holds all three facts. Buy/skip is legal when `buy` is true; sell/skip when holding. No days or no sales remaining are bases. Today reads tomorrow, so loop days backward. Begin at `dp[0][1][k]`.

State: `dp[ind][buy][cap]` = maximum profit from day `ind`, where `buy == 1` means we may buy and `cap` is the remaining number of sales.

~~~cpp
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy) {
                    dp[ind][buy][cap] = max(
                        -prices[ind] + dp[ind + 1][0][cap],
                        dp[ind + 1][1][cap]);
                } else {
                    dp[ind][buy][cap] = max(
                        prices[ind] + dp[ind + 1][1][cap - 1],
                        dp[ind + 1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][k];
}
~~~

### Variant map

- Stock I: one transaction; greedy minimum-price scan is enough.
- Stock II: unlimited transactions; remove `cap`.
- Stock III: use `cap = 2`.
- Stock IV: use supplied `k`.
- Cooldown: after selling, move to `ind + 2`.
- Transaction fee: subtract `fee` on selling, or on buying, consistently.

### Common bug

Decrement `cap` on selling, not buying.

---

## 7. LIS Family

### Recognition clue

Find an increasing subsequence, often with reconstruction, counting, or a related ordering condition.

### O(n^2) LIS

**Problem model:** Treat the current value as the end of a subsequence and ask which earlier smaller value can precede it.

**Derivation:** State `dp[i]` is LIS length ending at `i`. Try every smaller earlier `prev`. Every value alone has length one. Loop left to right because only earlier indices are used. The answer is the maximum over all endpoints.

`dp[i]` = LIS length ending at index `i`.

~~~cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int answer = 1;

    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[prev] < nums[i]) {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        answer = max(answer, dp[i]);
    }
    return answer;
}
~~~

### O(n log n) LIS length

`tails[length - 1]` stores the smallest possible ending value for that length.

~~~cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;

    for (int value : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), value);
        if (it == tails.end()) tails.push_back(value);
        else *it = value;
    }
    return tails.size();
}
~~~

### Number of LIS

**Problem model:** A longest sequence can reach the same endpoint by several routes, so retain both the best length and its count.

**Derivation:** `length[i]` is best length ending at `i` and `ways[i]` counts it. A strictly better predecessor replaces the count; an equally good predecessor adds its count. Start every index with length one and one way. Sum counts at global best length.

Maintain both `length[i]` and `ways[i]`.

~~~cpp
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> length(n, 1), ways(n, 1);
    int bestLength = 1;

    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[prev] >= nums[i]) continue;

            if (length[prev] + 1 > length[i]) {
                length[i] = length[prev] + 1;
                ways[i] = ways[prev];
            } else if (length[prev] + 1 == length[i]) {
                ways[i] += ways[prev];
            }
        }
        bestLength = max(bestLength, length[i]);
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (length[i] == bestLength) answer += ways[i];
    }
    return answer;
}
~~~

### Derived problems

- Largest Divisible Subset: sort, then use `nums[i] % nums[prev] == 0`.
- Longest String Chain: sort by length and test each one-character-deletion predecessor.
- Longest Bitonic Subsequence: LIS from the left plus decreasing LIS from the right.

---

## 8. Interval / Partition DP

### Recognition clue

Choose a final split, multiplication point, balloon, or partition boundary within an interval.

### Core invariant

`dp[i][j]` is the best answer for the closed interval `[i, j]`. Try every split `k`.

~~~cpp
for (int len = 2; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;

        for (int k = i; k < j; k++) {
            // combine dp[i][k] and dp[k + 1][j]
        }
    }
}
~~~

### Matrix Chain Multiplication

**Problem model:** The final multiplication splits the chain after some matrix `k`, leaving two independent smaller chains.

**Derivation:** State `dp[i][j]` is minimum cost for matrices `i..j`. Try every final split `k`. One matrix needs zero operations. Large intervals use smaller intervals, so increase interval length. The full answer is `dp[1][n - 1]` in the dimension-array form.

State: minimum multiplications for matrices `i` through `j`.

~~~cpp
for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j <= n - 1; j++) {
        int best = 1000000000;

        for (int k = i; k < j; k++) {
            int cost = arr[i - 1] * arr[k] * arr[j]
                     + dp[i][k] + dp[k + 1][j];
            best = min(best, cost);
        }
        dp[i][j] = best;
    }
}
~~~

### Burst Balloons

**Problem model:** Early bursts change neighbors. Choose the balloon burst **last** in an interval so its outside neighbors are fixed.

**Derivation:** State `dp[i][j]` is best coins from bursting all balloons in `[i, j]`. Try every `k` as the last burst. Empty interval is `0`. Compute short intervals before long ones. After padding with boundary ones, return the whole original interval.

Choose the **last** balloon burst in interval `[i, j]` so its neighbors are known.

~~~cpp
nums.insert(nums.begin(), 1);
nums.push_back(1);

for (int len = 1; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;

        for (int k = i; k <= j; k++) {
            dp[i][j] = max(dp[i][j],
                nums[i - 1] * nums[k] * nums[j + 1]
                + dp[i][k - 1] + dp[k + 1][j]);
        }
    }
}
~~~

### Boolean Expression Evaluation

State: `dp[i][j][isTrue]` = number of ways substring `[i, j]` evaluates to true/false. Split only at operators, so use `k += 2`.

### Palindrome Partitioning II

**Problem model:** Select a first palindromic piece; the remaining suffix is the same problem.

**Derivation:** State `dp[i]` is minimum palindrome pieces in suffix `i..n-1`. Try every `j` where `s[i..j]` is a palindrome. Empty suffix has zero pieces. Later suffixes are needed first, so loop right to left. Pieces are one more than cuts, giving `dp[0] - 1`.

State: `dp[i]` = minimum number of palindrome pieces for the suffix starting at `i`.

~~~cpp
vector<int> dp(n + 1, 0);

for (int i = n - 1; i >= 0; i--) {
    int best = 1000000000;

    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, s)) {
            best = min(best, 1 + dp[j + 1]);
        }
    }
    dp[i] = best;
}

return dp[0] - 1;
~~~

### Partition Array for Maximum Sum

State: `dp[i]` = best value obtainable from suffix starting at `i`.

~~~cpp
for (int i = n - 1; i >= 0; i--) {
    int maxValue = 0;

    for (int j = i; j < min(n, i + k); j++) {
        maxValue = max(maxValue, arr[j]);
        dp[i] = max(dp[i], maxValue * (j - i + 1) + dp[j + 1]);
    }
}
~~~

### Common bugs

- Using an ordinary left/right split for Burst Balloons instead of choosing the last balloon.
- Forgetting the padded `1` values in Burst Balloons.
- Returning palindrome pieces rather than cuts.

---

## 9. DP on Squares and Histograms

### Count Square Submatrices With All Ones

**Problem model:** An all-ones square ending at a cell grows only as far as top, left, and diagonal supporting squares allow.

**Derivation:** State `dp[i][j]` is largest square side ending at this cell. A one-cell extends `1 + min(top, left, diagonal)`; a zero makes no square. First row/column ones have side one. Fill top-left to bottom-right and sum every value as the answer.

State: `dp[i][j]` = side length of the largest all-ones square ending at `(i, j)`.

~~~cpp
int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1],
                                        dp[i - 1][j - 1]});
                }
                answer += dp[i][j];
            }
        }
    }
    return answer;
}
~~~

### Maximal Rectangle of Ones

**Problem model:** Each row is the bottom of a histogram whose bar heights are consecutive ones above that row.

**Derivation:** State `height[col]` is consecutive ones ending in this row. Update heights top to bottom; a zero resets its height. For every row, use Largest Rectangle in Histogram. The answer is the largest histogram area among all rows.

Convert each row into a histogram of consecutive heights. For every row, call your **Largest Rectangle in Histogram** monotonic-stack template.

~~~cpp
vector<int> height(m, 0);

for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
        height[col] = matrix[row][col] == '1' ? height[col] + 1 : 0;
    }
    answer = max(answer, largestRectangleArea(height));
}
~~~

This is a DP-plus-monotonic-stack problem; do not invent a new 2D recurrence for it.

---

## Pending Striver DP: Best Completion Order

Do not finish every pending question before writing templates. Add a template, then validate it with the problem that introduces it.

1. **Ninja and his Friends:** two-agent grid DP.
2. **Rod Cutting:** unbounded knapsack.
3. **Distinct Subsequences:** counting DP on two strings.
4. **Edit Distance:** three-operation string DP.
5. **Wildcard Matching:** boolean string DP.
6. **Number of Longest Increasing Subsequences:** length plus count DP.
7. **Partition Array for Maximum Sum:** one-dimensional partition DP.
8. **Palindrome Partitioning II:** partition DP with palindrome checks.
9. **Burst Balloons:** choose-last interval DP.
10. **Different Ways to Evaluate a Boolean Expression:** interval counts.
11. **Count Square Submatrices With All Ones:** square DP.
12. **Maximum Rectangle Area With All Ones:** histogram reduction.

## Revision Rule

~~~text
Day 0: solve and write the state/transition.
Day 2: recreate the skeleton without notes.
Day 7: timed re-solve.
Day 21: solve it in a mixed-topic session.
~~~

You own a template when you can explain its state, write its base cases, and choose its loop direction without seeing an old solution.
