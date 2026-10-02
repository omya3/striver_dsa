# Day 12 — Distinct Islands: DFS, Coordinates, and `set` (30 minutes)

Today's placement pattern is **Number of Distinct Islands**, one of the remaining problems in your legacy Striver graph list. This is a syntax drill: write the DFS and STL declarations from memory, then run the supplied cases.

## Ground rule

Work in `drill.cpp`. Keep `solution.cpp` closed until minute 27. Compile after the DFS and again after the counting function.

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

An island is a four-direction connected group of `1` cells. Two islands have the same shape if one is a **translation** of the other. Rotating or reflecting a shape does not make it the same shape.

## 0–4 minutes: Recall yesterday's BFS

Without opening Day 11, fill the `RECALL` comment in `drill.cpp`:

1. The type for a queue of `{row, column}` cells.
2. The value assigned to the source distance before pushing it.
3. The value used for an unvisited cell.
4. Why bounds must be checked before reading `grid[next_row][next_column]`.

## 4–10 minutes: Types and DFS setup

Add only the standard headers you use. Declare:

```cpp
using Cell = pair<int, int>;
using Grid = vector<vector<int>>;
using Shape = vector<Cell>;
```

In `collect_shape`, mark the current cell as seen and append:

```text
{row - base_row, column - base_column}
```

The first land cell of an island is its base. Relative positions make identical islands match even when they appear elsewhere in the grid.

## 10–21 minutes: Four-direction DFS

Complete `collect_shape` using the same direction order every time: up, right, down, left.

For each neighbor, check in this order:

1. Is the row and column inside the grid?
2. Is the cell land (`1`)?
3. Has it not been visited?
4. If all three hold, recurse with the **same base row and base column**.

Use `const Grid&` for the input and references for `seen` and `shape`. Do not copy either container at every recursive call.

## 21–27 minutes: Count unique shapes

In `count_distinct_islands`:

1. Return `0` for an empty grid.
2. Create a visited grid initialized to `false` or `0`.
3. Declare `set<Shape> unique_shapes`.
4. Loop through every cell. For each unvisited land cell, create a fresh `Shape`, run DFS, sort it, and insert it into the set.
5. Return the set size as an `int`.

Sorting coordinates makes shape comparison independent of DFS visit order.

## 27–30 minutes: Run these cases

Fill the three grids in `main()` and get:

```text
repeated plus vertical=2
rotated shapes=2
all water=0
```

`repeated` has three translated copies of an L and one vertical island:

```text
1 1 0 1 1 0 0
1 0 0 1 0 0 1
0 0 0 0 0 0 1
0 1 1 0 0 0 0
0 1 0 0 0 0 0
```

`rotated` has two different orientations of an L. They count as distinct:

```text
1 1 0 1 0
1 0 0 1 1
```

`water` is a 2-by-3 grid of zeroes.

## Closed-book check

Write these on paper before moving to graph problems:

```text
set<Shape> declaration
relative-coordinate pair
sort a vector
DFS visited mark
```

If you run out of time, finish the DFS and one test. Keep the remaining cases for tomorrow's first five minutes.
