# String Template Book

Use this book for active recall. For each pattern, read the problem model, close
the file, write the invariant and C++ skeleton from memory, and then solve its
representative problem. The explanations sit directly beside the code.

The code snippets use C++17 and assume standard headers (`#include <bits/stdc++.h>`
on competitive-programming platforms). Functions with the same name in different
sections are alternatives, not meant to be pasted into one source file together.

## Choose the pattern before coding

| Question in the prompt | First pattern to consider |
| --- | --- |
| Are characters being balanced or grouped? | One-pass state / run-length scan |
| Does a pattern occur in a text, including overlaps? | KMP or Z function |
| Do we need equal prefix and suffix lengths? | Prefix function / border chain |
| Are many fixed-length substrings being compared? | Rolling hash, with collision checks |
| Is the source string repeated until the target appears? | Bounded repetition + substring search |
| Must characters be prepended to make a palindrome? | Longest palindromic prefix + KMP |
| Is the longest palindromic substring required? | Center expansion; Manacher for linear time |

These are **string matching and construction** templates. Sliding windows belong
to the sliding-window topic; LCS, edit distance and wildcard matching already
live in [`DP_TEMPLATE_BOOK.md`](../step_16_DP/DP_TEMPLATE_BOOK.md). Trie code
is in [`step_17_tries`](../step_17_tries).

## Coverage of your existing solutions

| Local solution | Revise section |
| --- | --- |
| [`1_min_add_mk_para_valid.cpp`](1_min_add_mk_para_valid.cpp) | 1. Balance scan |
| [`2_count_and_say.cpp`](2_count_and_say.cpp) | 2. Run-length scan |
| [`6_kmp.cpp`](6_kmp.cpp) | 3. Prefix function and KMP |
| [`8_longest_happy_prefix.cpp`](8_longest_happy_prefix.cpp) | 4. Borders and periods |
| [`5_zfunction.cpp`](5_zfunction.cpp) | 5. Z function |
| [`3_rabin_karp.cpp`](3_rabin_karp.cpp) | 6. Rolling hash |
| [`4_a_repeated_string_match.cpp`](4_a_repeated_string_match.cpp), [`4_b_repeated_string_match.cpp`](4_b_repeated_string_match.cpp) | 7. Repeated string match |
| [`7_a_shortest_pallindrome.cpp`](7_a_shortest_pallindrome.cpp), [`7_b_shortest_pallindrome_using_rabin_karp.cpp`](7_b_shortest_pallindrome_using_rabin_karp.cpp) | 8. Shortest palindrome |

Sections 4's period rule and 9 are **new extensions** for CSES, not claims that
you have already solved their representative problems.

---

## 1. Balance Scan: Minimum Additions for Valid Parentheses

### Problem model and recognition clue

In `"()))("`, some closing brackets have no earlier opening bracket, and some
opening brackets remain unmatched at the end. Count the minimum brackets that
must be inserted. The order matters, so total counts of `'('` and `')'` alone
are insufficient.

### How to derive the state

After reading a prefix, `open` is the number of unmatched `'('`. A `')'`
consumes one open bracket when possible; otherwise it needs a new `'('` before
it, so increment `missingOpen`. At the end, every remaining open bracket needs
a `')'`. The answer is `missingOpen + open`.

### Skeleton code

```cpp
int minAddToMakeValid(const string& s) {
    int open = 0;
    int missingOpen = 0;

    for (char ch : s) {
        if (ch == '(') {
            open++;
        } else if (open > 0) {
            open--;
        } else {
            missingOpen++;
        }
    }

    return missingOpen + open;
}
```

### Complexity and common bugs

`O(n)` time, `O(1)` space. Do not cancel a closing bracket with an opening
bracket that occurs later. For multiple bracket types or nested syntax, use a
stack; one integer no longer captures the state.

### Representative problem

Minimum Add to Make Parentheses Valid.

---

## 2. Run-Length Scan: Count and Say

### Problem model and recognition clue

`"111221"` consists of three `1`s, two `2`s, then one `1`. Describing these
consecutive runs gives `"312211"`. The task repeats this transformation from
the seed `"1"`.

### How to derive the state

Keep the first index of the current run. Move `i` to the first different
character, append the run length and its character, and start the next run.
Every run is emitted exactly once, including the final one.

### Skeleton code

```cpp
string describeRuns(const string& s) {
    string result;
    int n = static_cast<int>(s.size());

    for (int start = 0; start < n; ) {
        int end = start;
        while (end < n && s[end] == s[start]) end++;

        result += to_string(end - start);
        result += s[start];
        start = end;
    }
    return result;
}

string countAndSay(int n) {
    string current = "1";
    for (int term = 2; term <= n; term++) {
        current = describeRuns(current);
    }
    return current;
}
```

### Complexity and common bugs

One transformation takes `O(|s|)` time and output space. The total for `n`
terms depends on the lengths of the generated terms. Do not forget the final
run; `to_string(count)` is required when the count has multiple digits.

### Representative problem

Count and Say.

---

## 3. Prefix Function and KMP Search

### Problem model and recognition clue

Find all occurrences of a pattern in a text, including overlaps. For example,
`"aba"` occurs in `"ababa"` at positions `0` and `2`. Restarting the whole
comparison after a mismatch repeats work.

### How to derive the state

`pi[i]` is the length of the longest **proper** prefix of `pattern[0..i]` that
is also a suffix of that substring. If `j` characters have matched and the
next one differs, `pi[j - 1]` tells us how many matched characters can still be
kept. The text index does not move backward. After a full match, fall back to
`pi[m - 1]` to keep possible overlapping matches.

### Skeleton code

```cpp
vector<int> prefixFunction(const string& pattern) {
    int m = static_cast<int>(pattern.size());
    vector<int> pi(m, 0);

    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmpMatches(const string& text, const string& pattern) {
    vector<int> positions;
    if (pattern.empty()) return positions; // Adapt if empty patterns are allowed.

    vector<int> pi = prefixFunction(pattern);
    int m = static_cast<int>(pattern.size());
    int j = 0;

    for (int i = 0; i < static_cast<int>(text.size()); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) j++;

        if (j == m) {
            positions.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    return positions;
}
```

### Complexity and common bugs

`O(n + m)` time and `O(m)` space for text length `n`, pattern length `m`.
`pi[i]` is a **length**, not an index. On mismatch use `pi[j - 1]`, not
`pi[j]`. After a match, keep the fallback so overlapping matches survive.
Check whether the judge wants zero-based positions, one-based positions, a
count, or only the first match.

### Representative problems

Striver KMP search; CSES [String Matching](https://cses.fi/problemset/task/1753/);
NeetCode [Find the Index of the First Occurrence in a String](https://neetcode.io/problems/find-the-index-of-the-first-occurrence-in-a-string/question).

---

## 4. Border Chain and Periods From the Prefix Function

### Problem model and recognition clue

A **border** is a nonempty prefix that is also a suffix but is shorter than the
whole string. `"ababab"` has borders of lengths `2` (`"ab"`) and `4`
(`"abab"`). A **period** `p` means `s[i] == s[i - p]` for every `i >= p`;
the final copy may be incomplete.

### How to derive the state

`pi[n - 1]` gives the longest proper border. Following `pi[length - 1]`
repeatedly gives every shorter border. For a period `p < n`, the suffix
`s[p..n-1]` must equal the prefix `s[0..n-p-1]`; the Z function tests that as
`z[p] >= n - p`. Every string also has period `n`.

### Skeleton code

```cpp
vector<int> allBorderLengths(const string& s) {
    if (s.empty()) return {};
    vector<int> pi = prefixFunction(s);
    vector<int> borders;

    for (int length = pi.back(); length > 0; length = pi[length - 1]) {
        borders.push_back(length);
    }
    reverse(borders.begin(), borders.end());
    return borders;
}

vector<int> allPeriods(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> z = zFunction(s); // Defined in section 5.
    vector<int> periods;

    for (int length = 1; length <= n; length++) {
        if (length == n || z[length] >= n - length) {
            periods.push_back(length);
        }
    }
    return periods;
}
```

For **Longest Happy Prefix**, return `s.substr(0, pi.back())` after checking
for an empty string. “Happy” here means a proper border, not necessarily a
palindrome.

### Complexity and common bugs

`O(n)` time and space. Do not include the entire string among its borders.
Do include `n` among its periods. If the problem requires a whole number of
repetitions, add `n % p == 0`; CSES Finding Periods allows a partial final
copy.

### Representative problems

Longest Happy Prefix; CSES [Finding Borders](https://cses.fi/problemset/task/1732/)
and [Finding Periods](https://cses.fi/problemset/task/1733/).

---

## 5. Z Function and Pattern Search

### Problem model and recognition clue

At every index `i`, find how many characters match the entire string's prefix.
For `"ababa"`, the suffix starting at index `2` begins with `"aba"`, so
`z[2] = 3`. This supports pattern matching, border checks and period checks.

### How to derive the state

Maintain `[left, right]`, the rightmost segment known to match the prefix.
Inside it, reuse the already computed result at `i - left`, capped by the
remaining segment length. Then compare characters beyond the known segment.

### Skeleton code

```cpp
vector<int> zFunction(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> z(n, 0);
    int left = 0, right = 0;

    for (int i = 1; i < n; i++) {
        if (i <= right) {
            z[i] = min(right - i + 1, z[i - left]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> zMatches(const string& text, const string& pattern) {
    if (pattern.empty()) return {};
    string joined = pattern + '#' + text; // '#' must be absent from inputs.
    vector<int> z = zFunction(joined);
    vector<int> positions;
    int m = static_cast<int>(pattern.size());

    for (int i = m + 1; i < static_cast<int>(joined.size()); i++) {
        if (z[i] >= m) positions.push_back(i - m - 1);
    }
    return positions;
}
```

### Complexity and common bugs

`O(n)` for the Z array; `O(n + m)` for matching. `z[0]` is conventionally zero
here. Keep the right boundary inclusive. Choose a separator outside the input
alphabet, or use KMP's two-string search when no safe separator exists.

### Representative problems

Striver Z Function; CSES String Matching and String Functions.

---

## 6. Rabin-Karp: Fixed-Length Rolling Hash

### Problem model and recognition clue

Compare a pattern with every text window of the same length. A polynomial hash
allows the next window hash to be updated by removing the outgoing character
and adding the incoming one. Equal hashes are only candidates for equality.

### How to derive the state

For a window of length `m`, the first character contributes
`value * base^(m-1)`. Subtract it, multiply the remaining hash by `base`, then
add the new last character. Keep all arithmetic modulo `MOD`. Confirm any
hash match by comparing characters because collisions are possible.

### Skeleton code

```cpp
vector<int> rabinKarpMatches(const string& text, const string& pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());
    vector<int> positions;
    if (m == 0 || m > n) return positions;

    const long long MOD = 1000000007LL;
    const long long BASE = 257;
    auto value = [](char ch) { return static_cast<unsigned char>(ch) + 1; };

    long long highestPower = 1;
    for (int i = 1; i < m; i++) {
        highestPower = highestPower * BASE % MOD;
    }

    long long targetHash = 0, windowHash = 0;
    for (int i = 0; i < m; i++) {
        targetHash = (targetHash * BASE + value(pattern[i])) % MOD;
        windowHash = (windowHash * BASE + value(text[i])) % MOD;
    }

    for (int start = 0; start + m <= n; start++) {
        if (targetHash == windowHash &&
            text.compare(start, m, pattern) == 0) {
            positions.push_back(start);
        }

        if (start + m < n) {
            windowHash = (windowHash - value(text[start]) * highestPower % MOD
                          + MOD) % MOD;
            windowHash = (windowHash * BASE + value(text[start + m])) % MOD;
        }
    }
    return positions;
}
```

### Complexity and common bugs

Hash updates take `O(n + m)` time; verification adds the lengths of checked
windows and can make the worst case `O(nm)`. Extra space is `O(1)` aside from
output. Do not use a single hash as proof of equality. Normalize a negative
subtraction before taking `%`, and use a wide enough integer type for products.

### Representative problems

Rabin-Karp Pattern Search, Repeated String Match (hash variant).

---

## 7. Repeated String Match

### Problem model and recognition clue

Given `a` and `b`, find the fewest copies of `a` whose concatenation contains
`b`. A match may begin near the end of one copy and finish in the next.

### How to derive the bound

At least `ceil(|b| / |a|)` copies are needed by length. A valid match can start
at any offset less than `|a|`, so at most **one more** copy than this lower
bound is needed. Test those two counts using substring search. The extra test
at `count + 2` in the existing file is harmless but unnecessary.

### Skeleton code

```cpp
int repeatedStringMatch(const string& a, const string& b) {
    int copies = (static_cast<int>(b.size()) +
                  static_cast<int>(a.size()) - 1) /
                 static_cast<int>(a.size()); // Inputs are nonempty.

    string repeated;
    for (int i = 0; i < copies; i++) repeated += a;
    if (repeated.find(b) != string::npos) return copies;

    repeated += a;
    if (repeated.find(b) != string::npos) return copies + 1;

    return -1;
}
```

### Complexity and common bugs

The bound requires `O(|a| + |b|)` constructed characters. The complexity of
`std::string::find` depends on its implementation; use KMP for a guaranteed
`O(|a| + |b|)` search after construction. Do not test only the lower bound:
`a = "abcd"`, `b = "cdabcdab"` needs a wrap-around match.

### Representative problem

Repeated String Match.

---

## 8. Shortest Palindrome by Prepending Characters

### Problem model and recognition clue

Only characters may be added **before** the string. For `"abcd"`, the longest
prefix already forming a palindrome is `"a"`; reverse the remaining suffix
`"bcd"` and prepend it to obtain `"dcbabcd"`.

### How to derive the state

Let `reverseS = reverse(s)`. Compute the prefix function of
`s + '#' + reverseS`. Its last value is the length of the longest prefix of
`s` equal to a suffix of `reverseS`, which is exactly the longest palindromic
prefix of `s`. Prepend the reverse of the remaining suffix.

### Skeleton code

```cpp
string shortestPalindrome(string s) {
    if (s.empty()) return "";

    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    string joined = s + '#' + reversed; // '#' absent from s.
    vector<int> pi = prefixFunction(joined);
    int palindromePrefixLength = pi.back();

    string suffix = s.substr(palindromePrefixLength);
    reverse(suffix.begin(), suffix.end());
    return suffix + s;
}
```

### Complexity and common bugs

`O(n)` time and space. Use a delimiter absent from the input alphabet. The
longest **palindromic prefix** is needed; finding the longest palindrome
anywhere in `s` does not solve this problem. A rolling forward/reverse hash can
suggest a palindromic prefix, but equal hashes may collide, so KMP is the
deterministic default.

### Representative problem

Shortest Palindrome.

---

## 9. Longest Palindromic Substring (CSES Extension)

### Problem model and recognition clue

Find the longest **contiguous** substring that reads the same both ways. This
is different from a palindromic subsequence, which may skip characters.
Center expansion is a good first solution; Manacher's algorithm is useful when
the string is too long for `O(n^2)`.

### How to derive the state

For each index `i`, `odd[i]` is the number of mirrored character pairs around
center `i`, including the center itself; the palindrome length is
`2 * odd[i] - 1`. `even[i]` is the number of pairs centered between `i - 1`
and `i`; its length is `2 * even[i]`. Keep the rightmost palindrome interval
`[left, right]`. A center inside it can copy a radius from its mirror, capped
by the boundary, before extending through new character comparisons.

### Skeleton code

```cpp
string longestPalindrome(const string& s) {
    int n = static_cast<int>(s.size());
    if (n == 0) return "";

    vector<int> odd(n), even(n);
    int left = 0, right = -1;

    for (int i = 0; i < n; i++) {
        int radius = (i > right) ? 1 : min(odd[left + right - i], right - i + 1);
        while (i - radius >= 0 && i + radius < n &&
               s[i - radius] == s[i + radius]) radius++;
        odd[i] = radius;
        if (i + radius - 1 > right) {
            left = i - radius + 1;
            right = i + radius - 1;
        }
    }

    left = 0;
    right = -1;
    for (int i = 0; i < n; i++) {
        int radius = (i > right) ? 0 : min(even[left + right - i + 1], right - i + 1);
        while (i - radius - 1 >= 0 && i + radius < n &&
               s[i - radius - 1] == s[i + radius]) radius++;
        even[i] = radius;
        if (i + radius - 1 > right) {
            left = i - radius;
            right = i + radius - 1;
        }
    }

    int bestStart = 0, bestLength = 1;
    for (int i = 0; i < n; i++) {
        int oddLength = 2 * odd[i] - 1;
        int evenLength = 2 * even[i];
        if (oddLength > bestLength) {
            bestLength = oddLength;
            bestStart = i - odd[i] + 1;
        }
        if (evenLength > bestLength) {
            bestLength = evenLength;
            bestStart = i - even[i];
        }
    }
    return s.substr(bestStart, bestLength);
}
```

### Complexity and common bugs

`O(n)` time and space. Odd and even centers need separate formulas. `odd[i]`
stores a radius, not the final palindrome length. If this is your first
palindrome search, solve it with center expansion first, then learn the mirror
optimization above.

For the first solve, use center expansion to see the odd/even distinction:

```cpp
string longestPalindromeByCenters(const string& s) {
    int n = static_cast<int>(s.size());
    int bestStart = 0, bestLength = 0;

    auto expand = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        int length = right - left - 1;
        if (length > bestLength) {
            bestLength = length;
            bestStart = left + 1;
        }
    };

    for (int center = 0; center < n; center++) {
        expand(center, center);     // Odd length.
        expand(center, center + 1); // Even length.
    }
    return s.substr(bestStart, bestLength);
}
```

This version is `O(n^2)` time and `O(1)` extra space. Manacher preserves the
same center idea while reusing information from the rightmost known palindrome.
Use center expansion to learn on small examples; CSES allows up to `10^6`
characters, so submit the linear-time Manacher version there.

### Representative problem

CSES [Longest Palindrome](https://cses.fi/problemset/task/1111/).

---

## First practice pass

1. Rewrite sections **3** and **5** without notes, then solve CSES
   [String Matching](https://cses.fi/problemset/task/1753/) with one of them.
2. Derive the border chain from `pi[n-1]` and solve CSES
   [Finding Borders](https://cses.fi/problemset/task/1732/).
3. Use the Z condition in section **4** for CSES
   [Finding Periods](https://cses.fi/problemset/task/1733/).
4. Take one **unseen** NeetCode All string problem. Give it a timed attempt,
   then map its idea to this book or write one short new pattern note.
5. Later, learn section **9** for CSES Longest Palindrome.

For a first day, steps 1 and 2 are enough. Do not rush through every template
before trying a problem; the problem is what makes the invariant memorable.
