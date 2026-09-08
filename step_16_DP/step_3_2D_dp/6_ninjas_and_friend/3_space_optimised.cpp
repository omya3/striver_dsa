#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // prev tracks row r+1, curr tracks row r
        vector<vector<int>> prev(n, vector<int>(n, -1));
        vector<vector<int>> curr(n, vector<int>(n, -1));

        // 1. Initialize the Base Case (Last Row)
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                if (j1 == j2)
                {
                    prev[j1][j2] = grid[m - 1][j1];
                }
                else
                {
                    prev[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
                }
            }
        }

        // 2. Bottom-up DP Transitions
        for (int r = m - 2; r >= 0; r--)
        {
            for (int j1 = 0; j1 < n; j1++)
            {
                for (int j2 = 0; j2 < n; j2++)
                {

                    int val = (j1 == j2) ? grid[r][j1] : grid[r][j1] + grid[r][j2];
                    int maxi = -1e8;

                    // Explore all 9 transition combinations for both robots
                    for (int dir1 = -1; dir1 <= 1; dir1++)
                    {
                        for (int dir2 = -1; dir2 <= 1; dir2++)
                        {
                            int next_j1 = j1 + dir1;
                            int next_j2 = j2 + dir2;

                            // Ensure robot steps stay within the column boundaries
                            if (next_j1 >= 0 && next_j1 < n && next_j2 >= 0 && next_j2 < n)
                            {
                                int next_cherries = prev[next_j1][next_j2];
                                maxi = max(maxi, val + next_cherries);
                            }
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            // FIXED: Move current row data into prev for the next upper row iteration
            prev = curr;
        }

        // FIXED: Returns from prev to correctly handle 1-row grids and the final swap state
        return prev[0][n - 1];
    }
};