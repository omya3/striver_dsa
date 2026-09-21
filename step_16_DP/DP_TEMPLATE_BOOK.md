# Dynamic Programming Template Book

## How to use this book

For every DP problem, identify these five things before coding:

1. **State:** what does `dp[...]` mean?
2. **Transition:** what choices are available?
3. **Base case:** what is the smallest valid state?
4. **Order:** recursion direction or tabulation loop direction.
5. **Answer:** which final state is returned?

This book is **memoization-first**. First write the recursive state and choices,
then add a cache. Convert to tabulation or space optimization only after the
dependencies are clear. Iterative code is retained only when loop order is the
main idea or deep recursion would be unsafe.

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
// Recursive direction / dependencies:
// Answer state:
~~~
## 1. One-dimensional DP

### Recognition clue

At index `i`, the decision depends only on a few earlier indices: climb, jump, rob, or take/skip.

### Take / not-take invariant

**Problem model:** At every index, take the current value or skip it. Taking it rules out the adjacent value.

**Derivation:** State `dp[ind]` is the best answer for `0..ind`. Choices are
skip (`solve(ind - 1)`) or take (`arr[ind] + solve(ind - 2)`). The base is one
element or no elements. Recursion moves toward smaller indices, and the answer
is `solve(n - 1)`.

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

**Derivation:** State `dp[row][col]` is the number of ways, or minimum cost, to
reach this cell. Combine recursive answers from above and left. The start cell
is the base, invalid negative coordinates return the neutral or impossible
value, and the answer begins at `(n - 1, m - 1)`.

`dp[row][col]` means the answer on reaching cell `(row, col)`.

~~~cpp
int minimumPath(int row, int col, vector<vector<int>>& grid,
                vector<vector<int>>& dp) {
    const int INF = 1000000000;

    if (row < 0 || col < 0) return INF;
    if (row == 0 && col == 0) return grid[0][0];
    if (dp[row][col] != -1) return dp[row][col];

    int fromUp = minimumPath(row - 1, col, grid, dp);
    int fromLeft = minimumPath(row, col - 1, grid, dp);

    return dp[row][col] = grid[row][col] + min(fromUp, fromLeft);
}
~~~

Call it for `(n - 1, m - 1)` with `dp` initialized to `-1`. For **counting
paths**, return `0` outside the grid and add the two recursive results. For
**obstacles**, return `0` immediately for a blocked cell.

### Triangle DP

From `(row, col)`, choose the down or diagonal-down child.

~~~cpp
int trianglePath(int row, int col, vector<vector<int>>& triangle,
                 vector<vector<int>>& dp) {
    int n = triangle.size();
    if (row == n - 1) return triangle[row][col];
    if (dp[row][col] != -1) return dp[row][col];

    int down = trianglePath(row + 1, col, triangle, dp);
    int diagonal = trianglePath(row + 1, col + 1, triangle, dp);

    return dp[row][col] = triangle[row][col] + min(down, diagonal);
}
~~~

### Ninja Training: Day and Last Activity

**Problem model:** There are three activities each day. Choose exactly one, but
the same activity cannot be chosen on consecutive days.

**The five questions:**

1. **State:** `dp[day][last]` is the maximum score through `day` when activity
   `last` is forbidden on that day. Use `last == 3` when nothing is forbidden.
2. **Transition:** try every `task != last`, collect today's points, and make
   that task forbidden for the previous subproblem.
3. **Base case:** on day `0`, take the best task other than `last`.
4. **Order:** recurse from the final day toward day `0` and memoize `(day,last)`.
5. **Answer:** `solve(n - 1, 3)`.

~~~cpp
int ninjaTraining(int day, int last, vector<vector<int>>& points,
                  vector<vector<int>>& dp) {
    if (day == 0) {
        int best = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) best = max(best, points[0][task]);
        }
        return best;
    }

    if (dp[day][last] != -1) return dp[day][last];

    int best = 0;
    for (int task = 0; task < 3; task++) {
        if (task == last) continue;
        best = max(best, points[day][task]
                       + ninjaTraining(day - 1, task, points, dp));
    }
    return dp[day][last] = best;
}
~~~

Call with `day = n - 1`, `last = 3`, and an `n x 4` cache initialized to `-1`.
Complexity is `O(n * 4 * 3)` time and `O(n * 4)` cache memory.

**Common bugs:** returning a state with a real activity forbidden instead of
`last == 3`, or using `dp[day - 1][last]` after selecting `task`.

### Two-agent grid DP

**Problem model:** Two agents move down together. Both columns affect the future, so the state needs both positions.

**Derivation:** State `dp[row][col1][col2]` is the best collection from this
row. Try all nine pairs of next moves. The last row is the base, collecting a
shared cell once. Recursion moves to `row + 1`, and the answer starts at
`solve(0, 0, m - 1)`.

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

### Maximum-value 0/1 Knapsack

**Problem model:** Every item has a weight and value. Each item may be taken at
most once, and total weight cannot exceed the capacity.

**The five questions:**

1. **State:** `dp[ind][cap]` is the maximum value obtainable from items
   `ind..n-1` with remaining capacity `cap`.
2. **Transition:** skip the item, or take it and add its value to the result for
   `cap - weight`.
3. **Base case:** value is zero when `ind == n`.
4. **Order:** recurse to `ind + 1`; taking reduces capacity.
5. **Answer:** `solve(0, capacity)`.

~~~cpp
long long zeroOneKnapsack(int ind, int cap, vector<int>& weight,
                          vector<int>& value, vector<vector<long long>>& dp) {
    if (ind == (int)weight.size()) return 0;
    if (dp[ind][cap] != -1) return dp[ind][cap];

    long long skip = zeroOneKnapsack(ind + 1, cap, weight, value, dp);
    long long take = LLONG_MIN / 4;

    if (weight[ind] <= cap) {
        take = value[ind] + zeroOneKnapsack(
            ind + 1, cap - weight[ind], weight, value, dp);
    }
    return dp[ind][cap] = max(take, skip);
}
~~~

**Complexity:** `O(n * capacity)` time and `O(n * capacity)` cache memory.

**Common bug:** recursing on the same `ind` after taking, which permits reuse
and silently changes the problem into unbounded knapsack.

### Boolean subset sum

**Problem model:** Each number can be selected once or skipped, and selecting it reduces the target.

**Derivation:** State `dp[ind][target]` asks whether values from `ind` onward
can make the target. Skip the current value or take it and solve the reduced
target. Both choices move to `ind + 1`, preventing reuse. The answer is
`solve(0, target)`.

State: `dp[ind][target]` = can elements from `ind` onward make `target`?

~~~cpp
bool isSubsetSum(int ind, int target, vector<int>& arr,
                 vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (ind == (int)arr.size()) return false;
    if (dp[ind][target] != -1) return dp[ind][target];

    bool skip = isSubsetSum(ind + 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target) {
        take = isSubsetSum(ind + 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = take || skip;
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
long long countSubsets(int ind, int target, vector<int>& arr,
                       vector<vector<long long>>& dp, int mod) {
    if (ind == (int)arr.size()) return target == 0;
    if (dp[ind][target] != -1) return dp[ind][target];

    long long skip = countSubsets(ind + 1, target, arr, dp, mod);
    long long take = 0;
    if (arr[ind] <= target) {
        take = countSubsets(ind + 1, target - arr[ind], arr, dp, mod);
    }
    return dp[ind][target] = (take + skip) % mod;
}
~~~

This forward recursion handles zeros naturally: at a zero, take and skip enter
the same remaining target as two distinct choices. Do not use `target == 0` as
an early base case when zeros may remain; stop only at `ind == n`.

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

**Derivation:** State `dp[ind][capacity]` is the best value using items from
`ind` onward. Taking an item leaves `capacity - weight[ind]` and keeps `ind`
unchanged, so the same item remains reusable. Skipping moves to `ind + 1`.

~~~cpp
long long unboundedKnapsack(int ind, int capacity, vector<int>& value,
                            vector<int>& weight,
                            vector<vector<long long>>& dp) {
    if (ind == (int)value.size() || capacity == 0) return 0;
    if (dp[ind][capacity] != -1) return dp[ind][capacity];

    long long skip = unboundedKnapsack(
        ind + 1, capacity, value, weight, dp);
    long long take = LLONG_MIN / 4;

    if (weight[ind] <= capacity) {
        take = value[ind] + unboundedKnapsack(
            ind, capacity - weight[ind], value, weight, dp);
    }
    return dp[ind][capacity] = max(take, skip);
}
~~~

### Minimum Coins

**Problem model:** Coins may be reused. Find the minimum number whose values
sum exactly to `amount`; report impossible when no combination exists.

**The five questions:**

1. **State:** `dp[remaining]` is the minimum coins needed to form `remaining`.
2. **Transition:** try every coin that fits and use
   `1 + solve(remaining - coin)`.
3. **Base case:** zero remaining amount needs zero coins.
4. **Order:** recursion continually reduces the remaining amount.
5. **Answer:** `solve(amount)`, converted to `-1` if impossible.

~~~cpp
int minimumCoins(int remaining, vector<int>& coins, vector<int>& dp) {
    const int INF = 1000000000;
    if (remaining == 0) return 0;
    if (dp[remaining] != -1) return dp[remaining];

    int best = INF;
    for (int coin : coins) {
        if (coin <= remaining) {
            int smaller = minimumCoins(remaining - coin, coins, dp);
            if (smaller != INF) best = min(best, 1 + smaller);
        }
    }
    return dp[remaining] = best;
}
~~~

Call with a cache of size `amount + 1` initialized to `-1`; convert `INF` to
`-1` only in the public wrapper. Complexity is
`O(numberOfCoins * amount)` time and `O(amount)` cache memory.

**Common bugs:** using `INT_MAX` and then adding one, or initializing an
impossible positive sum to zero.

### Coin Combinations: Ordered Versus Unordered

The recurrence can look identical while the **loop order changes what is
counted**.

#### Ordered sequences: CSES Coin Combinations I

**Problem model:** `2 + 3` and `3 + 2` are different constructions.

1. **State:** `dp[remaining]` is the number of ordered sequences producing the
   remaining sum.
2. **Transition:** choose the final coin and append it to every sequence for
   `sum - coin`.
3. **Base case:** remaining sum zero has one empty completion.
4. **Order:** recurse by choosing the next coin; coin order is therefore kept.
5. **Answer:** `solve(target)`.

~~~cpp
long long countOrdered(int remaining, vector<int>& coins,
                       vector<long long>& dp, int mod) {
    if (remaining == 0) return 1;
    if (dp[remaining] != -1) return dp[remaining];

    long long ways = 0;
    for (int coin : coins) {
        if (coin <= remaining) {
            ways = (ways + countOrdered(
                remaining - coin, coins, dp, mod)) % mod;
        }
    }
    return dp[remaining] = ways;
}
~~~

#### Unordered combinations: CSES Coin Combinations II

**Problem model:** `2 + 3` and `3 + 2` represent the same multiset of coins.

1. **State:** `dp[ind][remaining]` is the number of combinations using coin
   denominations from `ind` onward.
2. **Transition:** add combinations that include the current coin.
3. **Base case:** remaining zero has one valid combination; no coins with a
   positive remainder has none.
4. **Order:** skip moves to `ind + 1`; take stays at `ind`, preserving a
   canonical denomination order.
5. **Answer:** `solve(0, target)`.

~~~cpp
long long countUnordered(int ind, int remaining, vector<int>& coins,
                         vector<vector<long long>>& dp, int mod) {
    if (remaining == 0) return 1;
    if (ind == (int)coins.size()) return 0;
    if (dp[ind][remaining] != -1) return dp[ind][remaining];

    long long skip = countUnordered(
        ind + 1, remaining, coins, dp, mod);
    long long take = 0;
    if (coins[ind] <= remaining) {
        take = countUnordered(
            ind, remaining - coins[ind], coins, dp, mod);
    }
    return dp[ind][remaining] = (take + skip) % mod;
}
~~~

Both versions use `O(numberOfCoins * target)` time and `O(target)` memory.
The recognition question is: **Does changing the order of selected coins create
a new answer?**

### Rod Cutting

Rod Cutting is unbounded knapsack:

- item length = `len`;
- item value = `price[len - 1]`;
- capacity = rod length `n`.

~~~cpp
int cutRod(int ind, int remainingLength, vector<int>& price,
           vector<vector<int>>& dp) {
    if (ind == 0) return remainingLength * price[0];
    if (dp[ind][remainingLength] != -1) {
        return dp[ind][remainingLength];
    }

    int skip = cutRod(ind - 1, remainingLength, price, dp);
    int take = INT_MIN / 4;
    int pieceLength = ind + 1;

    if (pieceLength <= remainingLength) {
        take = price[ind] + cutRod(
            ind, remainingLength - pieceLength, price, dp);
    }
    return dp[ind][remainingLength] = max(take, skip);
}
~~~

### Common bugs

- Iterating backward and accidentally turning it into 0/1 knapsack.
- Not allowing the `take` transition to remain on the same item.
- Comparing the item index with the piece length. In the recursive form,
  `pieceLength = ind + 1`, and the fit check must compare the piece length with
  the remaining rod capacity:

~~~cpp
int pieceLength = ind + 1;
if (pieceLength <= remainingLength) {
    take = price[ind] + solve(ind, remainingLength - pieceLength, price, dp);
}
~~~

The units should match: compare **length with remaining length**, never index
with length. Keep `ind` unchanged after taking because the same cut length can
be used again.

### Representative problems

Minimum Coins, Coin Change II, Unbounded Knapsack, Rod Cutting.

---

## 5. DP on Strings

### Recognition clue

The state is determined by prefixes of one or two strings.

### Longest Common Subsequence

**Problem model:** Compare final characters of two prefixes. A match can join the subsequence; on a mismatch, one final character must be discarded.

**Derivation:** State `dp[i][j]` is the LCS length of suffixes beginning at
`i` and `j`. A match consumes both characters; a mismatch skips one character
from either string. Reaching the end of either string gives zero. The answer is
`solve(0, 0)`.

State: `dp[i][j]` = LCS length of suffixes `s[i..]` and `t[j..]`.

~~~cpp
int longestCommonSubsequence(int i, int j, string& s, string& t,
                             vector<vector<int>>& dp) {
    if (i == (int)s.size() || j == (int)t.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        return dp[i][j] = 1 + longestCommonSubsequence(
            i + 1, j + 1, s, t, dp);
    }

    return dp[i][j] = max(
        longestCommonSubsequence(i + 1, j, s, t, dp),
        longestCommonSubsequence(i, j + 1, s, t, dp));
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

State: `dp[i][j]` = ways for source suffix `s[i..]` to form target suffix
`t[j..]`.

~~~cpp
long long numDistinct(int i, int j, string& s, string& t,
                      vector<vector<long long>>& dp) {
    if (j == (int)t.size()) return 1;
    if (i == (int)s.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    long long skip = numDistinct(i + 1, j, s, t, dp);
    long long use = 0;
    if (s[i] == t[j]) {
        use = numDistinct(i + 1, j + 1, s, t, dp);
    }
    return dp[i][j] = use + skip;
}
~~~

At a match, skipping and using the source character are two different choices.

### Edit Distance

**Problem model:** When final characters differ, the final operation is insert, delete, or replace.

**Derivation:** State `dp[i][j]` is the minimum operations to convert source
suffix `i` into target suffix `j`. Equal characters consume both. Otherwise,
insert advances `j`, delete advances `i`, and replace advances both. An empty
suffix requires the length of the other suffix. The answer is `solve(0, 0)`.

State: minimum operations to convert suffix `s[i..]` into `t[j..]`.

~~~cpp
int editDistance(int i, int j, string& s, string& t,
                 vector<vector<int>>& dp) {
    if (i == (int)s.size()) return t.size() - j;
    if (j == (int)t.size()) return s.size() - i;
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        return dp[i][j] = editDistance(i + 1, j + 1, s, t, dp);
    }

    int insertChar = editDistance(i, j + 1, s, t, dp);
    int deleteChar = editDistance(i + 1, j, s, t, dp);
    int replaceChar = editDistance(i + 1, j + 1, s, t, dp);

    return dp[i][j] = 1 + min({insertChar, deleteChar, replaceChar});
}
~~~

### Wildcard Matching

**Problem model:** `?` consumes one text character. `*` either consumes no character or consumes one and remains active.

**Derivation:** State `dp[i][j]` says whether pattern prefix `i` matches text prefix `j`. Normal matches and `?` use diagonal. A `*` tries empty use or one-character use. Empty-text matching needs an all-stars pattern prefix. The full match is the final table cell.

`?` matches one character. `*` matches empty or many characters. Here `i` and
`j` are prefix lengths.

~~~cpp
bool allStars(string& pattern, int length) {
    for (int i = 0; i < length; i++) {
        if (pattern[i] != '*') return false;
    }
    return true;
}

int wildcardMatch(int i, int j, string& pattern, string& text,
                  vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return true;
    if (i == 0) return false;
    if (j == 0) return allStars(pattern, i);
    if (dp[i][j] != -1) return dp[i][j];

    if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
        return dp[i][j] = wildcardMatch(
            i - 1, j - 1, pattern, text, dp);
    }

    if (pattern[i - 1] == '*') {
        bool useEmpty = wildcardMatch(i - 1, j, pattern, text, dp);
        bool useCharacter = wildcardMatch(i, j - 1, pattern, text, dp);
        return dp[i][j] = useEmpty || useCharacter;
    }

    return dp[i][j] = false;
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

**Derivation:** State `dp[ind][buy][cap]` holds all three facts. Buy/skip is
legal when `buy` is true; sell/hold when holding. No days or no sales remaining
are bases. Every choice moves to a later day, and the answer begins at
`solve(0, 1, k)`.

State: `dp[ind][buy][cap]` = maximum profit from day `ind`, where `buy == 1` means we may buy and `cap` is the remaining number of sales.

~~~cpp
int stockProfit(int ind, int buy, int cap, vector<int>& prices,
                vector<vector<vector<int>>>& dp) {
    if (ind == (int)prices.size() || cap == 0) return 0;
    if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    if (buy) {
        int take = -prices[ind]
                 + stockProfit(ind + 1, 0, cap, prices, dp);
        int skip = stockProfit(ind + 1, 1, cap, prices, dp);
        return dp[ind][buy][cap] = max(take, skip);
    }

    int sell = prices[ind]
             + stockProfit(ind + 1, 1, cap - 1, prices, dp);
    int hold = stockProfit(ind + 1, 0, cap, prices, dp);
    return dp[ind][buy][cap] = max(sell, hold);
}
~~~

Call `stockProfit(0, 1, k, prices, dp)` with an
`n x 2 x (k + 1)` cache initialized to `-1`.

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

### Memoized take/skip LIS

**Problem model:** At every index, skip the value or take it when it is larger
than the previously selected value.

**Derivation:** State `dp[ind][prev + 1]` is the best length from `ind` onward.
The `+1` shift stores `prev == -1` at column zero. Skipping advances only
`ind`; taking advances `ind` and changes `prev`.

`dp[ind][prev + 1]` = LIS length available from `ind` when the previous chosen
index is `prev`.

~~~cpp
int lengthOfLIS(int ind, int prev, vector<int>& nums,
                vector<vector<int>>& dp) {
    if (ind == (int)nums.size()) return 0;
    if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

    int skip = lengthOfLIS(ind + 1, prev, nums, dp);
    int take = 0;
    if (prev == -1 || nums[ind] > nums[prev]) {
        take = 1 + lengthOfLIS(ind + 1, ind, nums, dp);
    }
    return dp[ind][prev + 1] = max(take, skip);
}
~~~

Call with `(0, -1)`. Complexity is `O(n^2)` time and cache memory.

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

Memoize a pair for every endpoint: best length ending there and the number of
ways to obtain that length.

~~~cpp
pair<int, long long> lisEndingAt(
    int i, vector<int>& nums, vector<pair<int, long long>>& dp,
    vector<char>& seen) {
    if (seen[i]) return dp[i];
    seen[i] = true;

    int bestLength = 1;
    long long ways = 1;

    for (int prev = 0; prev < i; prev++) {
        if (nums[prev] >= nums[i]) continue;
        auto [previousLength, previousWays] =
            lisEndingAt(prev, nums, dp, seen);

        int candidateLength = previousLength + 1;
        if (candidateLength > bestLength) {
            bestLength = candidateLength;
            ways = previousWays;
        } else if (candidateLength == bestLength) {
            ways += previousWays;
        }
    }
    return dp[i] = {bestLength, ways};
}

long long numberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, long long>> dp(n);
    vector<char> seen(n, false);
    int globalLength = 0;
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        auto [length, ways] = lisEndingAt(i, nums, dp, seen);
        if (length > globalLength) {
            globalLength = length;
            answer = ways;
        } else if (length == globalLength) {
            answer += ways;
        }
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
long long solveInterval(int i, int j, vector<vector<long long>>& dp) {
    if (i > j) return EMPTY_INTERVAL_VALUE;
    if (i == j) return SINGLE_ITEM_VALUE;
    if (dp[i][j] != UNVISITED) return dp[i][j];

    long long best = INITIAL_VALUE;
    for (int k = i; k < j; k++) {
        best = combine(best,
                       solveInterval(i, k, dp),
                       solveInterval(k + 1, j, dp),
                       splitCost(i, k, j));
    }
    return dp[i][j] = best;
}
~~~

`EMPTY_INTERVAL_VALUE`, `INITIAL_VALUE`, and `combine` depend on whether the
problem asks for a minimum, maximum, or count.

### Matrix Chain Multiplication

**Problem model:** The final multiplication splits the chain after some matrix `k`, leaving two independent smaller chains.

**Derivation:** State `dp[i][j]` is minimum cost for matrices `i..j`. Try every
final split `k` and recursively solve the two resulting chains. One matrix
needs zero operations. The full answer is `solve(1, n - 1)` in the
dimension-array form.

State: minimum multiplications for matrices `i` through `j`.

~~~cpp
long long matrixChain(int i, int j, vector<int>& dimensions,
                      vector<vector<long long>>& dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    long long best = LLONG_MAX;
    for (int k = i; k < j; k++) {
        long long cost = 1LL * dimensions[i - 1] * dimensions[k]
                       * dimensions[j]
                       + matrixChain(i, k, dimensions, dp)
                       + matrixChain(k + 1, j, dimensions, dp);
        best = min(best, cost);
    }
    return dp[i][j] = best;
}
~~~

### Burst Balloons

**Problem model:** Early bursts change neighbors. Choose the balloon burst **last** in an interval so its outside neighbors are fixed.

**Derivation:** State `dp[i][j]` is best coins from bursting all balloons in `[i, j]`. Try every `k` as the last burst. Empty interval is `0`. Compute short intervals before long ones. After padding with boundary ones, return the whole original interval.

Choose the **last** balloon burst in interval `[i, j]` so its neighbors are known.

~~~cpp
int burstBalloons(int i, int j, vector<int>& nums,
                  vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int best = 0;
    for (int k = i; k <= j; k++) {
        int coins = nums[i - 1] * nums[k] * nums[j + 1]
                  + burstBalloons(i, k - 1, nums, dp)
                  + burstBalloons(k + 1, j, nums, dp);
        best = max(best, coins);
    }
    return dp[i][j] = best;
}
~~~

Insert boundary value `1` at both ends, then call the function on the original
balloon interval `[1, n]`.

### Boolean Expression Evaluation

**Problem model:** An expression alternates operands (`T`, `F`) and operators
(`&`, `|`, `^`). Count parenthesizations that evaluate to true.

**The five questions:**

1. **State:** `dp[i][j][truth]` counts ways expression interval `[i, j]`
   evaluates to false or true.
2. **Transition:** choose each operator `k` as the final operation, then combine
   the left/right true and false counts according to that operator.
3. **Base case:** a one-character interval contributes one way to its literal
   truth value.
4. **Order:** recurse on the left and right intervals around each operator.
5. **Answer:** the true count returned for `[0, n - 1]`.

~~~cpp
pair<long long, long long> evaluateExpression(
    int i, int j, string& expression,
    vector<vector<pair<long long, long long>>>& dp,
    vector<vector<char>>& seen, int mod) {
    if (i == j) {
        return expression[i] == 'T' ? make_pair(1LL, 0LL)
                                    : make_pair(0LL, 1LL);
    }
    if (seen[i][j]) return dp[i][j];
    seen[i][j] = true;

    long long totalTrue = 0;
    long long totalFalse = 0;

    for (int k = i + 1; k < j; k += 2) {
        auto [lt, lf] = evaluateExpression(
            i, k - 1, expression, dp, seen, mod);
        auto [rt, rf] = evaluateExpression(
            k + 1, j, expression, dp, seen, mod);

        if (expression[k] == '&') {
            totalTrue += lt * rt;
            totalFalse += lt * rf + lf * rt + lf * rf;
        } else if (expression[k] == '|') {
            totalTrue += lt * rt + lt * rf + lf * rt;
            totalFalse += lf * rf;
        } else { // '^'
            totalTrue += lt * rf + lf * rt;
            totalFalse += lt * rt + lf * rf;
        }

        totalTrue %= mod;
        totalFalse %= mod;
    }
    return dp[i][j] = {totalTrue, totalFalse};
}
~~~

The pair stores `{trueWays, falseWays}`. This avoids writing a separate
`isTrue` dimension while preserving the same state information.

**Complexity:** `O(n^3)` time and `O(n^2)` memory.

**Common bugs:** splitting at operands instead of operators, forgetting false
counts, and multiplying in `int` before applying the modulus.

### Palindrome Partitioning II

**Problem model:** Select a first palindromic piece; the remaining suffix is the same problem.

**Derivation:** State `dp[i]` is minimum palindrome pieces in suffix `i..n-1`.
Try every `j` where `s[i..j]` is a palindrome, then recurse from `j + 1`.
The empty suffix has zero pieces. Pieces are one more than cuts, giving
`solve(0) - 1`.

State: `dp[i]` = minimum number of palindrome pieces for the suffix starting at `i`.

~~~cpp
int minimumPalindromePieces(int i, string& s,
                            vector<vector<char>>& palindrome,
                            vector<int>& dp) {
    int n = s.size();
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    int best = 1000000000;
    for (int j = i; j < n; j++) {
        if (palindrome[i][j]) {
            best = min(best, 1 + minimumPalindromePieces(
                j + 1, s, palindrome, dp));
        }
    }
    return dp[i] = best;
}
~~~

The required cuts equal `minimumPalindromePieces(0, ...) - 1`.

Calling an `O(n)` palindrome check inside both loops makes the solution
`O(n^3)`. Precompute palindrome intervals first:

~~~cpp
vector<vector<char>> buildPalindromeTable(const string& s) {
    int n = s.size();
    vector<vector<char>> palindrome(n, vector<char>(n, false));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            palindrome[i][j] =
                s[i] == s[j] &&
                (j - i <= 2 || palindrome[i + 1][j - 1]);
        }
    }
    return palindrome;
}
~~~

Use `palindrome[i][j]` in the partition loop. The complete approach then uses
`O(n^2)` time and `O(n^2)` memory.

**Common bug:** returning the number of palindrome pieces. A partition into
`p` pieces uses `p - 1` cuts.

### Partition Array for Maximum Sum

State: `dp[i]` = best value obtainable from suffix starting at `i`.

~~~cpp
int partitionMaximumSum(int i, int k, vector<int>& arr, vector<int>& dp) {
    int n = arr.size();
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    int maxValue = 0;
    int best = 0;

    for (int j = i; j < min(n, i + k); j++) {
        maxValue = max(maxValue, arr[j]);
        int current = maxValue * (j - i + 1)
                    + partitionMaximumSum(j + 1, k, arr, dp);
        best = max(best, current);
    }
    return dp[i] = best;
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

**Derivation:** State `dp[i][j]` is the largest square side ending at this cell.
A one-cell recursively extends `1 + min(top, left, diagonal)`; a zero or an
out-of-grid coordinate contributes zero. Call the state for every endpoint and
sum the returned side lengths.

State: `dp[i][j]` = side length of the largest all-ones square ending at `(i, j)`.

~~~cpp
int squareEndingAt(int i, int j, vector<vector<int>>& matrix,
                   vector<vector<int>>& dp) {
    if (i < 0 || j < 0 || matrix[i][j] == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int up = squareEndingAt(i - 1, j, matrix, dp);
    int left = squareEndingAt(i, j - 1, matrix, dp);
    int diagonal = squareEndingAt(i - 1, j - 1, matrix, dp);

    return dp[i][j] = 1 + min({up, left, diagonal});
}
~~~

Call `squareEndingAt(i, j)` for every cell and add the returned side lengths.
Each square of side `s` contributes one square of every size `1..s`, so summing
the largest side at every endpoint counts all squares. Total complexity remains
`O(n * m)`.

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

## 10. Additional OA DP Patterns

### Weighted Interval Scheduling: CSES Projects

**Problem model:** Every job has a start time, inclusive end time, and reward.
Choose non-overlapping jobs with maximum total reward.

**The five questions:**

1. **State:** after sorting by start time, `dp[i]` is the maximum reward from
   jobs `i..n-1`.
2. **Transition:** skip job `i`, or take it and jump to the first job starting
   strictly after its end.
3. **Base case:** `dp[n] = 0` when no job remains.
4. **Order:** recurse to `i + 1` or binary-search the next compatible index.
5. **Answer:** `solve(0)`.

~~~cpp
struct Job {
    long long start;
    long long end;
    long long reward;
};

long long maximumProjectReward(int i, vector<Job>& jobs,
                               vector<long long>& starts,
                               vector<long long>& dp) {
    if (i == (int)jobs.size()) return 0;
    if (dp[i] != -1) return dp[i];

    int next = upper_bound(starts.begin(), starts.end(), jobs[i].end)
             - starts.begin();

    long long take = jobs[i].reward
                   + maximumProjectReward(next, jobs, starts, dp);
    long long skip = maximumProjectReward(i + 1, jobs, starts, dp);

    return dp[i] = max(take, skip);
}
~~~

Sort jobs by start time, build the `starts` array, initialize `dp` to `-1`, and
call the function at index zero.

**Complexity:** `O(n log n)` time and `O(n)` memory.

**Common bugs:** using `lower_bound(end)` for CSES Projects even though the end
time is inclusive, binary-searching before sorting, or storing rewards in
`int`.

### Finite-state DP: CSES Counting Towers

**Problem model:** At each height, the top boundary can be in one of two
structural states. The exact construction history is irrelevant once that
boundary state is known.

Use:

- `joined[h]`: configurations of height `h` ending in the joined boundary
  state;
- `split[h]`: configurations ending in the two-part boundary state.

**The five questions:**

1. **State:** height and one of the two boundary states.
2. **Transition:** extend every previous boundary in all legal ways:
   `joined[h] = 2 * joined[h-1] + split[h-1]` and
   `split[h] = joined[h-1] + 4 * split[h-1]`.
3. **Base case:** at height one, each boundary state has one configuration.
4. **Order:** precompute heights from `2` up to the largest query.
5. **Answer:** `(joined[n] + split[n]) % MOD`.

This template intentionally stays iterative. The maximum height is `10^6`, so
a recursive memoized chain could overflow the call stack, and all test cases
benefit from one shared precomputation.

~~~cpp
vector<long long> countingTowers(int maxHeight, int mod) {
    vector<long long> joined(maxHeight + 1, 0);
    vector<long long> split(maxHeight + 1, 0);
    vector<long long> answer(maxHeight + 1, 0);

    joined[1] = split[1] = 1;
    answer[1] = 2;

    for (int h = 2; h <= maxHeight; h++) {
        joined[h] = (2 * joined[h - 1] + split[h - 1]) % mod;
        split[h] = (joined[h - 1] + 4 * split[h - 1]) % mod;
        answer[h] = (joined[h] + split[h]) % mod;
    }
    return answer;
}
~~~

**Complexity:** `O(maxHeight + numberOfQueries)` total time after
precomputation and `O(maxHeight)` memory.

**Recognition clue:** when many histories behave identically in the future,
group them into a small number of boundary states rather than remembering the
full construction.

**Common bugs:** merging the two states too early, answering with only one
state, or recomputing the table independently for every query.

---

## Core Coverage Checklist

The core Striver and interview-oriented DP templates are now present. Use this
table as a revision tracker rather than a pending-problem list.

| Family | Anchor problems | Covered |
| --- | --- | --- |
| One-dimensional decisions | Frog Jump, House Robber | Yes |
| Day and previous choice | Ninja Training | Yes |
| Grid and two-agent states | Unique Paths, Ninja and Friends | Yes |
| 0/1 subset and knapsack | Subset Sum, Book Shop | Yes |
| Unbounded choices | Minimum Coins, Coin Combinations, Rod Cutting | Yes |
| Two-string DP | LCS, Distinct Subsequences, Edit Distance, Wildcard | Yes |
| Stock state machines | Stock I-IV, cooldown, fee | Yes |
| LIS length/count/reconstruction | LIS, Number of LIS, divisible subset | Yes |
| Interval and front partitioning | MCM, Burst Balloons, Palindrome II | Yes |
| Matrix shapes | Count Squares, Maximal Rectangle | Yes |
| Weighted scheduling | CSES Projects | Yes |
| Finite-state recurrence | CSES Counting Towers | Yes |

Advanced families such as tree DP, DAG DP, bitmask DP, and digit DP are not
required to revise the Striver core. Add them later only when a target problem
actually requires them.

## Revision Rule

~~~text
Day 0: solve and write the state/transition.
Day 2: recreate the skeleton without notes.
Day 7: timed re-solve.
Day 21: solve it in a mixed-topic session.
~~~

You own a template when you can explain its state, write its base cases, and choose its loop direction without seeing an old solution.
