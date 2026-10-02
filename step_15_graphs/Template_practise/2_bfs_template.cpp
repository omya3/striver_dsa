#include <queue>
#include <vector>

using namespace std;

// Invariant: when a node is first enqueued, its distance is the minimum
// number of unweighted edges from source.
vector<int> bfsDistance(int source, const vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> distance(n, -1);
    queue<int> pending;

    distance[source] = 0;
    pending.push(source);

    while (!pending.empty())
    {
        int node = pending.front();
        pending.pop();

        for (int neighbor : adj[node])
        {
            if (distance[neighbor] == -1)
            {
                distance[neighbor] = distance[node] + 1;
                pending.push(neighbor);
            }
        }
    }
    return distance;
}
