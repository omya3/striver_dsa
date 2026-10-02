#include <vector>

using namespace std;

// Invariant: dfs(node) visits every currently unvisited vertex reachable
// from node. Run it once from every unvisited node for a disconnected graph.
void dfs(int node, const vector<vector<int>> &adj, vector<int> &visited,
         vector<int> &order)
{
    visited[node] = 1;
    order.push_back(node);

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, order);
        }
    }
}

vector<int> dfsTraversal(const vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> order;

    for (int node = 0; node < n; node++)
    {
        if (!visited[node])
        {
            dfs(node, adj, visited, order);
        }
    }
    return order;
}
