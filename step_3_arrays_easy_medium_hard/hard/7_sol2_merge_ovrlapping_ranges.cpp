#include <iostream>
using namespace std;

vector<vector<int>> merge_method(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for (int i = 0; i < n; i++)
    {
        if (result.empty() || arr[i][0] > result.back()[1])
        {
            result.push_back(arr[i]);
        }
        else
        {
            result.back()[1] = max(result.back()[1], arr[i][1]);
        }
    }
    return result;
}

int main()
{
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        cin >> temp[0];
        cin >> temp[1];
        arr.emplace_back(temp);
    }
    int result = merge_method(arr);
}