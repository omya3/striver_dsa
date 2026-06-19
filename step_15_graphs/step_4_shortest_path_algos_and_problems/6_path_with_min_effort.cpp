#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minCostPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        effort[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        while (!pq.empty())
        {
            int currentEffort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (row == n - 1 && col == m - 1)
                return currentEffort;
            if (currentEffort > effort[row][col])
                continue;
            for (int i = 0; i < 4; i++)
            {
                int nRow = row + dRow[i], nCol = col + dCol[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m)
                {
                    int nextEffort = max(currentEffort, abs(mat[row][col] - mat[nRow][nCol]));
                    if (nextEffort < effort[nRow][nCol])
                    {
                        effort[nRow][nCol] = nextEffort;
                        pq.push({nextEffort, {nRow, nCol}});
                    }
                }
            }
        }
        return 0;
    }
};
