# Day 11 — Grid BFS and Binary Maze (30 minutes)

This follows yesterday's weighted-graph drill and prepares you for **Shortest Path in a Binary Maze** from the older Striver graph sheet.

## Rules

1. Work in `drill.cpp`. Keep `solution.cpp` closed until minute 27.
2. Compile after each function. Read the first error and fix it before moving on.
3. Use four directions only. A cell containing `1` is open; `0` is blocked.
4. A distance is the **number of moves**, so source equals destination means `0`.
5. Stop at 30 minutes and start your graph problem practice.

Compile from this directory:

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

## 0–4 minutes: Yesterday's syntax recall

In the comment marked `RECALL` in `drill.cpp`, write these from memory:

```cpp
using State = pair<long long, int>; // {distance, node}
priority_queue<State, vector<State>, greater<State>> min_heap;
```

Yesterday's `State = pair<int, int>` was inconsistent with `vector<long long> dist`. A large shortest-path distance can be truncated when pushed into that heap. Do not edit yesterday's file during this timed drill.

Also answer in that comment: when adding an undirected edge, how many adjacency-list insertions are needed?

## 4–8 minutes: Grid syntax

Complete `in_bounds()` and declare the four row/column offsets. The pairs of offsets must represent **up, right, down, left**. An offset pair is one move; do not mix a row offset from one direction with a column offset from another.

Use `int` consistently for row, column, and grid dimensions to avoid signed/unsigned warnings.

## 8–24 minutes: Shortest path in a binary maze

Implement:

```cpp
int shortest_path(const Grid& grid, Cell source, Cell destination);
```

Required syntax and behavior:

- `using Cell = pair<int, int>;`
- `queue<Cell>` stores `{row, column}`.
- `vector<vector<int>> distance` starts with `-1` everywhere.
- Reject empty grids, out-of-bounds endpoints, and blocked endpoints.
- Mark the source as discovered (`distance = 0`) **when pushing it**.
- Read the queue with `front()`, then remove with `pop()`.
- Check bounds before indexing `grid[next_row][next_col]`.
- Push each open, unvisited neighbor once.
- Return `-1` when the destination cannot be reached.

Memory cue:

```text
check endpoints -> push source -> pop cell -> try four neighbors
                                  neighbor distance = current distance + 1
```

## 24–27 minutes: Test cases

Fill the TODOs in `main()` and get this exact output:

```text
reachable=5
same cell=0
blocked destination=-1
unreachable=-1
```

Use this reachable maze:

```text
1 1 0 1
0 1 1 1
1 1 0 1
```

From `{0,0}` to `{2,3}`, the shortest path has five moves.

For `unreachable`, use:

```text
1 0
0 1
```

from `{0,0}` to `{1,1}`.

## 27–30 minutes: Closed-book recall

Without looking, say or write:

1. The `queue` declaration for a `{row, column}` pair.
2. `front()` and `pop()` in the right order.
3. The bounds condition for a grid cell.
4. Why the source gets distance `0` before entering the queue.
5. Why this problem uses BFS instead of Dijkstra.

Optional after the timer: adapt this to **Distance of Nearest Cell Having One** by putting *all* `1` cells into the queue at distance `0` before BFS begins.
