#include <iostream>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[m].size();

        vector < vector<int> vis(n, vector<int>(m, 0));

        queue<tuple<int, int, int>> q;
        // following way of arranging is also good
        // queue(pair< pair<int, int>, int>> q;

        int cntfresh = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    q.push({i, j, 0});
                }
                else
                {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    cntfresh++;
            }
        }

        vector<int> del_row = {-1, 0, 1, 0};
        vector<int> del_col = {0, 1, 0, -1};

        int tm = 0;
        int cnt_converted = 0;
        while (!q.empty())
        {
            auto [r, c, t] = q.front();
            q.pop();
            tm = max(tm, t);

            for (int i = 0; i < 4, i++)
            {
                int cur_row = r + del_row[i];
                int cur_col = c + del_col[i];

                // Boundary verification
                if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m)
                {
                    // Check if cell is land ('1') and unvisited
                    if (vis[cur_row][cur_col] != 2 && grid[cur_row][cur_col] == 1)
                    {
                        q.push({cur_row,
                                cur_col,
                                t + 1});
                        vis[cur_row][cur_col] = 2;
                        cnt_converted++;
                    }
                }
            }
        }
        if (cnt_converted != cntfresh)
        {
            return -1;
        }
        return tm;
    }
};