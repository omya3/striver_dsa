# Day 2 — C++ Syntax Recall (30 Minutes)

Topics: `deque`, `pair`, max-heap, and min-heap.

## Rules

1. Work only in `drill.cpp`.
2. Do not open `solution.cpp` during the first 27 minutes.
3. Compile after each function instead of waiting until the end.
4. If stuck for 90 seconds, write a short guess and move to the next TODO.
5. At minute 30, stop and record the syntax you forgot.

## Compile and run

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

You can use `g++` instead of `clang++`.

## 0–3 minutes: Setup recall

Add all required standard-library headers to `drill.cpp` from memory. You will
need input/output, strings, deque, pairs, priority queues, vectors, and the
`greater` comparator.

## 3–10 minutes: Deque drill

Complete `deque_drill()`.

Starting with an empty `deque<int>`:

1. Use both ends to create `10 20 30 40`.
2. Print its front, back, and size.
3. Remove one item from each end.
4. Print the remaining elements with a range-based loop.
5. Print whether the deque is empty.

Expected section output:

```text
front=10 back=40 size=4
after pops: 20 30
empty=false
```

## 10–17 minutes: Pair drill

Complete `pair_drill()`.

1. Declare `pair<string, int>` containing `"Omkar"` and `80`.
2. Print it with `.first` and `.second`.
3. Change the score to `95` and print it again.
4. Create `"Aman", 72` using `make_pair()`.
5. Read the second pair with structured binding and print the two variables.

Expected section output:

```text
student=Omkar 80
updated=Omkar 95
second=Aman 72
```

## 17–25 minutes: Heap drill

Complete `heap_drill()` using these values:

```text
5 1 8 3 8
```

1. Declare a default max-heap.
2. Declare a min-heap using `vector<int>` and `greater<int>`.
3. Push every value into both heaps.
4. Print and remove all max-heap elements.
5. Print and remove all min-heap elements.

Expected section output:

```text
max-heap: 8 8 5 3 1
min-heap: 1 3 5 8 8
```

Remember: `pop()` removes the top element but does not return it.

## 25–30 minutes: Mixed challenge

Complete `mixed_drill()`.

1. Declare `deque<pair<string, int>> tasks`.
2. Use both ends to create this exact order:

```text
email 2
coding 5
meeting 3
```

3. Print each pair.
4. Put every task priority into a max-heap.
5. Print the priorities from highest to lowest.

Expected section output:

```text
tasks:
email 2
coding 5
meeting 3
priorities: 5 3 2
```

## Final recall check

Before opening the solution, write these declarations once from memory on a
blank line at the bottom of `drill.cpp` (then comment them out):

- `deque<pair<string, int>>`
- max-heap of integers
- min-heap of integers

After the session, write down only the declarations or operations you forgot.
Those become the first two-minute warm-up tomorrow.

