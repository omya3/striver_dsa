# Day 10 — Graph STL Foundations (30 Minutes)

Today's drill connects C++ syntax practice with graph revision. You will type
the containers and operations that appear repeatedly in placement problems:

- `vector<vector<pair<int, int>>>` adjacency lists
- structured bindings with `const auto&`
- `queue<int>` for BFS
- distance and visited arrays
- a min-heap of `{distance, node}` pairs
- stale-entry checking in Dijkstra

## Rules

1. Work only in `drill.cpp` for the first 27 minutes.
2. Do not open `solution.cpp` before minute 27.
3. Compile after completing each function.
4. Use the exact container types requested—this is a syntax-recall drill.
5. Stop after 30 minutes and begin graph problems.

## Compile and run

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

## Graph used in the drill

The graph is undirected and weighted:

```text
0 --4-- 1 --1-- 3 --3-- 4
 \      /       /
  1    2       5
   \  /       /
     2 -------
```

Edges are inserted in this order:

```text
0 1 4
0 2 1
2 1 2
1 3 1
2 3 5
3 4 3
```

Each adjacency-list pair stores:

```text
{neighbor, edge_weight}
```

## 0–5 minutes: Headers and aliases

Add the required headers for:

- input/output
- `vector`
- `pair`
- `queue` and `priority_queue`
- `greater`
- numeric limits

Declare these aliases:

```cpp
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
using State = pair<long long, int>;
```

Memory cue:

```text
Edge  = {neighbor, weight}
State = {distance, node}
```

## 5–10 minutes: Build and print the adjacency list

Implement:

```cpp
void add_undirected_edge(Graph& graph, int u, int v, int weight);
void print_graph(const Graph& graph);
```

For an undirected edge, add both directions.

In `print_graph()`, use an index loop for nodes and this range loop for edges:

```cpp
for (const auto& [neighbor, weight] : graph[node])
```

Why `const auto&`?

- `const`: the edge must not be modified.
- `&`: avoid copying each pair.
- structured binding: directly names both pair elements.

## 10–17 minutes: BFS distances

Implement:

```cpp
vector<int> bfs_distance(const Graph& graph, int source);
```

Treat every edge as one step, ignoring its weight.

Requirements:

- initialize every distance to `-1`
- use `queue<int>`
- set the source distance to `0` before pushing it
- mark a node discovered when pushing it, not when popping it
- traverse an edge with `const auto& [neighbor, weight]`
- prevent an unused-variable warning for `weight`

Expected BFS distances from node `0`:

```text
0 1 1 2 3
```

Memory cue:

```text
front -> pop -> inspect neighbors -> assign distance -> push
```

## 17–27 minutes: Dijkstra min-heap

Implement:

```cpp
vector<long long> dijkstra(const Graph& graph, int source);
```

Use:

```cpp
priority_queue<State, vector<State>, greater<State>> min_heap;
```

Requirements:

1. Initialize distances to a safe `INF` value.
2. Set the source distance to zero.
3. Push `{0, source}`.
4. Extract `{current_distance, node}` with structured binding.
5. Skip stale heap entries.
6. Relax every adjacent edge.
7. Push the improved `{distance, neighbor}` into the heap.

Expected shortest distances from node `0`:

```text
0 3 1 4 7
```

Memory cue:

```text
candidate = current distance + edge weight
if candidate is smaller -> update -> push
```

## 27–30 minutes: Closed-book recall

Write these without looking:

1. Weighted adjacency-list declaration.
2. Loop that unpacks `{neighbor, weight}` without copying.
3. BFS queue declaration.
4. Min-heap declaration for `{distance, node}`.
5. Dijkstra stale-entry condition.
6. The two insertions required for an undirected edge.

## Expected final output

```text
adjacency list:
0: (1,4) (2,1)
1: (0,4) (2,2) (3,1)
2: (0,1) (1,2) (3,5)
3: (1,1) (2,5) (4,3)
4: (3,3)
bfs distance: 0 1 1 2 3
dijkstra distance: 0 3 1 4 7
```

## Scoring

- **Everything works without warnings:** ready to revise graph problems.
- **BFS works but Dijkstra fails:** retype the min-heap declaration and the
  relaxation block three times.
- **Wrong adjacency list:** revise that an undirected edge is inserted twice.
- **Correct answers but warnings remain:** fix unused structured-binding values
  and signed/unsigned loop comparisons.
