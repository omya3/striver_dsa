#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

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

// 2. LeetCode / GFG Solution Interface
class Solution
{
public:
    vector<vector<string>> accMerge(vector<vector<string>> &arr)
    {
        int n = arr.size();
        DisjointSet ds(n);

        // Step 1: Map each mail to its first seen account index
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < arr[i].size(); j++)
            {
                string mail = arr[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else
                {
                    // If email already seen, union current index with the previous one
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // Step 2: Group emails by their ultimate parent index
        vector<vector<string>> mergedMail(n);
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        // Step 3: Sort emails and prepend the account name
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].size() == 0)
                continue;

            // Lexicographically sort the emails belonging to this component
            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(arr[i][0]); // Push the account name
            for (auto it : mergedMail[i])
            {
                temp.push_back(it); // Push sorted emails
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
