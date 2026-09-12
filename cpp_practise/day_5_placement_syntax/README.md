# Day 5 — Placement-Focused C++ Drill (30 Minutes)

This is a **spiral drill**: it revisits syntax you have already used, fixes the
weak points from Day 4, and adds one common placement pattern.

Today covers:

- passing vectors by `const` reference and mutable reference
- `vector<vector<int>>` adjacency lists
- writing a reusable binary-search function
- Top-K frequency using `unordered_map` and a min-heap

## Rules

1. Work only in `drill.cpp`.
2. Do not open `solution.cpp` before minute 27.
3. Compile after each section.
4. Fix the first compiler error before reading the next one.
5. Stop at minute 30 and start solving placement problems.

## Compile and run

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

## 0–6 minutes: References and function syntax

Complete `print_values()` and `sort_descending()`.

1. `print_values()` must accept `const vector<int>&` because it only reads.
2. `sort_descending()` must accept `vector<int>&` because it modifies the
   caller's vector.
3. Sort using `greater<int>`.
4. Call both functions from `reference_drill()`.

Expected:

```text
original: 4 1 7 2
descending: 7 4 2 1
```

Recall:

- `const T&` — read the original without copying
- `T&` — modify the original
- `T` — work on a copy

## 6–13 minutes: Reliable adjacency-list syntax

Complete `graph_drill()`.

1. Create `vector<vector<int>> graph(vertex_count)`.
2. Read each edge with structured binding.
3. Add both directions for the undirected graph.
4. Sort each neighbour list using a **non-const reference**.
5. Print every vertex and its neighbours.

Expected:

```text
graph:
0: 1 2
1: 0 3
2: 0 3 4
3: 1 2
4: 2
```

Placement trap: `sort()` modifies its range, so you cannot sort through a
`const` reference.

## 13–20 minutes: Manual binary search

Complete `binary_search_index()` without calling `std::binary_search`.

Requirements:

1. Accept the sorted vector by `const` reference.
2. Use `left`, `right`, and `mid` indices.
3. Return the target's index when found.
4. Return `-1` when missing.
5. Calculate `mid` without using `(left + right) / 2`.

Expected:

```text
index of 7=3
index of 4=-1
```

## 20–28 minutes: Top-K frequent elements

Complete `top_k_frequent()` for:

```text
values = 1 1 1 2 2 3 3 3 3 4
k = 2
```

1. Build `unordered_map<int, int> frequency`.
2. Declare a min-heap of `pair<int, int>` containing `{count, value}`.
3. Push every frequency entry.
4. Whenever heap size exceeds `k`, remove the smallest entry.
5. Pop the remaining values into a vector.
6. Reverse the result so the highest frequency comes first.
7. Return the result vector.

Expected:

```text
top 2: 3 1
```

Target complexity: approximately `O(n log k)` time and `O(m + k)` extra space,
where `m` is the number of distinct values.

## 28–30 minutes: Closed-book declaration recall

Type these on blank lines without looking upward, then comment them out:

1. A nested integer vector with `n` rows.
2. An integer frequency map.
3. A min-heap of integer pairs.
4. A function parameter that reads a vector without copying it.
5. A function parameter that modifies the caller's vector.

## Scoring

- **5/5 declarations recalled:** move to placement problems immediately.
- **3–4:** retype only the missed declarations once.
- **0–2:** repeat this drill tomorrow before adding a new topic.

