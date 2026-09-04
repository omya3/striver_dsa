# Day 3 — C++ Problem-Solving Warm-up (30 Minutes)

Today reinforces syntax that appears constantly in DSA problems:

- `stack` and `queue`
- `unordered_map` frequency counting
- `sort`, `binary_search`, `lower_bound`, and `upper_bound`
- a mixed frequency/heap mini-problem

## Rules

1. Work only in `drill.cpp`.
2. Do not open `solution.cpp` until minute 27.
3. Compile after every function.
4. Read only the first compiler error, fix it, and compile again.
5. Stop at minute 30 and begin your problem-solving session.

## Compile and run

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

## 0–3 minutes: Header recall

Add the standard headers required for:

- input/output and strings
- vectors and pairs
- stack and queue
- unordered maps
- sorting and binary-search algorithms

Compile immediately, even if the functions are unfinished.

## 3–9 minutes: Stack and queue

Complete `stack_queue_drill()` using:

```text
4 1 7 2
```

1. Push every value into both a stack and a queue.
2. Print and remove every stack element.
3. Print and remove every queue element.

Expected:

```text
stack: 2 7 1 4
queue: 4 1 7 2
```

Remember that both `pop()` functions return nothing.

## 9–16 minutes: Frequency table

Complete `frequency_drill()` using the supplied words.

1. Declare `unordered_map<string, int>`.
2. Count each word with `operator[]` in one line inside the loop.
3. Print the counts of `apple` and `banana` using `.at()`.
4. Check for `kiwi` using `.find()` without inserting it.

Expected:

```text
apple=3
banana=2
kiwi=missing
```

## 16–23 minutes: Sorting and bounds

Complete `bounds_drill()`.

1. Sort the supplied vector ascending.
2. Print the sorted vector.
3. Find the first `4` using `lower_bound`.
4. Find the position after the last `4` using `upper_bound`.
5. Convert both iterators into zero-based positions.
6. Calculate the number of occurrences using iterator subtraction.
7. Use `binary_search` to check whether `6` exists.

Expected:

```text
sorted: 1 2 4 4 4 7 9
lower=2 upper=5 count=3
contains 6=false
```

Important: bounds require the range to be sorted first.

## 23–30 minutes: Mixed mini-problem

Complete `most_frequent_drill()` for:

```text
5 2 5 3 2 5
```

1. Put all values into a queue.
2. Process the queue into an `unordered_map<int, int>` frequency table.
3. Create a max-heap of `pair<int, int>` storing `{frequency, value}`.
4. Push every frequency-table entry into the heap.
5. Use the heap top to print the most frequent value and its count.

Expected:

```text
most_frequent=5 count=3
```

## Final 60-second recall

Without looking upward, say aloud what each expression returns:

```cpp
stack.top()
queue.front()
frequency[word]
lower_bound(first, last, target)
upper_bound(first, last, target)
```

Then start solving problems. Do not extend the warm-up beyond 30 minutes.

