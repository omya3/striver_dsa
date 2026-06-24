#include <vector>
#include <algorithm>

using namespace std;

// 1. Your Disjoint Set Class Implementation
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// 2. Kruskal's Algorithm within the expected solution class
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // Step A: Create a list of edges formatted as {weight, {u, v}}
        // This makes sorting by weight simple and straightforward
        vector<pair<int, pair<int, int>>> edgeList;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            edgeList.push_back({wt, {u, v}});
        }

        // Step B: Sort all edges in non-decreasing order based on their weights
        sort(edgeList.begin(), edgeList.end());

        // Step C: Initialize the Disjoint Set for V vertices
        DisjointSet ds(V);
        int mstWeight = 0;

        // Step D: Process edges one by one
        for (auto &it : edgeList)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            // If u and v do not share the same ultimate parent, they don't form a cycle
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWeight += wt;      // Add edge weight to MST sum
                ds.unionBySize(u, v); // Combine the two components
            }
        }

        return mstWeight;
    }
};
