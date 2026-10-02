# Day 13 — Learn String Patterns in 30 Minutes

Today is day 1 of your three-day string block. You will learn two reusable patterns: **two pointers** for a cleaned palindrome and a **frequency array** for lowercase anagrams. Tomorrow moves to word parsing; day 3 uses a sliding window.

The code already contains headers, a test harness, and `main()`. Your job is to implement only the two functions in [`drill.cpp`](drill.cpp). This keeps the time focused on decisions you will make in placement problems.

## How to use the 30 minutes

### 0–3 min: Predict before coding

Read the small `find`/`substr` example in `main()` and predict its two printed lines. Then answer on paper:

- For `"A, a"`, which characters should the palindrome check compare?
- What should happen for `""` and `"!!!"`?
- If `first = "aab"` and `second = "aba"`, what is the final frequency of `'a'`?

### 3–16 min: Implement `is_clean_palindrome`

Use a left index and an **exclusive** right index (`right = text.size()`). Skip punctuation and spaces. Compare letters without case sensitivity; digits still count.

Use `static_cast<unsigned char>(text[index])` before calling `isalnum` or `tolower`. This is the correct way to pass a possibly signed `char` to `<cctype>` functions.

Compile and run after this function. Only palindrome checks need to pass at this point.

### 16–25 min: Implement `are_anagrams_lowercase`

The inputs contain only `'a'` to `'z'`. First reject unequal lengths. Create `array<int, 26> frequency{};`, add counts for the first word, subtract counts for the second, then check that every count is zero.

Compile and run again. All checks should now pass.

### 25–30 min: Explain and transfer

Without reading your code, write one sentence for each:

1. Why does `right` start at `text.size()` instead of `text.size() - 1`?
2. Why is `array<int, 26> frequency{};` better than an uninitialized array here?
3. What would you change if the anagram inputs could contain uppercase letters or punctuation?

Then change one test input in `main()`, predict the new result, and run it. Restore the test afterward if you want the supplied output back.

## Run

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

The two opening lines should be:

```text
found at=4
substring=code
```

Your target is **13/13 checks passed**. If a check fails, trace just that input through your function before changing the code.

If you are stuck for three minutes, open [`HINTS.md`](HINTS.md) and reveal only the next hint for that function. Use `solution.cpp` after the timed drill to compare decisions, not merely to copy code.

## What to remember for placements

- `find()` returns `string::npos` when absent; check it before using the position.
- `substr(start, length)` returns a new string.
- Two pointers can scan from both ends without building a cleaned copy.
- A fixed 26-slot array is ideal only when the input alphabet is known to be lowercase English letters.
- A failing edge case is information: empty input, punctuation only, repeated letters, and unequal lengths reveal different mistakes.
