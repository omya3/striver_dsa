#include <iostream>
using namespace std;

int find_max_subarray_length(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> map;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (map.find(sum) != map.end())
            {
                maxi = max(maxi, i - map[sum]);
            }
            else
            {
                map[sum] = i;
            }
        }
    }
    return maxi;
}

int main()
{
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = find_max_subarray_length(arr);
}