#include <iostream>
using namespace std;

vector<int> generate_row(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.emplace_back(ans);
    }
    return ansRow;
}

vector<vector<int>> generate_triangle(int numRows)
{
    vector<vector<int>> answer;
    for (int row = 1; row <=numRows; row++)
    {
        answer.emplace_back(generate_row(row));
    }
    return answer;
}

int main()
{
    int num_rows;
    cout << "Enter the number of rows you want to print" << endl;
}