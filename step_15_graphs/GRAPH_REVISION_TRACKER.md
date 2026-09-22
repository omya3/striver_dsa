# Striver Graph Revision Tracker

Last reconciled with the redesigned TakeUForward A2Z sheet: **21 September 2026**.

Official sheet: <https://takeuforward.org/prep-hub/strivers-a2z-dsa-sheet>

## Status legend

- `DONE` — a matching solution or the required algorithm is present locally.
- `REVIEW` — a closely related solution is present, but the current prompt differs.
- `PENDING` — no matching solution was found locally; solve this during revision.

The redesigned site reports **47 graph problems**. Its currently visible learning/practice rows contain the 44 entries below; the graph contest is not treated as a normal solved-code row here.

## Current graph syllabus versus local repository

| # | Current TakeUForward item | Status | Local evidence / note |
|---:|---|---|---|
| 1 | Introduction to Graph | DONE | [`1_rep_adj_matrix.cpp`](step_1_learning/1_rep_adj_matrix.cpp), [`2_rep_adj_list.cpp`](step_1_learning/2_rep_adj_list.cpp) |
| 2 | Traversal Techniques | DONE | [`3_bfs_traversal.cpp`](step_1_learning/3_bfs_traversal.cpp), [`4_dfs_traversal.cpp`](step_1_learning/4_dfs_traversal.cpp) |
| 3 | Connected Components | PENDING | Provinces uses the concept, but there is no dedicated current-prompt solution. |
| 4 | Number of Provinces | DONE | [`1_provinces.cpp`](step_2_problems_on_bfs_dfs/1_provinces.cpp) |
| 5 | Number of Islands | DONE | [`12_num_islands.cpp`](step_2_problems_on_bfs_dfs/12_num_islands.cpp) |
| 6 | Flood Fill Algorithm | DONE | [`4_flood_fill.cpp`](step_2_problems_on_bfs_dfs/4_flood_fill.cpp) |
| 7 | Number of Enclaves | DONE | [`9_num_enclaves.cpp`](step_2_problems_on_bfs_dfs/9_num_enclaves.cpp) |
| 8 | Rotten Oranges | DONE | [`3_rotten_oranges.cpp`](step_2_problems_on_bfs_dfs/3_rotten_oranges.cpp) |
| 9 | Distance of Nearest Cell Having One | REVIEW | [`7_dist_nearest_neigh_0.cpp`](step_2_problems_on_bfs_dfs/7_dist_nearest_neigh_0.cpp) finds nearest zero. Same multi-source BFS pattern, but reverse the source value for the current prompt. |
| 10 | Surrounded Regions | DONE | [`8_surrounded_regions.cpp`](step_2_problems_on_bfs_dfs/8_surrounded_regions.cpp) |
| 11 | Number of Distinct Islands | PENDING | No matching local solution found. |
| 12 | Detect a Cycle in an Undirected Graph | DONE | [`5_cycle_detection_bfs.cpp`](step_2_problems_on_bfs_dfs/5_cycle_detection_bfs.cpp), [`6_cycle_detection_dfs.cpp`](step_2_problems_on_bfs_dfs/6_cycle_detection_dfs.cpp) |
| 13 | Bipartite Graph | DONE | [`13_bipartite_graph.cpp`](step_2_problems_on_bfs_dfs/13_bipartite_graph.cpp) |
| 14 | Topological Sort / Kahn's Algorithm | DONE | [`1_topo_sort.cpp`](step_3_topo_sort_and_problems/1_topo_sort.cpp), [`2_topo_sort_using_kahns_algo.cpp`](step_3_topo_sort_and_problems/2_topo_sort_using_kahns_algo.cpp) |
| 15 | Detect a Cycle in a Directed Graph | DONE | [`14_detect_cycle_in_directed_graph.cpp`](step_2_problems_on_bfs_dfs/14_detect_cycle_in_directed_graph.cpp), [`15_detect_cycle_in_directed_graph_bfs.cpp`](step_2_problems_on_bfs_dfs/15_detect_cycle_in_directed_graph_bfs.cpp) |
| 16 | Find Eventual Safe States | DONE | [`5_eval_safe_states.cpp`](step_3_topo_sort_and_problems/5_eval_safe_states.cpp) |
| 17 | Course Schedule I | DONE | [`3_course_schedule_1.cpp`](step_3_topo_sort_and_problems/3_course_schedule_1.cpp) |
| 18 | Course Schedule II | DONE | [`4_course_schedule_2.cpp`](step_3_topo_sort_and_problems/4_course_schedule_2.cpp) |
| 19 | Alien Dictionary | DONE | [`6_alien_dictionary.cpp`](step_3_topo_sort_and_problems/6_alien_dictionary.cpp) |
| 20 | Shortest Path in DAG | DONE | [`2_shortest_path_in_DAG.cpp`](step_4_shortest_path_algos_and_problems/2_shortest_path_in_DAG.cpp) |
| 21 | Shortest Path in Undirected Graph with Unit Weights | DONE | [`1_shortest_path_undirected_graph.cpp`](step_4_shortest_path_algos_and_problems/1_shortest_path_undirected_graph.cpp) |
| 22 | Word Ladder I | DONE | [`10_word_ladder_1.cpp`](step_2_problems_on_bfs_dfs/10_word_ladder_1.cpp) |
| 23 | Word Ladder II | PENDING | No matching local solution found. |
| 24 | Dijkstra's Algorithm | DONE | [`3_dijkstra_with_min_heap.cpp`](step_4_shortest_path_algos_and_problems/3_dijkstra_with_min_heap.cpp), [`4_dijkstra_a_using_set.cpp`](step_4_shortest_path_algos_and_problems/4_dijkstra_a_using_set.cpp) |
| 25 | Print Shortest Path | DONE | [`4_dijkstra_print_shortest_path.cpp`](step_4_shortest_path_algos_and_problems/4_dijkstra_print_shortest_path.cpp) |
| 26 | Shortest Distance in a Binary Maze | REVIEW | [`5_shortest_path_bin_matrix.cpp`](step_4_shortest_path_algos_and_problems/5_shortest_path_bin_matrix.cpp) is the 8-direction binary-matrix variant. Re-solve the current prompt if it uses source/destination and four directions. |
| 27 | Path with Minimum Effort | DONE | [`6_path_with_min_effort.cpp`](step_4_shortest_path_algos_and_problems/6_path_with_min_effort.cpp) |
| 28 | Cheapest Flight Within K Stops | DONE | [`7_checpest_flights_within_k_stops.cpp`](step_4_shortest_path_algos_and_problems/7_checpest_flights_within_k_stops.cpp) |
| 29 | Minimum Multiplications to Reach End | DONE | [`10_min_steps_for_multiplication.cpp`](step_4_shortest_path_algos_and_problems/10_min_steps_for_multiplication.cpp) |
| 30 | Number of Ways to Arrive at Destination | DONE | [`9_no_of_ways_to_reach_dest.cpp`](step_4_shortest_path_algos_and_problems/9_no_of_ways_to_reach_dest.cpp) |
| 31 | Bellman-Ford Algorithm | PENDING | No matching local solution found. |
| 32 | Floyd-Warshall Algorithm | DONE | Floyd-Warshall is implemented inside [`11_find_city_with_smallest_no_of_neighbours.cpp`](step_4_shortest_path_algos_and_problems/11_find_city_with_smallest_no_of_neighbours.cpp); add a standalone template during revision. |
| 33 | Find the City with Smallest Number of Neighbors | DONE | [`11_find_city_with_smallest_no_of_neighbours.cpp`](step_4_shortest_path_algos_and_problems/11_find_city_with_smallest_no_of_neighbours.cpp) |
| 34 | MST Theory | DONE | Prim and Kruskal implementations exist; revise cut property and why a greedy edge is safe. |
| 35 | Disjoint Set | DONE | [`3_disjoint_set.cpp`](step_5_MST/3_disjoint_set.cpp) |
| 36 | Find the MST Weight | DONE | [`2_a_prims_algorithm.cpp`](step_5_MST/2_a_prims_algorithm.cpp), [`2_b_kruskals_algo.cpp`](step_5_MST/2_b_kruskals_algo.cpp) |
| 37 | Operations to Make Network Connected | DONE | [`5_min_no_of_ops_for_connected_graph.cpp`](step_5_MST/5_min_no_of_ops_for_connected_graph.cpp) |
| 38 | Accounts Merge | DONE | [`7_account_merge.cpp`](step_5_MST/7_account_merge.cpp) |
| 39 | Number of Islands II | DONE | [`8_num_islands_2.cpp`](step_5_MST/8_num_islands_2.cpp) |
| 40 | Making a Large Island | DONE | [`9_making_large_island.cpp`](step_5_MST/9_making_large_island.cpp) |
| 41 | Most Stones Removed with Same Row or Column | DONE | [`6_most_stones_removed.cpp`](step_5_MST/6_most_stones_removed.cpp) |
| 42 | Kosaraju's Algorithm | PENDING | No matching local solution found. |
| 43 | Bridges in Graph | PENDING | No matching local solution found. |
| 44 | Articulation Point in Graph | PENDING | No matching local solution found. |

## What remains

### Definitely pending — solve these

1. Connected Components
2. Number of Distinct Islands
3. Word Ladder II
4. Bellman-Ford Algorithm
5. Kosaraju's Algorithm
6. Bridges in Graph
7. Articulation Point in Graph

### Re-solve the current variant

1. Distance of Nearest Cell Having One
2. Shortest Distance in a Binary Maze

## Recommended revision order

Do not revise only by reading old code. For each pattern, first write the core function from memory, compile it, and then compare it with the local solution.

1. **Traversal day:** adjacency list, BFS, DFS, components, grid BFS/DFS, distinct islands.
2. **Ordering day:** directed cycle detection, topological sort, Kahn, course schedule, alien dictionary.
3. **Shortest-path day:** unit-weight BFS, DAG shortest path, Dijkstra, Bellman-Ford, Floyd-Warshall.
4. **MST/DSU day:** Prim, Kruskal, union by size/rank, path compression, DSU applications.
5. **Advanced DFS day:** Kosaraju, bridges, articulation points.

## Progress rule

Change an item to `DONE` only after the code compiles and passes the judge. Add its local file link in the same row so future website redesigns do not lose the record.
