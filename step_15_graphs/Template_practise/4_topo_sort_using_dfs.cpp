#include <iostream>
#include <vector>    // FIX 2: Added missing header
#include <algorithm> // FIX 2: Added missing header for reverse

using namespace std;

// FIX 1: Changed return type from 'int' to 'bool'
bool dfs(int node, vector<vector<int>> &grid, vector<int> &visited, vector<int> &toposort)
{
    visited[node] = 1;

    for (auto neigh : grid[node])
    {
        if (visited[neigh] == 0)
        {
            if (!dfs(neigh, grid, visited, toposort))
            {
                return false;
            }
        }
        else if (visited[neigh] == 1)
        {
            return false;
        }
    }

    visited[node] = 2;
    toposort.push_back(node);
    return true;
}

vector<int> topo_sort(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<int> visited(n, 0); // Explicitly zero-initialize
    vector<int> toposort;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            if (!dfs(i, grid, visited, toposort))
            {
                return {}; // Return empty vector if a valid topological sort is impossible
            }
        }
    }
    reverse(toposort.begin(), toposort.end());
    return toposort;
}
