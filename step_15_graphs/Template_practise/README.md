# Graph Template Index

This folder is the quick-recall template pack. Type a template from memory before looking at its saved version.

## Templates already present

| Pattern | File |
|---|---|
| DFS traversal | [`1_dfs_template.cpp`](1_dfs_template.cpp) |
| BFS traversal | [`2_bfs_template.cpp`](2_bfs_template.cpp) |
| Adjacency-list creation | [`3_adj_list_creation.cpp`](3_adj_list_creation.cpp) |
| Topological sort with DFS | [`4_topo_sort_using_dfs.cpp`](4_topo_sort_using_dfs.cpp) |
| Topological sort with Kahn's algorithm | [`5_topo_sort_using_kahns_algo.cpp`](5_topo_sort_using_kahns_algo.cpp) |
| Cycle detection with DFS | [`6_detect_cycle_using_dfs.cpp`](6_detect_cycle_using_dfs.cpp) |
| Dijkstra using `set` | [`7_dijkstras_using_set.cpp`](7_dijkstras_using_set.cpp) |

## Important templates still to add

Add these only after writing and testing the corresponding problem during revision:

1. Grid BFS/DFS with direction arrays
2. Undirected cycle detection with BFS
3. Directed cycle detection with DFS state and with Kahn's algorithm
4. Dijkstra using a min-heap and parent reconstruction
5. Bellman-Ford
6. Floyd-Warshall
7. Disjoint Set Union with path compression and union by size
8. Prim and Kruskal
9. Kosaraju
10. Bridges and articulation points using discovery/low time

## Recall checklist

- Is the graph directed or undirected?
- Is it weighted or unweighted?
- Are nodes zero-indexed or one-indexed?
- For an undirected edge, did you insert both directions?
- For BFS, did you mark a node visited when pushing it into the queue?
- For Dijkstra, is every edge weight non-negative?
- For disconnected graphs, did you start traversal from every unvisited node?
- Are distance sums large enough to require `long long`?
