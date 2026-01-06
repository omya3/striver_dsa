#include <iostream>
using namespace std;

vector<vector<int>> merge_method(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!result.empty() && end <= result.back()[1])
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
                continue;
            }
            else
            {   
                i = j-2; // optimisation
                break;
            }
        }
        result.push_back({start, end});
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