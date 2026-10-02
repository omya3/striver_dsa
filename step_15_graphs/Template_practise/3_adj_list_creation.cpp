#include <tuple>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> buildUndirectedGraph(
    int vertices,
    const vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(vertices);

    for (auto [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

vector<vector<pair<int, int>>> buildDirectedWeightedGraph(
    int vertices,
    const vector<tuple<int, int, int>> &edges)
{
    vector<vector<pair<int, int>>> adj(vertices);

    for (auto [from, to, weight] : edges)
    {
        adj[from].push_back({to, weight});
    }
    return adj;
}
