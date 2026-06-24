#include <vector>
using namespace std;

// 1. Your Disjoint Set Class Template
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

// 2. LeetCode Solution Interface
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        // Base Condition: To connect n nodes, we absolutely need at least n-1 edges
        if (connections.size() < n - 1)
        {
            return -1;
        }

        DisjointSet ds(n);
        int extraCables = 0;

        // Process each cable connection
        for (auto &edge : connections)
        {
            int u = edge[0];
            int v = edge[1];

            // If they already share the same ultimate parent, this cable is redundant
            if (ds.findUPar(u) == ds.findUPar(v))
            {
                extraCables++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }

        // Count how many independent components exist after processing all edges
        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.findUPar(i) == i)
            {
                components++;
            }
        }

        // Total operations needed is always (components - 1)
        return components - 1;
    }
};
