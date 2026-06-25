#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 1. Your Disjoint Set Class Template
class DisjointSet
{
public:
    vector<int> rank, parent, size;
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

// 2. Main Solution Class implementing Striver's logic
class Solution
{
private:
    bool isValid(int r, int c, int n)
    {
        return (r >= 0 && r < n && c >= 0 && c < n);
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Direction vectors for moving Up, Left, Down, Right
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        // --- STEP 1: Connect all existing 1s to build initial components ---
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;

                for (int ind = 0; ind < 4; ind++)
                {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];

                    if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                    {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // --- STEP 2: Try converting each 0 into a 1 to find maximum size ---
        int mx = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;

                // Using a set to avoid adding the same island component multiple times
                set<int> components;
                for (int ind = 0; ind < 4; ind++)
                {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];

                    if (isValid(newr, newc, n))
                    {
                        if (grid[newr][newc] == 1)
                        {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }

                // Calculate size total by summing unique adjacent island components
                int sizeTotal = 0;
                for (auto it : components)
                {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1); // +1 accounts for the flipped '0' cell itself
            }
        }

        // --- EDGE CASE: If the grid contains only 1s, check size of the entire matrix ---
        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }

        return mx;
    }
};
