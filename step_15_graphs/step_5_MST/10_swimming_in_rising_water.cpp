#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // Min-heap tracking: {max_elevation_so_far, x, y}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // 1. Visited tracker initialized to false
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Start at (0, 0). The initial cost is the height of the starting cell.
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        // Direction arrays for moving Up, Right, Down, Left
        vector<int> rows = {-1, 0, 1, 0};
        vector<int> cols = {0, 1, 0, -1};

        while (!pq.empty())
        {
            // FIX: Changed pq.to() to pq.top()
            auto [cost, x, y] = pq.top();
            pq.pop();

            // Destination reached! Since it's a min-heap, this cost is guaranteed optimal.
            if (x == n - 1 && y == n - 1)
            {
                return cost;
            }

            for (int i = 0; i < 4; i++)
            {
                int curr_row = x + rows[i];
                int curr_col = y + cols[i];

                // 2. BOUNDARY CHECK: Ensure the neighbor is inside the grid
                if (curr_row >= 0 && curr_row < n && curr_col >= 0 && curr_col < n)
                {

                    // 3. VISITED CHECK: Only process if it hasn't been visited yet
                    if (!visited[curr_row][curr_col])
                    {
                        visited[curr_row][curr_col] = true;

                        // FIX: The cost to enter a neighbor is the MAXIMUM peak on the path.
                        // It's the maximum between the current path cost and the neighbor's height.
                        int next_cost = max(cost, grid[curr_row][curr_col]);

                        pq.push({next_cost, curr_row, curr_col});
                    }
                }
            }
        }
        return 0;
    }
};
