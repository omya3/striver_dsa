#include <iostream>
using namespace std;

vector<vector<int>> result;

void power(vector<int> &nums, int i, vector<int> &curr)
{
    if (i == nums.size())
    {
        result.push_back(curr);
        return;
    }

    // Include nums[i]
    curr.push_back(nums[i]);
    power(nums, i + 1, curr);

    // Exclude nums[i]
    curr.pop_back();
    power(nums, i + 1, curr);
}

int main()
{
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    vector<int> arr;
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> curr;
    power(arr, 0, curr);
}