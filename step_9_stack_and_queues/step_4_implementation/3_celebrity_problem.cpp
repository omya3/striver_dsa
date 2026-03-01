#include <bits/stdc++.h>
using namespace std;

int find_celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    int top = 0, down = n - 1;

    // Phase 1: find candidate
    while (top < down)
    {
        if (mat[top][down] == 1)
        {
            // top knows down -> top can't be celebrity
            top++;
        }
        else
        {
            // top doesn't know down -> down can't be celebrity
            down--;
        }
    }
    int cand = top; // possible celebrity

    // Phase 2: verify candidate
    for (int i = 0; i < n; i++)
    {
        if (i == cand) continue;

        // cand must not know i, and i must know cand
        if (mat[cand][i] == 1 || mat[i][cand] == 0)
            return -1;
    }
    return cand;
}

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        return find_celebrity(mat);
    }
};
