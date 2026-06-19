#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // Edge case: If start or end cell is blocked, no path exists
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }

        // Base case: For a 1x1 matrix that is open
        if (n == 1)
        {
            return 1;
        }

        // Queue stores pairs of coordinates: {row, col}
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark the starting cell as visited

        int pathLength = 1;

        // Offset arrays for all 8 possible directional moves
        int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // Standard BFS traversal loop
        while (!q.empty())
        {
            int size = q.size();

            // Process all nodes at the current distance level
            for (int i = 0; i < size; i++)
            {
                auto [row, col] = q.front();
                q.pop();

                // If we reached the target bottom-right cell
                if (row == n - 1 && col == n - 1)
                {
                    return pathLength;
                }

                // Explore all 8 adjacent neighbors
                for (int d = 0; d < 8; d++)
                {
                    int nRow = row + dRow[d];
                    int nCol = col + dCol[d];

                    // Check boundary limits and ensure the neighbor cell is open (0)
                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0)
                    {
                        // Optimization: Check destination early to stop execution faster
                        if (nRow == n - 1 && nCol == n - 1)
                        {
                            return pathLength + 1;
                        }

                        grid[nRow][nCol] = 1; // Mark as visited
                        q.push({nRow, nCol});
                    }
                }
            }
            pathLength++; // Move to the next distance layer
        }

        return -1; // Destination is unreachable
    }
};
