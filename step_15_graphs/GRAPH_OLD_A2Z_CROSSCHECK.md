# Graphs — Legacy Striver A2Z Cross-check

Source checked: <https://codolio.com/question-tracker/sheet/strivers-a2z-dsa-sheet>

Checked against the local `step_15_graphs` solutions on **21 September 2026**.

## Result

The Codolio legacy graph section contains **54 rows**:

- **43 covered locally or conceptually**
- **9 coding problems still pending**
- **1 algorithm to write once as a standalone solution**
- **1 Java-only representation row, which can be skipped for C++ preparation**

## Pending coding problems

Solve these nine problems:

1. **Word Ladder II**
2. **Number of Distinct Islands**
3. **Shortest Path in a Binary Maze**
   - The existing [`5_shortest_path_bin_matrix.cpp`](step_4_shortest_path_algos_and_problems/5_shortest_path_bin_matrix.cpp) is the LeetCode-style eight-direction variant.
   - The legacy sheet problem uses a supplied source and destination with four-direction movement, so it should be solved separately.
4. **Network Delay Time**
5. **Bellman-Ford Algorithm**
6. **Swim in Rising Water**
7. **Bridges in Graph**
8. **Articulation Point**
9. **Kosaraju's Algorithm**

## Covered, but create a standalone recall file

- **Floyd-Warshall Algorithm** — the algorithm is already used inside [`11_find_city_with_smallest_no_of_neighbours.cpp`](step_4_shortest_path_algos_and_problems/11_find_city_with_smallest_no_of_neighbours.cpp), but there is no dedicated Floyd-Warshall file.

This is not a new unsolved concept. Write the standalone template from memory during shortest-path revision.

## Legacy rows that are already covered

### Learning

- Graph representation in C++
- Connected-components logic
- BFS
- DFS

`Graph Representation | Java` is irrelevant to the C++ track. `Graph and Types` is a theory-revision row, not a missing coding problem.

### BFS/DFS problems

- Number of Provinces
- Connected Components Problem in Matrix / Number of Islands
- Rotten Oranges
- Flood Fill
- Undirected cycle detection using BFS
- Undirected cycle detection using DFS
- 0/1 Matrix
- Surrounded Regions
- Number of Enclaves
- Word Ladder I
- Bipartite Graph
- Directed cycle detection using DFS

### Topological sort

- Topological Sort using DFS
- Kahn's Algorithm
- Directed cycle detection using BFS/Kahn
- Course Schedule I
- Course Schedule II
- Eventual Safe States
- Alien Dictionary

### Shortest paths

- Shortest Path in an Undirected Graph with Unit Weights
- Shortest Path in a DAG
- Dijkstra using a min-heap and a set
- Why a priority queue is used in Dijkstra
- Path With Minimum Effort
- Cheapest Flights Within K Stops
- Number of Ways to Arrive at Destination
- Minimum Multiplications to Reach End
- Find the City With the Smallest Number of Neighbors

### MST and DSU

- Minimum Spanning Tree
- Prim's Algorithm
- Disjoint Set using union by rank
- Disjoint Set using union by size
- Kruskal's Algorithm
- Operations to Make Network Connected
- Most Stones Removed
- Accounts Merge
- Number of Islands II
- Making a Large Island

## Recommended pending order

1. Number of Distinct Islands
2. Shortest Path in a Binary Maze
3. Network Delay Time
4. Bellman-Ford
5. Swim in Rising Water
6. Word Ladder II
7. Kosaraju
8. Bridges
9. Articulation Point

After solving a problem, add its file link beside its name here. A problem counts as complete only after it compiles and passes the judge.
