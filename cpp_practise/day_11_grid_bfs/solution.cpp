// Day 11 reference solution. Open after minute 27.

#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using Cell = pair<int, int>;
using Grid = vector<vector<int>>;

bool in_bounds(int row, int column, int rows, int columns)
{
    return row >= 0 && row < rows && column >= 0 && column < columns;
}

int shortest_path(const Grid &grid, Cell source, Cell destination)
{
    if (grid.empty() || grid[0].empty())
    {
        return -1;
    }

    const int rows = static_cast<int>(grid.size());
    const int columns = static_cast<int>(grid[0].size());

    if (!in_bounds(source.first, source.second, rows, columns) ||
        !in_bounds(destination.first, destination.second, rows, columns) ||
        grid[source.first][source.second] == 0 ||
        grid[destination.first][destination.second] == 0)
    {
        return -1;
    }

    const array<int, 4> row_delta{-1, 0, 1, 0};
    const array<int, 4> column_delta{0, 1, 0, -1};

    vector<vector<int>> distance(rows, vector<int>(columns, -1));
    queue<Cell> pending;
    distance[source.first][source.second] = 0;
    pending.push(source);

    while (!pending.empty())
    {
        const auto [row, column] = pending.front();
        pending.pop();

        if (Cell{row, column} == destination)
        {
            return distance[row][column];
        }

        for (int direction = 0; direction < 4; ++direction)
        {
            const int next_row = row + row_delta[direction];
            const int next_column = column + column_delta[direction];

            if (!in_bounds(next_row, next_column, rows, columns))
            {
                continue;
            }
            if (grid[next_row][next_column] == 0 ||
                distance[next_row][next_column] != -1)
            {
                continue;
            }

            distance[next_row][next_column] = distance[row][column] + 1;
            pending.push({next_row, next_column});
        }
    }

    return -1;
}

int main()
{
    const Grid reachable{
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 0, 1},
    };
    const Grid unreachable{{1, 0}, {0, 1}};

    cout << "reachable=" << shortest_path(reachable, {0, 0}, {2, 3}) << '\n';
    cout << "same cell=" << shortest_path(reachable, {0, 0}, {0, 0}) << '\n';
    cout << "blocked destination=" << shortest_path(reachable, {0, 0}, {0, 2}) << '\n';
    cout << "unreachable=" << shortest_path(unreachable, {0, 0}, {1, 1}) << '\n';
}
