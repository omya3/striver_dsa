// Day 11: four-direction grid BFS for Binary Maze.
// Complete TODOs without opening solution.cpp until minute 27.

// TODO 1: Add explicit headers for arrays, input/output, pairs, queues, and vectors.
#include <iostream>
#include <vector>
#include <queue>
#include <utility> // For std::pair

using namespace std;

// TODO 2: Declare Cell = pair<int, int> and Grid = vector<vector<int>>.
using Cell = pair<int, int>;
using Grid = vector<vector<int>>;

/* RECALL (write without looking):
   Dijkstra State type for long long distances: pair<long long, int> -> {distance, node}
   Dijkstra min-heap declaration: priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
   Insertions for one undirected edge: adj[u].push_back({v, weight}); adj[v].push_back({u, weight});
*/

bool in_bounds(int row, int column, int rows, int columns)
{
    // TODO 3: Return true only for a valid grid position.
    if (row >= 0 && row < rows && column >= 0 && column < columns)
        return true;
    return false;
}

int shortest_path(const Grid &grid, Cell source, Cell destination)
{
    // TODO 4: Reject an empty grid before reading grid[0].
    if (grid.empty() || grid[0].empty())
        return -1;

    const int rows = static_cast<int>(grid.size());
    const int columns = static_cast<int>(grid[0].size());

    // TODO 5: Reject out-of-bounds or blocked endpoints.
    if (!in_bounds(source.first, source.second, rows, columns) || grid[source.first][source.second] == 0)
        return -1;
    if (!in_bounds(destination.first, destination.second, rows, columns) || grid[destination.first][destination.second] == 0)
        return -1;

    // TODO 6: Declare four row offsets and four column offsets using
    //         up, right, down, left in matching positions.
    vector<int> delrows = {-1, 0, +1, 0}; // Up, Right, Down, Left
    vector<int> delcols = {0, +1, 0, -1};

    // TODO 7: Create a distance grid filled with -1 and a queue<Cell>.
    queue<Cell> q;
    vector<vector<int>> distance(rows, vector<int>(columns, -1));

    // NOTE: In an unweighted grid BFS, a single `distance` grid can double as your `visited` tracker!
    // If distance[r][c] != -1, it means it has already been visited.

    // TODO 8: Set the source distance to 0, then push it.
    distance[source.first][source.second] = 0;
    q.push({source.first, source.second});

    // TODO 9 & 10: BFS until the queue is empty.
    while (!q.empty())
    {
        Cell curr = q.front();
        q.pop();

        // Return the destination distance when its cell is removed from the queue
        if (curr.first == destination.first && curr.second == destination.second)
            return distance[curr.first][curr.second];

        for (int i = 0; i < 4; i++)
        {
            int neigh_row = curr.first + delrows[i];
            int neigh_col = curr.second + delcols[i];

            // TODO 10: Check bounds FIRST, then check open (1) and unvisited (-1)
            if (in_bounds(neigh_row, neigh_col, rows, columns) &&
                grid[neigh_row][neigh_col] == 1 &&
                distance[neigh_row][neigh_col] == -1)
            {
                // Set distance before pushing
                distance[neigh_row][neigh_col] = distance[curr.first][curr.second] + 1;
                q.push({neigh_row, neigh_col});
            }
        }
    }

    return -1;
}

int main()
{
    // TODO 11: Construct the reachable 3x4 maze from README.md.
    // 1 represents open pathway, 0 represents a wall/blocked path
    Grid reachable_maze = {
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}};

    // TODO 12: Print shortest_path from {0,0} to {2,3} as "reachable=...".
    cout << "reachable=" << shortest_path(reachable_maze, {0, 0}, {2, 3}) << "\n";

    // TODO 13: Print from {0,0} to {0,0} as "same cell=...".
    cout << "same cell=" << shortest_path(reachable_maze, {0, 0}, {0, 0}) << "\n";

    // TODO 14: Print from {0,0} to {0,2} as "blocked destination=...".
    cout << "blocked destination=" << shortest_path(reachable_maze, {0, 0}, {0, 2}) << "\n";

    // TODO 15: Construct the unreachable 2x2 maze and print its result.
    Grid unreachable_maze = {
        {1, 0},
        {0, 1}};
    cout << "unreachable=" << shortest_path(unreachable_maze, {0, 0}, {1, 1}) << "\n";

    return 0;
}
