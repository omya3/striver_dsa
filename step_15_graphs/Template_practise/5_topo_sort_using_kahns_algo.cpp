#include <iostream>
#include <vector> // FIX 1: Added missing header
#include <queue>  // FIX 1: Added missing header
using namespace std;

vector<int> topo_sort_kahn(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> indegree(n, 0);
    vector<int> toposort;
    queue<int> q;

    // 1. Calculate indegree for each node
    for (int node = 0; node < n; node++)
    {
        for (auto neigh : adj[node])
        {
            indegree[neigh]++;
        }
    }

    // 2. Push all nodes with 0 indegree into the queue
    for (int node = 0; node < n; node++)
    {
        if (indegree[node] == 0)
        {
            q.push(node); // FIX 2: Only push to queue here
        }
    }

    // 3. Process the queue
    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop();

        toposort.push_back(curr_node); // Add to sort when popped

        for (int neigh : adj[curr_node])
        {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }

    // 4. Cycle Detection Check
    // FIX 3: If we didn't process all nodes, a cycle must exist!
    if (toposort.size() != n)
    {
        return {}; // Return empty vector to signal invalid topological order
    }

    return toposort;
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int n = 6;
    vector<vector<int>> adj(n);

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 1);
    addEdge(adj, 5, 2);

    vector<int> res = topo_sort_kahn(adj);

    if (res.empty())
    {
        cout << "Cycle detected! Topological sort impossible.\n";
    }
    else
    {
        for (int vertex : res)
            cout << vertex << " ";
        cout << endl;
    }
}
