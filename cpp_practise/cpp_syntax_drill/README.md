# C++ STL Syntax Drill — 45 Minutes

## Rule for the session

Do not copy from `solution.cpp` during the first 40 minutes. Type from memory,
compile often, and use compiler errors as feedback. If stuck for more than 90
seconds, look up only the one declaration you need, close it, and type it again.

## Run commands

From this directory:

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

`g++` can be used instead of `clang++`.

## Timer

### 0–3 minutes: Warm-up

Open `drill.cpp`. From memory, add all required standard-library headers and
write `using` declarations or use `std::` explicitly. Compile immediately.

### 3–10 minutes: Vector and string traversal

Complete `traversal_drill()`.

- Print the vector once with an index-based loop.
- Print it again with a range-based loop.
- Change every vector element to twice its value using references.
- Print every character of the string with an iterator.
- Count vowels in the string.

Expected final values: doubled vector `4 8 8 2 10`; vowel count `4`.

### 10–17 minutes: `unordered_map` frequency table

Complete `frequency_drill()`.

- Build a word-frequency table using `operator[]`.
- Print the count of `red` using `.at()`.
- Check whether `green` exists using `.find()`.
- Print every key/value pair. Its order is intentionally unspecified.

Expected: `red=3`, `blue=2`, `green=missing`.

### 17–23 minutes: `set`

Complete `set_drill()`.

- Insert every input value.
- Try inserting `3` again and inspect the returned boolean.
- Look up `7` with `.find()`.
- Delete `1` with `.erase()`.
- Print the remaining set in its natural order.

Expected remaining values: `3 5 7 9`.

### 23–29 minutes: `deque`

Complete `deque_drill()`.

- Use `push_front` and `push_back` to create `10 20 30 40`.
- Print `front()` and `back()`.
- Use `pop_front` and `pop_back` once each.
- Print the remaining deque.

Expected remaining values: `20 30`.

### 29–35 minutes: Max-heap and min-heap

Complete `heap_drill()` with two `priority_queue` objects.

- Push all the values into a default max-heap.
- Declare a min-heap using `vector<int>` and `greater<int>`.
- Pop and print each heap until empty.

Expected max order: `9 7 4 2 1`; min order: `1 2 4 7 9`.

### 35–40 minutes: `sort`, `lower_bound`, and `upper_bound`

Complete `algorithm_drill()`.

- Sort the data ascending.
- Find the first position where `4` could occur with `lower_bound`.
- Find the first position after all `4`s with `upper_bound`.
- Compute the number of `4`s from the iterator difference.
- Sort a copy descending with `greater<int>`.

Expected sorted data: `1 2 4 4 4 7 9`; bounds: `[2, 5)`; count: `3`.

### 40–45 minutes: Closed-book speed round

Without viewing earlier code, create `speed.cpp` and type these six declarations:

1. `vector<string>` containing three words
2. `unordered_map<char, int>` frequency table
3. `set<int>` and an insert/find/erase sequence
4. `deque<int>` with one operation at each end
5. max-heap and min-heap declarations
6. sorted vector plus `lower_bound` and `upper_bound`

Compile it. If it fails, fix it before the timer ends. Then compare only the
parts you missed with `solution.cpp` and retype those declarations once.

## How to score yourself

- **8/8 topics recalled:** repeat tomorrow in 20 minutes.
- **6–7:** repeat the failed declarations at the end of today.
- **0–5:** redo the full drill tomorrow; prioritize typing over reading.

