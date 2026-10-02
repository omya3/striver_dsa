// Day 12 reference solution. Open after minute 27.

#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using Cell = pair<int, int>;
using Grid = vector<vector<int>>;
using Shape = vector<Cell>;

void collect_shape(const Grid &grid, int row, int column,
                   int base_row, int base_column,
                   vector<vector<bool>> &seen, Shape &shape)
{
    seen[row][column] = true;
    shape.push_back({row - base_row, column - base_column});

    const array<int, 4> row_delta{-1, 0, 1, 0};
    const array<int, 4> column_delta{0, 1, 0, -1};
    const int rows = static_cast<int>(grid.size());
    const int columns = static_cast<int>(grid[0].size());

    for (int direction = 0; direction < 4; ++direction)
    {
        const int next_row = row + row_delta[direction];
        const int next_column = column + column_delta[direction];

        if (next_row < 0 || next_row >= rows ||
            next_column < 0 || next_column >= columns)
        {
            continue;
        }
        if (grid[next_row][next_column] == 0 || seen[next_row][next_column])
        {
            continue;
        }

        collect_shape(grid, next_row, next_column,
                      base_row, base_column, seen, shape);
    }
}

int count_distinct_islands(const Grid &grid)
{
    if (grid.empty() || grid[0].empty())
    {
        return 0;
    }

    const int rows = static_cast<int>(grid.size());
    const int columns = static_cast<int>(grid[0].size());
    vector<vector<bool>> seen(rows, vector<bool>(columns, false));
    set<Shape> unique_shapes;

    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            if (grid[row][column] == 0 || seen[row][column])
            {
                continue;
            }

            Shape shape;
            collect_shape(grid, row, column, row, column, seen, shape);
            sort(shape.begin(), shape.end());
            unique_shapes.insert(shape);
        }
    }

    return static_cast<int>(unique_shapes.size());
}

int main()
{
    const Grid repeated{
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
    };
    const Grid rotated{
        {1, 1, 0, 1, 0},
        {1, 0, 0, 1, 1},
    };
    const Grid water(2, vector<int>(3, 0));

    cout << "repeated plus vertical=" << count_distinct_islands(repeated) << '\n';
    cout << "rotated shapes=" << count_distinct_islands(rotated) << '\n';
    cout << "all water=" << count_distinct_islands(water) << '\n';
}
