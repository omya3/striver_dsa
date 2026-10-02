# Day 13 — Progressive Hints

Open the next hint only after three minutes of trying and tracing one failing case. Stop reading once you can continue.

## Palindrome

1. Treat `right` as the first index *after* the remaining range. The character on the right is `text[right - 1]`. `while (left < right)` also handles an empty string safely.
2. Inside the loop, first skip a non-alphanumeric left character with `++left; continue;`. Then skip a non-alphanumeric right character with `--right; continue;`.
3. Compare `tolower(static_cast<unsigned char>(text[left]))` with `tolower(static_cast<unsigned char>(text[right - 1]))`. Return `false` on mismatch; otherwise increment `left` and decrement `right`.

## Anagrams

1. Different lengths cannot be anagrams. Check that before allocating counts.
2. `array<int, 26> frequency{};` starts at all zeroes. For each `char ch` in the first string, use `++frequency[ch - 'a'];`. Use `--` for the second string.
3. A range loop over `frequency` can return `false` if any count is nonzero. If the loop finishes, return `true`.
