#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int V, int m, vector<vector<int>> &edges)
    {
        // 1. Build an optimized 1-indexed adjacency list
        vector<vector<pair<int, int>>> adj(V + 1);
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // 2. Initialize distance and parent arrays
        vector<int> dist(V + 1, 1e9);
        vector<int> parent(V + 1);
        for (int i = 1; i <= V; i++)
        {
            parent[i] = i;
        }

        int src = 1; // Explicitly defined source node
        dist[src] = 0;

        set<pair<int, int>> st;
        st.insert({0, src});

        // 3. Dijkstra exploration loop
        while (!st.empty())
        {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(st.begin());

            for (const auto &neighbor : adj[node])
            {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (dist[node] + edgeWeight < dist[nextNode])
                {
                    if (dist[nextNode] != 1e9)
                    {
                        st.erase({dist[nextNode], nextNode});
                    }

                    dist[nextNode] = dist[node] + edgeWeight;
                    parent[nextNode] = node; // Record where we came from
                    st.insert({dist[nextNode], nextNode});
                }
            }
        }

        // 4. Case where destination node V is completely unreachable
        if (dist[V] == 1e9)
        {
            return {-1};
        }

        // 5. Correctly trace back the path sequence from V to 1
        vector<int> path;
        int currentNode = V;

        while (parent[currentNode] != currentNode)
        {
            path.push_back(currentNode);
            currentNode = parent[currentNode]; // Fixed: Advance node pointer
        }
        path.push_back(src); // Add the starting source node

        // 6. Flip the path so it reads from Source to Target
        reverse(path.begin(), path.end());

        // 7. Format requirement: First element must be the absolute total path weight
        vector<int> result;
        result.push_back(dist[V]);
        result.insert(result.end(), path.begin(), path.end());

        return result;
    }
};
