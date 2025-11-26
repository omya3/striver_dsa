#include <iostream>
#include <vector>
using namespace std;

vector<int> print_in_spiral_way(const vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0, right = n - 1;   // columns
    int top = 0, bottom = m - 1;   // rows
    vector<int> nums;

    while (top <= bottom && left <= right) {
        // print top row
        for (int i = left; i <= right; i++)
            nums.emplace_back(matrix[top][i]);
        top++;

        // print right column
        for (int i = top; i <= bottom; i++)
            nums.emplace_back(matrix[i][right]);
        right--;

        // print bottom row (right to left)
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                nums.emplace_back(matrix[bottom][i]);
            bottom--;
        }

        // print left column (bottom to top)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                nums.emplace_back(matrix[i][left]);
            left++;
        }
    }

    return nums;
}

int main() {
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    vector<int> spiral = print_in_spiral_way(matrix);

    cout << "[";
    for (size_t i = 0; i < spiral.size(); ++i) {
        cout << spiral[i];
        if (i != spiral.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
