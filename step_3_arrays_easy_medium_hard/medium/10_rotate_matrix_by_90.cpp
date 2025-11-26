#include <iostream>

using namespace std;

vector<vector<int>> rotate_by_90(vector<vector<int>> &matrix)
{   int n = matrix.size();
    // lets first transpose 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i>=j){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
            }
        }
    }

    int left;
    int right;
    // lets reverse every row now
    for (int i = 0; i < n; i++)
    {   
        left = 0;
        right = n-1;
        while(left<right){
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }   
    }

    cout << "[";
    for (size_t i = 0; i < n; ++i) {
        cout << "[";
        for (size_t j = 0; j < n; ++j) {
            cout << matrix[i][j];
            if (j != matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != matrix.size() - 1) cout << ",";
    }
    cout << "]" << endl;


}

int main()
{

    cout << "Enter the value of n" << endl;
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    rotate_by_90(matrix);
}