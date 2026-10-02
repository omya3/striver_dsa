# Graph Template Index

This folder is the quick-recall template pack. Type a template from memory before looking at its saved version.

## Master template book

Use [`GRAPH_TEMPLATE_BOOK.md`](GRAPH_TEMPLATE_BOOK.md) for revision. It maps
every graph problem completed so far to a reusable pattern and keeps the
recognition clue, invariant, skeleton, complexity, bugs and representative
problems together.

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
| Tarjan bridges with edge IDs | [`8_bridges_tarjan.cpp`](8_bridges_tarjan.cpp) |

## Important templates still to add after solving

The master book now covers the completed patterns. These remain intentionally
outside the completed set until their corresponding problems are solved and tested:

1. Kosaraju's algorithm
2. Articulation points

## Recall checklist

- Is the graph directed or undirected?
- Is it weighted or unweighted?
- Are nodes zero-indexed or one-indexed?
- For an undirected edge, did you insert both directions?
- For BFS, did you mark a node visited when pushing it into the queue?
- For Dijkstra, is every edge weight non-negative?
- For disconnected graphs, did you start traversal from every unvisited node?
- Are distance sums large enough to require `long long`?
