#include <vector>
#include <set> // Added the correct include for std::set

using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
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

        // 2. Initialize the distance vector with infinity
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        // 3. FIXED: Removed the lingering priority_queue line that caused name collision
        set<pair<int, int>> st; // Renamed to 'st' for clarity, keeps elements unique and sorted
        st.insert({0, src});

        // 4. Run Dijkstra exploration loop
        while (!st.empty())
        {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(st.begin()); // Erase by iterator is faster than erasing by value

            // Traverse adjacent neighbors
            for (const auto &neighbor : adj[node])
            {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                // Relaxation condition step
                if (dist[node] + edgeWeight < dist[nextNode])
                {

                    // Optimization advantage of set: remove the existing old path if it exists
                    if (dist[nextNode] != 1e9)
                    {
                        st.erase({dist[nextNode], nextNode});
                    }

                    dist[nextNode] = dist[node] + edgeWeight;
                    st.insert({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }
};
