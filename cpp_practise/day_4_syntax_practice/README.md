# Day 4 — C++ Syntax Practice (30 Minutes)

Today focuses on syntax commonly needed in DSA problems:

- nested vectors and nested traversal
- `string::find`, `substr`, and `reverse`
- sorting pairs with a lambda comparator
- building an adjacency list

## Rules

1. Work only in `drill.cpp`.
2. Do not open `solution.cpp` until minute 27.
3. Compile after completing each function.
4. Fix only the first compiler error before compiling again.
5. Stop after 30 minutes and begin solving problems.

## Compile and run

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

## 0–3 minutes: Header recall

Add the headers needed for input/output, vectors, strings, pairs, sorting, and
reversing. Compile immediately.

## 3–9 minutes: Nested vectors

Complete `nested_vector_drill()`.

1. Add the row `{7, 8, 9}` to the supplied matrix.
2. Print the first row using an index-based loop.
3. Print the entire matrix with nested range-based loops.
4. Calculate the sum of all elements.

Expected:

```text
first row: 1 2 3
matrix:
1 2 3
4 5 6
7 8 9
sum=45
```

## 9–15 minutes: String operations

Complete `string_drill()` using `"striver-dsa"`.

1. Find the position of `'-'`.
2. Use `substr()` to extract the text before and after the dash.
3. Make a copy of the original string and reverse the copy.
4. Use `find()` and `string::npos` to check whether `"cpp"` occurs.

Expected:

```text
left=striver right=dsa
reversed=asd-revirts
cpp=missing
```

## 15–22 minutes: Sort pairs with a lambda

Complete `pair_sort_drill()`.

Sort the supplied students using these rules:

1. Higher score first.
2. When scores are equal, alphabetically smaller name first.
3. Print the sorted pairs using structured binding.

Expected:

```text
scores:
Ravi 90
Zoya 90
Neha 82
Aman 75
```

Your comparator must answer: “Should `a` appear before `b`?”

## 22–30 minutes: Build an adjacency list

Complete `graph_drill()` for the supplied undirected edges.

1. Create `vector<vector<int>> graph` with four vertices.
2. Read each edge using structured binding.
3. Add both directions because the graph is undirected.
4. Sort every neighbour list.
5. Print each vertex and its neighbours.

Expected:

```text
graph:
0: 1 2
1: 0 3
2: 0 3
3: 1 2
```

## Final 60-second recall

Without looking back, type or say these shapes:

```cpp
vector<vector<int>> matrix;
text.substr(start, length);
sort(values.begin(), values.end(), comparator);
for (const auto& [first, second] : pairs)
```

Then stop the drill and start solving problems.

