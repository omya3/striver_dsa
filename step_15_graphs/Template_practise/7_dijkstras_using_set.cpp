#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Pass V (vertices) and edges explicitly to allow clean adjacency building
vector<int> dijkstras(int V, const vector<vector<int>> &edges, int src)
{
    // 1. Build an optimized adjacency list for an undirected graph
    vector<vector<pair<int, int>>> adj(V);
    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // 2. Initialize distances to a large value (infinity)
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // Set stores pairs of {distance, node} - sorted automatically by distance
    set<pair<int, int>> set_queue;
    set_queue.insert({0, src});

    while (!set_queue.empty())
    {
        // FIX: Using structured binding correctly on dereferenced iterator
        auto [d, node] = *set_queue.begin();
        set_queue.erase(set_queue.begin());

        // FIX: Iterating through 'adj' which contains the parsed pairs, NOT 'grid'
        for (auto &neigh : adj[node])
        {
            int neigh_node = neigh.first; // FIX: Fixed typo 'fist' -> 'first'
            int edge_weight = neigh.second;

            // Relaxation Step
            if (dist[node] + edge_weight < dist[neigh_node])
            {
                // If the neighbor was already in the set with a worse distance, remove it
                if (dist[neigh_node] != 1e9)
                {
                    set_queue.erase({dist[neigh_node], neigh_node});
                }

                // Update to the better distance and insert the fresh pair
                dist[neigh_node] = dist[node] + edge_weight;
                set_queue.insert({dist[neigh_node], neigh_node});
            }
        }
    }
    return dist;
}
