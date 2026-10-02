# Graph Template Book

Use this as the single revision source for graph patterns. A template is not a
complete answer to every problem. It preserves the state, invariant and control
flow that stay unchanged while the problem-specific validity rule changes.

## How to use this book

Before coding, answer these six questions:

1. **Model:** what are the vertices and edges?
2. **Direction:** directed or undirected?
3. **Weight:** unweighted, non-negative, negative, or a custom path cost?
4. **State:** is the node enough, or must the state also contain stops, a grid
   position, a mask, or another property?
5. **Invariant:** what is guaranteed when a state is removed from the frontier?
6. **Answer:** distance, traversal, component count, ordering, path, or number
   of ways?

For active recall, write the recognition clue and invariant first. Then write
the skeleton without looking. Finally, solve one representative problem.

## Coverage map

| Solved problem family | Template to revise |
|---|---|
| Provinces, connected components | DFS/BFS and components |
| Number of Islands, Flood Fill, Enclaves, Surrounded Regions | Grid traversal |
| Rotten Oranges, nearest zero/one | Multi-source BFS |
| Number of Distinct Islands | Shape-normalized grid DFS |
| Undirected cycle | Parent-aware BFS/DFS |
| Bipartite Graph | Two-color traversal |
| Directed cycle, Eventual Safe States | DFS state or Kahn's algorithm |
| Course Schedule, Alien Dictionary | Topological sort |
| Word Ladder I | Implicit-graph BFS |
| Word Ladder II | BFS distances + shortest-path backtracking |
| Unit-weight shortest path, Binary Maze | BFS distance |
| Shortest Path in DAG | Topological relaxation |
| Dijkstra, Network Delay, Print Shortest Path | Min-heap Dijkstra |
| Path With Minimum Effort, Swim in Rising Water | Minimax Dijkstra |
| Cheapest Flights Within K Stops, Minimum Multiplications | Expanded-state shortest path |
| Number of Ways to Arrive | Dijkstra + ways |
| Bellman-Ford | Repeated edge relaxation |
| Find the City | Floyd-Warshall |
| Network Connected, Accounts Merge, Islands II, Large Island, Stones | DSU |
| Prim, Kruskal | Minimum spanning tree |
| Tarjan strongly connected components | Discovery/low-link + active stack |
| Critical Connections in a Network | Tarjan bridges in an undirected graph |

---

## 1. Adjacency List, DFS and Components

### Recognition clue

The input is an edge list, and the task asks for reachability, traversal or the
number of disconnected groups.

### Invariant

Once `visited[node]` is set, that node is processed only once. One traversal
from an unvisited start visits exactly one connected component.

### Skeleton code

```cpp
vector<vector<int>> buildUndirectedGraph(
    int vertices,
    const vector<pair<int, int>>& edges
) {
    vector<vector<int>> adj(vertices);

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

void dfs(int node, const vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countComponents(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> visited(n, 0);
    int components = 0;

    for (int node = 0; node < n; node++) {
        if (!visited[node]) {
            components++;
            dfs(node, adj, visited);
        }
    }
    return components;
}
```

### Complexity

`O(V + E)` time and `O(V)` auxiliary space, including the recursion stack.

### Common bugs

- Adding only one direction for an undirected edge.
- Starting only from node `0` when the graph may be disconnected.
- Passing the adjacency list or `visited` by value.
- Stack overflow on a very deep graph; use iterative DFS when constraints are large.

### Representative problems

Number of Provinces, Connected Components, Number of Islands.

---

## 2. BFS Traversal and Unweighted Distance

### Recognition clue

Every edge has equal cost, or the problem asks for the minimum number of moves,
transformations or edges.

### Invariant

The first time BFS reaches a node, it has used the minimum number of edges from
the source. Mark a node when enqueuing it so it is not inserted repeatedly.

### Skeleton code

```cpp
vector<int> unweightedShortestPath(
    int source,
    const vector<vector<int>>& adj
) {
    int n = adj.size();
    vector<int> distance(n, -1);
    queue<int> pending;

    distance[source] = 0;
    pending.push(source);

    while (!pending.empty()) {
        int node = pending.front();
        pending.pop();

        for (int neighbor : adj[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                pending.push(neighbor);
            }
        }
    }
    return distance;
}
```

### Complexity

`O(V + E)` time and `O(V)` space.

### Common bugs

- Using DFS when a minimum number of unweighted edges is required.
- Marking visited after popping instead of when pushing.
- Accidentally treating a directed edge as undirected.

### Representative problems

Shortest Path in an Undirected Graph with Unit Weights, Message Route.

---

## 3. Grid DFS/BFS

### Recognition clue

Grid cells are vertices and valid neighboring cells form edges. The task asks
for regions, reachability, recoloring, boundary-connected cells or islands.

### Invariant

Each valid cell is visited once. The direction arrays define the graph: four
directions and eight directions are different problems.

### Skeleton code

```cpp
const int DR[4] = {-1, 0, 1, 0};
const int DC[4] = {0, 1, 0, -1};

bool inside(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

void gridDfs(
    int row,
    int col,
    const vector<vector<int>>& grid,
    vector<vector<int>>& visited
) {
    visited[row][col] = 1;

    for (int direction = 0; direction < 4; direction++) {
        int nextRow = row + DR[direction];
        int nextCol = col + DC[direction];

        if (inside(nextRow, nextCol, grid.size(), grid[0].size()) &&
            !visited[nextRow][nextCol] && grid[nextRow][nextCol] == 1) {
            gridDfs(nextRow, nextCol, grid, visited);
        }
    }
}
```

### Complexity

`O(rows * cols)` time and space in the worst case.

### Common bugs

- Checking `grid[nextRow][nextCol]` before checking bounds.
- Using four directions for an eight-direction problem or vice versa.
- Mutating the grid when later logic still needs the original values.

### Representative problems

Flood Fill, Number of Islands, Number of Enclaves, Surrounded Regions.

---

## 4. Multi-Source BFS

### Recognition clue

Several starting cells spread simultaneously, or every cell needs its distance
to the nearest source.

### Invariant

All sources enter the queue with distance zero. BFS then processes the entire
distance-`d` frontier before distance `d + 1`, so each cell receives its nearest
source distance.

### Skeleton code

```cpp
vector<vector<int>> nearestSource(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    queue<pair<int, int>> pending;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 1) {
                distance[row][col] = 0;
                pending.push({row, col});
            }
        }
    }

    while (!pending.empty()) {
        auto [row, col] = pending.front();
        pending.pop();

        for (int direction = 0; direction < 4; direction++) {
            int nextRow = row + DR[direction];
            int nextCol = col + DC[direction];

            if (inside(nextRow, nextCol, rows, cols) &&
                distance[nextRow][nextCol] == -1) {
                distance[nextRow][nextCol] = distance[row][col] + 1;
                pending.push({nextRow, nextCol});
            }
        }
    }
    return distance;
}
```

### Complexity

`O(rows * cols)` time and space.

### Common bugs

- Running a separate BFS from every cell.
- Forgetting to enqueue every source before BFS begins.
- Mixing the values that represent a source and a traversable cell.

### Representative problems

Rotten Oranges, Distance of Nearest Cell Having One, 01 Matrix.

---

## 5. Distinct Island Shapes

### Recognition clue

Connected components must be compared by shape while ignoring their absolute
positions.

### Invariant

Represent every cell relative to the component's first cell. Translated copies
then produce the same sequence when DFS uses one fixed direction order.

### Skeleton code

```cpp
void recordShape(
    int row,
    int col,
    int baseRow,
    int baseCol,
    const vector<vector<int>>& grid,
    vector<vector<int>>& visited,
    vector<pair<int, int>>& shape
) {
    visited[row][col] = 1;
    shape.push_back({row - baseRow, col - baseCol});

    for (int direction = 0; direction < 4; direction++) {
        int nextRow = row + DR[direction];
        int nextCol = col + DC[direction];

        if (inside(nextRow, nextCol, grid.size(), grid[0].size()) &&
            !visited[nextRow][nextCol] && grid[nextRow][nextCol] == 1) {
            recordShape(nextRow, nextCol, baseRow, baseCol,
                        grid, visited, shape);
        }
    }
}

int countDistinctIslands(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    set<vector<pair<int, int>>> shapes;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 1 && !visited[row][col]) {
                vector<pair<int, int>> shape;
                recordShape(row, col, row, col, grid, visited, shape);
                shapes.insert(shape);
            }
        }
    }
    return shapes.size();
}
```

### Complexity

`O(rows * cols * log S)` with an ordered set, where `S` is the number of
different stored shapes. Grid traversal itself is linear.

### Common bugs

- Recording absolute coordinates.
- Changing DFS direction order between components.
- Assuming rotations and reflections are equal when the problem only ignores translation.

### Representative problems

Number of Distinct Islands.

---

## 6. Cycle Detection in an Undirected Graph

### Recognition clue

The graph is undirected and the task asks whether any component contains a cycle.

### Invariant

While exploring from `node`, a visited neighbor is a cycle only when it is not
the edge back to `parent`.

### Skeleton code

```cpp
bool hasCycleFrom(
    int start,
    const vector<vector<int>>& adj,
    vector<int>& visited
) {
    queue<pair<int, int>> pending;
    pending.push({start, -1});
    visited[start] = 1;

    while (!pending.empty()) {
        auto [node, parent] = pending.front();
        pending.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                pending.push({neighbor, node});
            } else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}
```

### Complexity

`O(V + E)` time and `O(V)` space.

### Common bugs

- Treating the parent edge as a cycle.
- Checking only the component containing node `0`.
- Reusing this logic for a directed graph.

### Representative problems

Detect Cycle in an Undirected Graph, Round Trip.

---

## 7. Bipartite Graph

### Recognition clue

Vertices must be divided into two groups so every edge joins different groups.

### Invariant

Every traversed edge must connect opposite colors. An edge joining equal colors
proves that the component contains an odd cycle.

### Skeleton code

```cpp
bool isBipartite(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for (int start = 0; start < n; start++) {
        if (color[start] != -1) continue;

        queue<int> pending;
        color[start] = 0;
        pending.push(start);

        while (!pending.empty()) {
            int node = pending.front();
            pending.pop();

            for (int neighbor : adj[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    pending.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}
```

### Complexity

`O(V + E)` time and `O(V)` space.

### Common bugs

- Using a boolean color without a separate uncolored state.
- Starting from only one component.

### Representative problems

Bipartite Graph, Building Teams.

---

## 8. Directed Cycle Detection with DFS State

### Recognition clue

The graph is directed and the question asks about cycles, prerequisite validity
or eventual safety.

### Invariant

State `1` means the node is on the current recursive path. Reaching another
state-`1` node is a back edge and therefore a directed cycle. State `2` means
the node is fully processed and safe from the current search.

### Skeleton code

```cpp
bool directedCycleDfs(
    int node,
    const vector<vector<int>>& adj,
    vector<int>& state
) {
    state[node] = 1;

    for (int neighbor : adj[node]) {
        if (state[neighbor] == 0) {
            if (directedCycleDfs(neighbor, adj, state)) return true;
        } else if (state[neighbor] == 1) {
            return true;
        }
    }

    state[node] = 2;
    return false;
}
```

### Complexity

`O(V + E)` time and `O(V)` space.

### Common bugs

- Using undirected parent logic on a directed graph.
- Forgetting to change the state to `2` while backtracking.
- Treating an edge to a fully processed node as a cycle.

### Representative problems

Directed Cycle Detection, Eventual Safe States, Course Schedule.

---

## 9. Topological Sort: DFS and Kahn

### Recognition clue

There are prerequisites or dependencies, and every edge `u -> v` requires `u`
before `v`. A valid ordering exists only for a DAG.

### Invariant

- **DFS:** append a node only after all outgoing neighbors are processed.
- **Kahn:** the queue contains exactly the currently available zero-indegree nodes.

### Skeleton code

```cpp
vector<int> kahnTopologicalSort(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);

    for (int node = 0; node < n; node++) {
        for (int neighbor : adj[node]) indegree[neighbor]++;
    }

    queue<int> available;
    for (int node = 0; node < n; node++) {
        if (indegree[node] == 0) available.push(node);
    }

    vector<int> order;
    while (!available.empty()) {
        int node = available.front();
        available.pop();
        order.push_back(node);

        for (int neighbor : adj[node]) {
            if (--indegree[neighbor] == 0) available.push(neighbor);
        }
    }

    if ((int)order.size() != n) return {};
    return order;
}

void topoDfs(
    int node,
    const vector<vector<int>>& adj,
    vector<int>& visited,
    vector<int>& order
) {
    visited[node] = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) topoDfs(neighbor, adj, visited, order);
    }
    order.push_back(node);
}
```

Reverse the DFS `order` after all components are processed. If the input may
contain a cycle, combine DFS topological sorting with the three-state cycle
check from the previous template.

### Complexity

`O(V + E)` time and `O(V)` space.

### Common bugs

- Reversing the direction of prerequisite edges.
- Returning a partial Kahn order when its size is less than `V`.
- Omitting isolated vertices from the initial zero-indegree queue.
- In Alien Dictionary, forgetting the invalid-prefix case such as `"abcd"` before `"ab"`.

### Representative problems

Topological Sort, Course Schedule I/II, Alien Dictionary, Eventual Safe States.

---

## 10. Word Ladder I: BFS on an Implicit Graph

### Recognition clue

States are words; one valid character change creates an edge. The task asks for
the minimum number of transformations.

### Invariant

Words removed from the dictionary are visited. BFS layers equal transformation
counts, so the first arrival at `endWord` is shortest.

### Skeleton code

```cpp
int ladderLength(
    string beginWord,
    const string& endWord,
    vector<string>& wordList
) {
    unordered_set<string> unused(wordList.begin(), wordList.end());
    if (!unused.count(endWord)) return 0;

    queue<pair<string, int>> pending;
    pending.push({beginWord, 1});
    unused.erase(beginWord);

    while (!pending.empty()) {
        auto [word, steps] = pending.front();
        pending.pop();

        if (word == endWord) return steps;

        for (int index = 0; index < (int)word.size(); index++) {
            char original = word[index];
            for (char replacement = 'a'; replacement <= 'z'; replacement++) {
                word[index] = replacement;
                if (unused.erase(word)) {
                    pending.push({word, steps + 1});
                }
            }
            word[index] = original;
        }
    }
    return 0;
}
```

### Complexity

For `N` words of length `L`, approximately `O(N * L * 26)` neighbor work,
plus hashing costs.

### Common bugs

- Not restoring the original character after trying replacements.
- Keeping visited words in the dictionary and enqueuing them repeatedly.
- Returning edges when the platform expects the number of words in the sequence.

### Representative problems

Word Ladder I.

---

## 11. Word Ladder II: BFS Distances + Backtracking

### Recognition clue

Return every shortest transformation sequence, not merely the shortest length.

### Invariant

BFS assigns each reachable word its minimum level. During reconstruction, a
valid predecessor of a word at level `d` must exist at level `d - 1`.

### Skeleton code

```cpp
void buildLadders(
    string word,
    const string& beginWord,
    unordered_map<string, int>& distance,
    vector<string>& path,
    vector<vector<string>>& answer
) {
    if (word == beginWord) {
        reverse(path.begin(), path.end());
        answer.push_back(path);
        reverse(path.begin(), path.end());
        return;
    }

    int currentDistance = distance[word];

    for (int index = 0; index < (int)word.size(); index++) {
        char original = word[index];
        for (char replacement = 'a'; replacement <= 'z'; replacement++) {
            word[index] = replacement;
            auto it = distance.find(word);

            if (it != distance.end() && it->second == currentDistance - 1) {
                path.push_back(word);
                buildLadders(word, beginWord, distance, path, answer);
                path.pop_back();
            }
        }
        word[index] = original;
    }
}
```

The first phase is Word Ladder I BFS, except it stores
`distance[word] = distance[parent] + 1`. Start reconstruction with
`path = {endWord}` only if BFS reached `endWord`.

### Complexity

BFS is approximately `O(N * L * 26)`. Output reconstruction is proportional
to the total size of all returned shortest sequences and may be exponential.

### Common bugs

- Performing ordinary DFS without BFS levels, which explores non-shortest paths.
- Forgetting to restore both the changed character and the backtracking path.
- Stopping BFS before all information required for shortest-path reconstruction exists.

### Representative problems

Word Ladder II.

---

## 12. Shortest Path in a Binary Maze

### Recognition clue

Each legal grid move costs one, and the answer is the minimum moves between two
cells. This is the grid form of unweighted BFS.

### Invariant

When a cell is first enqueued, its distance is minimum. The movement arrays
must match the statement: four-direction and eight-direction variants differ.

### Skeleton code

```cpp
int shortestBinaryMaze(
    const vector<vector<int>>& grid,
    pair<int, int> source,
    pair<int, int> destination
) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    queue<pair<int, int>> pending;

    auto [sourceRow, sourceCol] = source;
    distance[sourceRow][sourceCol] = 0;
    pending.push(source);

    while (!pending.empty()) {
        auto [row, col] = pending.front();
        pending.pop();

        if (make_pair(row, col) == destination) return distance[row][col];

        for (int direction = 0; direction < 4; direction++) {
            int nextRow = row + DR[direction];
            int nextCol = col + DC[direction];

            if (inside(nextRow, nextCol, rows, cols) &&
                grid[nextRow][nextCol] == 1 &&
                distance[nextRow][nextCol] == -1) {
                distance[nextRow][nextCol] = distance[row][col] + 1;
                pending.push({nextRow, nextCol});
            }
        }
    }
    return -1;
}
```

### Complexity

`O(rows * cols)` time and space.

### Common bugs

- Using the wrong value for open cells.
- Forgetting to reject a blocked source or destination.
- Copying eight directions into a four-direction problem.

### Representative problems

Shortest Distance in a Binary Maze, Shortest Path in Binary Matrix.

---

## 13. Shortest or Longest Path in a DAG

### Recognition clue

The graph is a DAG and the problem asks for an optimal or counted path. Edge
weights may even be negative because topological order prevents revisiting.

### Invariant

When a node is processed in topological order, every predecessor has already
contributed to it. Each outgoing edge can therefore be relaxed once.

### Skeleton code

```cpp
vector<long long> dagShortestPath(
    int source,
    const vector<vector<pair<int, int>>>& adj,
    const vector<int>& topologicalOrder
) {
    const long long INF = 4e18;
    vector<long long> distance(adj.size(), INF);
    distance[source] = 0;

    for (int node : topologicalOrder) {
        if (distance[node] == INF) continue;

        for (auto [neighbor, weight] : adj[node]) {
            distance[neighbor] = min(
                distance[neighbor],
                distance[node] + weight
            );
        }
    }
    return distance;
}
```

For a longest path, initialize unreachable states to negative infinity and use
`max`. Save `parent[neighbor] = node` when an improvement occurs if the path
must be reconstructed. For path counting, replace relaxation with modular
addition to outgoing neighbors.

### Complexity

`O(V + E)` time and `O(V)` additional space after building the graph.

### Common bugs

- Relaxing outward from an unreachable node.
- Using Dijkstra merely because the word "shortest" appears.
- Applying this template when the graph can contain a cycle.

### Representative problems

Shortest Path in DAG, Longest Flight Route, Game Routes.

---

## 14. Dijkstra with a Min-Heap

### Recognition clue

Single-source shortest path in a weighted graph where every edge weight is
non-negative.

### Invariant

The heap orders candidate states by distance. When `(distance, node)` is popped,
skip it if it is stale. Every successful relaxation inserts a fresh candidate.

### Skeleton code

```cpp
vector<long long> dijkstra(
    int source,
    const vector<vector<pair<int, int>>>& adj
) {
    const long long INF = 4e18;
    vector<long long> distance(adj.size(), INF);

    using State = pair<long long, int>;
    priority_queue<State, vector<State>, greater<State>> pending;

    distance[source] = 0;
    pending.push({0, source});

    while (!pending.empty()) {
        auto [currentDistance, node] = pending.top();
        pending.pop();

        if (currentDistance != distance[node]) continue;

        for (auto [neighbor, weight] : adj[node]) {
            long long candidate = currentDistance + weight;
            if (candidate < distance[neighbor]) {
                distance[neighbor] = candidate;
                pending.push({candidate, neighbor});
            }
        }
    }
    return distance;
}
```

For path reconstruction, initialize `parent[node] = node`, assign
`parent[neighbor] = node` on strict improvement, and follow parents backward
from the destination.

For Network Delay Time, run Dijkstra from `k`; if any node remains unreachable,
return `-1`, otherwise return the maximum distance.

### Complexity

`O((V + E) log V)` time and `O(V + E)` graph/heap space.

### Common bugs

- Using Dijkstra with a negative edge.
- Creating a max-heap accidentally.
- Forgetting the stale-entry check.
- Using `int` when path sums can overflow.
- Adding both directions when the graph is directed.

### Representative problems

Dijkstra's Algorithm, Network Delay Time, Print Shortest Path, Shortest Routes I.

---

## 15. Minimax Dijkstra

### Recognition clue

The path cost is the maximum edge difference or maximum cell value encountered,
and the objective is to minimize that maximum.

### Invariant

`best[state]` is the smallest possible bottleneck found so far. Extending a path
uses `max(currentCost, newEdgeCost)` instead of addition. The smallest popped
non-stale destination cost is optimal.

### Skeleton code

```cpp
int minimumEffortPath(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    const int INF = 1e9;

    vector<vector<int>> best(rows, vector<int>(cols, INF));
    using State = tuple<int, int, int>; // cost, row, col
    priority_queue<State, vector<State>, greater<State>> pending;

    best[0][0] = 0;
    pending.push({0, 0, 0});

    while (!pending.empty()) {
        auto [cost, row, col] = pending.top();
        pending.pop();

        if (cost != best[row][col]) continue;
        if (row == rows - 1 && col == cols - 1) return cost;

        for (int direction = 0; direction < 4; direction++) {
            int nextRow = row + DR[direction];
            int nextCol = col + DC[direction];
            if (!inside(nextRow, nextCol, rows, cols)) continue;

            int edgeCost = abs(grid[row][col] - grid[nextRow][nextCol]);
            int candidate = max(cost, edgeCost);

            if (candidate < best[nextRow][nextCol]) {
                best[nextRow][nextCol] = candidate;
                pending.push({candidate, nextRow, nextCol});
            }
        }
    }
    return -1;
}
```

For **Swim in Rising Water**, the candidate is
`max(cost, grid[nextRow][nextCol])`, and the initial cost is `grid[0][0]`.

### Complexity

`O(rows * cols * log(rows * cols))` time and `O(rows * cols)` space.

### Common bugs

- Adding edge costs instead of taking their maximum.
- Marking a cell permanently visited when it is pushed under a formulation
  that may later improve it; the distance-array/stale-entry form is safer.
- Starting Swim in Rising Water with cost zero instead of the first elevation.

### Representative problems

Path With Minimum Effort, Swim in Rising Water.

---

## 16. Expanded-State Shortest Path

### Recognition clue

Reaching the same node with a different number of stops, operations or another
resource can change future possibilities. A node alone is not the full state.

### Invariant

The frontier stores every dimension that affects legal future transitions.
Prune only when the new state is dominated under all relevant dimensions.

### Skeleton code: bounded number of edges

```cpp
int cheapestWithAtMostKEdges(
    int n,
    const vector<vector<pair<int, int>>>& adj,
    int source,
    int destination,
    int maxEdges
) {
    const int INF = 1e9;
    vector<vector<int>> best(maxEdges + 1, vector<int>(n, INF));
    queue<pair<int, int>> pending; // node, edges used

    best[0][source] = 0;
    pending.push({source, 0});

    while (!pending.empty()) {
        auto [node, edgesUsed] = pending.front();
        pending.pop();

        if (edgesUsed == maxEdges) continue;

        for (auto [neighbor, price] : adj[node]) {
            int candidate = best[edgesUsed][node] + price;
            if (candidate < best[edgesUsed + 1][neighbor]) {
                best[edgesUsed + 1][neighbor] = candidate;
                pending.push({neighbor, edgesUsed + 1});
            }
        }
    }

    int answer = INF;
    for (int edges = 0; edges <= maxEdges; edges++) {
        answer = min(answer, best[edges][destination]);
    }
    return answer == INF ? -1 : answer;
}
```

For `k` intermediate stops, at most `k + 1` edges are allowed. Minimum
Multiplications uses the current number modulo `100000` as a node and BFS for
the minimum operations.

### Complexity

For the bounded-edge form, `O(K * E)` time and `O(K * V)` space.

### Common bugs

- Storing only `best[node]` when a more expensive arrival with fewer stops can
  still produce the final optimum.
- Confusing stops with edges.
- Omitting modulo reduction in Minimum Multiplications.

### Representative problems

Cheapest Flights Within K Stops, Minimum Multiplications to Reach End.

---

## 17. Count the Number of Shortest Paths

### Recognition clue

The graph has non-negative weights and asks both the minimum distance and how
many minimum-distance routes reach the destination.

### Invariant

`ways[node]` counts only paths whose length equals `distance[node]`. A strictly
better route replaces both distance and count; an equal route adds its count.

### Skeleton code

```cpp
int countShortestPaths(
    int source,
    int destination,
    const vector<vector<pair<int, int>>>& adj
) {
    const long long INF = 4e18;
    const int MOD = 1000000007;
    int n = adj.size();

    vector<long long> distance(n, INF);
    vector<int> ways(n, 0);
    using State = pair<long long, int>;
    priority_queue<State, vector<State>, greater<State>> pending;

    distance[source] = 0;
    ways[source] = 1;
    pending.push({0, source});

    while (!pending.empty()) {
        auto [currentDistance, node] = pending.top();
        pending.pop();
        if (currentDistance != distance[node]) continue;

        for (auto [neighbor, weight] : adj[node]) {
            long long candidate = currentDistance + weight;

            if (candidate < distance[neighbor]) {
                distance[neighbor] = candidate;
                ways[neighbor] = ways[node];
                pending.push({candidate, neighbor});
            } else if (candidate == distance[neighbor]) {
                ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
            }
        }
    }
    return ways[destination];
}
```

### Complexity

`O((V + E) log V)` time and `O(V + E)` space.

### Common bugs

- Adding ways after finding a strictly shorter path instead of replacing them.
- Forgetting modulo on the equal-distance case.
- Using `int` for distances.

### Representative problems

Number of Ways to Arrive at Destination.

---

## 18. Bellman-Ford

### Recognition clue

Single-source shortest paths may include negative edge weights, or the task asks
whether a negative-weight cycle is reachable from the source.

### Invariant

After the `i`th complete pass, shortest paths using at most `i` edges are known.
A simple shortest path has at most `V - 1` edges. Any improvement on one more
pass proves a reachable negative cycle.

### Skeleton code

```cpp
vector<long long> bellmanFord(
    int vertices,
    const vector<array<int, 3>>& edges,
    int source
) {
    const long long INF = 4e18;
    vector<long long> distance(vertices, INF);
    distance[source] = 0;

    for (int pass = 1; pass <= vertices - 1; pass++) {
        bool changed = false;

        for (auto [from, to, weight] : edges) {
            if (distance[from] == INF) continue;

            if (distance[from] + weight < distance[to]) {
                distance[to] = distance[from] + weight;
                changed = true;
            }
        }

        if (!changed) break;
    }

    for (auto [from, to, weight] : edges) {
        if (distance[from] != INF &&
            distance[from] + weight < distance[to]) {
            return {}; // reachable negative cycle
        }
    }
    return distance;
}
```

### Complexity

`O(V * E)` time and `O(V)` space.

### Common bugs

- Relaxing outward from an unreachable node and overflowing infinity.
- Running `V` ordinary passes before the separate cycle check.
- Claiming any negative cycle exists when it is not reachable from the chosen source.
- Forgetting both directed entries if the original edge is undirected.

### Representative problems

Bellman-Ford Algorithm, Cycle Finding.

---

## 19. Floyd-Warshall

### Recognition clue

The task needs shortest distances between every pair of vertices and `V` is
small enough for cubic time.

### Invariant

After processing intermediate vertex `k`, `distance[i][j]` is the best route
from `i` to `j` whose intermediate vertices come only from `0..k`.

### Skeleton code

```cpp
void floydWarshall(vector<vector<long long>>& distance) {
    int n = distance.size();
    const long long INF = 4e18;

    for (int node = 0; node < n; node++) distance[node][node] = 0;

    for (int middle = 0; middle < n; middle++) {
        for (int from = 0; from < n; from++) {
            for (int to = 0; to < n; to++) {
                if (distance[from][middle] == INF ||
                    distance[middle][to] == INF) continue;

                distance[from][to] = min(
                    distance[from][to],
                    distance[from][middle] + distance[middle][to]
                );
            }
        }
    }
}
```

Afterward, `distance[node][node] < 0` indicates a negative cycle involving that
node.

### Complexity

`O(V^3)` time and `O(V^2)` space.

### Common bugs

- Putting the `middle` loop inside either endpoint loop.
- Adding infinity values.
- Overwriting parallel edges instead of keeping their minimum weight.

### Representative problems

Floyd-Warshall Algorithm, Find the City with the Smallest Number of Neighbors.

---

## 20. Disjoint Set Union

### Recognition clue

Edges or cells are added while the task repeatedly asks whether two items are
already connected, how many components remain, or what each component's size is.

### Invariant

Every component has one representative root. Path compression shortens find
paths; union by size attaches the smaller tree below the larger one.

### Skeleton code

```cpp
class DisjointSet {
    vector<int> parent;
    vector<int> componentSize;

public:
    explicit DisjointSet(int n) : parent(n), componentSize(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    bool unite(int first, int second) {
        first = find(first);
        second = find(second);

        if (first == second) return false;
        if (componentSize[first] < componentSize[second]) swap(first, second);

        parent[second] = first;
        componentSize[first] += componentSize[second];
        return true;
    }

    int size(int node) {
        return componentSize[find(node)];
    }
};
```

### Complexity

Amortized `O(alpha(V))` per operation, effectively constant for interview constraints.

### Common bugs

- Comparing immediate parents instead of ultimate parents.
- Updating the size of the child root instead of the new root.
- Mixing zero-indexed and one-indexed initialization.
- Counting inactive grid cells as DSU components.

### Representative problems

Operations to Make Network Connected, Accounts Merge, Number of Islands II,
Making a Large Island, Most Stones Removed.

---

## 21. Minimum Spanning Tree: Kruskal and Prim

### Recognition clue

Connect all vertices with minimum total edge weight. The answer is a tree with
exactly `V - 1` edges when the graph is connected.

### Invariant

- **Kruskal:** process edges from lightest to heaviest and accept an edge only
  when it joins two different DSU components.
- **Prim:** the heap contains edges crossing from the visited tree to unvisited
  vertices; accept the cheapest edge reaching a new vertex.

### Skeleton code: Kruskal

```cpp
long long kruskalMst(int vertices, vector<array<int, 3>> edges) {
    sort(edges.begin(), edges.end(), [](const auto& first, const auto& second) {
        return first[2] < second[2];
    });

    DisjointSet dsu(vertices);
    long long totalWeight = 0;
    int acceptedEdges = 0;

    for (auto [from, to, weight] : edges) {
        if (dsu.unite(from, to)) {
            totalWeight += weight;
            acceptedEdges++;
        }
    }

    return acceptedEdges == vertices - 1 ? totalWeight : -1;
}
```

### Skeleton code: Prim

```cpp
long long primMst(const vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> inTree(n, 0);
    using State = pair<int, int>; // edge weight, node
    priority_queue<State, vector<State>, greater<State>> pending;

    pending.push({0, 0});
    long long totalWeight = 0;
    int visitedCount = 0;

    while (!pending.empty()) {
        auto [weight, node] = pending.top();
        pending.pop();

        if (inTree[node]) continue;
        inTree[node] = 1;
        visitedCount++;
        totalWeight += weight;

        for (auto [neighbor, edgeWeight] : adj[node]) {
            if (!inTree[neighbor]) pending.push({edgeWeight, neighbor});
        }
    }

    return visitedCount == n ? totalWeight : -1;
}
```

### Complexity

Kruskal is `O(E log E)`. Prim with a heap is `O(E log V)`.

### Common bugs

- Returning a partial forest without checking connectivity.
- Summing an edge before confirming that it joins a new component.
- Confusing an MST with a shortest-path tree.

### Representative problems

Prim's Algorithm, Kruskal's Algorithm, Road Reparation.

---

## 22. Tarjan's Strongly Connected Components

### Recognition clue

The graph is directed and the task asks for maximal groups where every vertex
can reach every other vertex.

### Invariant

`discovery[node]` is when DFS first sees the node. `low[node]` is the earliest
active DFS vertex reachable from its subtree. Only edges to vertices still on
the stack may lower `low` through `discovery[neighbor]`. When
`low[node] == discovery[node]`, `node` is the root of one complete SCC.

### Skeleton code

```cpp
class TarjanScc {
    int timer = 0;
    vector<int> discovery;
    vector<int> low;
    vector<int> onStack;
    stack<int> active;
    vector<vector<int>> components;

    void dfs(int node, const vector<vector<int>>& adj) {
        discovery[node] = low[node] = timer++;
        active.push(node);
        onStack[node] = 1;

        for (int neighbor : adj[node]) {
            if (discovery[neighbor] == -1) {
                dfs(neighbor, adj);
                low[node] = min(low[node], low[neighbor]);
            } else if (onStack[neighbor]) {
                low[node] = min(low[node], discovery[neighbor]);
            }
        }

        if (low[node] == discovery[node]) {
            vector<int> component;
            while (true) {
                int current = active.top();
                active.pop();
                onStack[current] = 0;
                component.push_back(current);
                if (current == node) break;
            }
            components.push_back(component);
        }
    }

public:
    vector<vector<int>> findComponents(const vector<vector<int>>& adj) {
        int n = adj.size();
        timer = 0;
        discovery.assign(n, -1);
        low.assign(n, -1);
        onStack.assign(n, 0);
        components.clear();
        active = stack<int>();

        for (int node = 0; node < n; node++) {
            if (discovery[node] == -1) dfs(node, adj);
        }
        return components;
    }
};
```

### Complexity

`O(V + E)` time and `O(V)` auxiliary space.

### Common bugs

- Updating from an edge to a vertex that has already left the active stack.
- Using `low[neighbor]` instead of `discovery[neighbor]` for an active back edge.
- Popping only the SCC root instead of every vertex through the root.
- Confusing Tarjan SCC with Tarjan bridges: SCC uses an active stack; bridges do not.

### Representative problems

Tarjan Strongly Connected Components, strongly connected component counting.

---

## 23. Tarjan Bridges in an Undirected Graph

### Recognition clue

The graph is undirected and the task asks which edges disconnect the graph when
removed.

### Invariant

`low[node]` is the earliest discovery time reachable from the DFS subtree of
`node` without using its entering edge. After a child returns, the tree edge
`node-child` is a bridge exactly when the child's subtree cannot reach `node`
or an ancestor:

```cpp
low[child] > tin[node]
```

### Skeleton code

```cpp
void bridgeDfs(
    int node,
    int parentEdge,
    const vector<vector<pair<int, int>>>& adj,
    vector<int>& tin,
    vector<int>& low,
    int& timer,
    vector<pair<int, int>>& bridges
) {
    tin[node] = low[node] = timer++;

    for (auto [neighbor, edgeId] : adj[node]) {
        if (edgeId == parentEdge) continue;

        if (tin[neighbor] == -1) {
            bridgeDfs(neighbor, edgeId, adj, tin, low, timer, bridges);
            low[node] = min(low[node], low[neighbor]);

            if (low[neighbor] > tin[node]) {
                bridges.push_back({node, neighbor});
            }
        } else {
            low[node] = min(low[node], tin[neighbor]);
        }
    }
}
```

Use an edge ID as `parentEdge` so only the exact entering edge is ignored. This
also handles parallel edges correctly.

### Complexity

`O(V + E)` time and `O(V + E)` space including the graph and recursion stack.

### Common bugs

- Running the bridge condition on an already visited neighbor instead of only
  after returning from an unvisited DFS child.
- Using `>=` instead of `>` for the bridge condition.
- Updating a back edge with `low[neighbor]` instead of `tin[neighbor]`.
- Reusing the directed-SCC `inStack` rule in this undirected algorithm.
- Ignoring every edge to the parent vertex when parallel edges may exist.

### Representative problems

Critical Connections in a Network, Bridges in Graph.

---

## What is not yet in the completed-template set

Add these after solving and testing their representative problems:

1. Articulation points.
2. Kosaraju's algorithm.

These are related to Tarjan SCC but are not interchangeable with it.

## Seven-day recall cycle

| Day | Recall set |
|---|---|
| 1 | Adjacency list, DFS/BFS, grid traversal, multi-source BFS |
| 2 | Undirected cycle, bipartite, directed cycle |
| 3 | Topological sort, Word Ladder I/II, DAG paths |
| 4 | Unweighted BFS, Dijkstra, path reconstruction |
| 5 | Minimax/state-expanded paths, shortest-path counting |
| 6 | Bellman-Ford, Floyd-Warshall |
| 7 | DSU, Prim, Kruskal, Tarjan SCC, Tarjan bridges |

For each day: write the invariant, reproduce the skeleton, and solve one mixed
problem without looking at its topic label.
