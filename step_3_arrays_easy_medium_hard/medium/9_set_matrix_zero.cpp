#include <iostream>

using namespace std;

vector<vector<int>> set_to_zero(vector<vector<int>> &matrix)
{
    // int col[n] = {0} ---> matrix[0][...]
    // int row[m] = {0} ---> matrix[...][0]

    int col0_var = 1;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // marking row
                if (j == 0)
                {
                    col0_var = 0; // marking column in special case
                }
                else
                {
                    matrix[0][j] = 0; // marking column
                }
            }
        }
    }

    // now lets traverse the rest of matrix elemens
    // i-e except row and column header elements
    // and mark them as 0
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if ((matrix[0][j] == 0) || (matrix[i][0] == 0))
            {
                matrix[i][j] = 0;
            }
        }
    }

    // lets traverse row 0  and change to zero if matrix[0][0] is set to 0
    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[0][i] = 0;
        }
    }

    // lets traverse col 0 from top and change to zero if col0_var is set to 0

    if (col0_var == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{

    int m, n;
    cout << "Enter the number of rows in the matrix";
    cin >> m;
    cout << "Enter the number of columns in the matrix";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
}