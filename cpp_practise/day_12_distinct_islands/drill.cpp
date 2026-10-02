// Day 12: distinct islands using DFS and a set of normalized shapes.
// Complete TODOs without opening solution.cpp until minute 27.

// TODO 1: Add explicit standard headers for sorting, arrays, I/O,
//         pairs, sets, and vectors.
#include <iostream>
#include <vector>
#include <array>
#include <set>

using namespace std;

// TODO 2: Declare Cell, Grid, and Shape as described in README.md.
using Cell = pair<int, int>;
using Grid = vector<vector<int>>;
using Shape = vector<Cell>;

/* RECALL from yesterday:
   Queue type for grid cells:
   Source distance before pushing:
   Unvisited distance value:
   Why check bounds first:
*/

void collect_shape(const Grid &grid, int row, int column,
                   int base_row, int base_column,
                   vector<vector<bool>> &seen, Shape &shape)
{
    // TODO 3: Mark this cell seen and record its relative coordinates.

    // TODO 4: Declare matching up/right/down/left row and column offsets.

    // TODO 5: Try the four neighbors; check bounds before indexing.
    //         Recurse only for land not already seen. Keep the same base.
}

int count_distinct_islands(const Grid &grid)
{
    // TODO 6: Handle an empty grid safely.

    const int rows = static_cast<int>(grid.size());
    const int columns = static_cast<int>(grid[0].size());

    // TODO 7: Declare seen and set<Shape> unique_shapes.

    // TODO 8: Start DFS from each unvisited land cell.
    //         Sort each Shape and insert it into unique_shapes.

    return 0; // TODO 9: Return the number of unique shapes.
}

int main()
{
    // TODO 10: Create the three grids from README.md.

    // TODO 11: Print their distinct-island counts with these labels:
    // repeated plus vertical=
    // rotated shapes=
    // all water=
}
