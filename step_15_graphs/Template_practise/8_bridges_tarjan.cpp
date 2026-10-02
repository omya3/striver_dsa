#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class TarjanBridges
{
private:
    int timer = 0;
    vector<int> tin;
    vector<int> low;
    vector<pair<int, int>> bridges;

    void dfs(int node, int parentEdge,
             const vector<vector<pair<int, int>>> &adj)
    {
        tin[node] = low[node] = timer++;

        for (auto [neighbor, edgeId] : adj[node])
        {
            if (edgeId == parentEdge)
                continue;

            if (tin[neighbor] == -1)
            {
                dfs(neighbor, edgeId, adj);
                low[node] = min(low[node], low[neighbor]);

                if (low[neighbor] > tin[node])
                {
                    bridges.push_back({node, neighbor});
                }
            }
            else
            {
                low[node] = min(low[node], tin[neighbor]);
            }
        }
    }

public:
    vector<pair<int, int>> findBridges(
        int vertices,
        const vector<pair<int, int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(vertices);

        for (int edgeId = 0; edgeId < (int)edges.size(); edgeId++)
        {
            auto [u, v] = edges[edgeId];
            adj[u].push_back({v, edgeId});
            adj[v].push_back({u, edgeId});
        }

        timer = 0;
        tin.assign(vertices, -1);
        low.assign(vertices, -1);
        bridges.clear();

        for (int node = 0; node < vertices; node++)
        {
            if (tin[node] == -1)
            {
                dfs(node, -1, adj);
            }
        }

        return bridges;
    }
};
