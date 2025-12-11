#include <iostream>
using namespace std;

bool search_min_element(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    int global_min = INT_MAX;

    if (arr[low] <= arr[high])
    {
        return arr[low];
    }

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (mid == low && mid == high)
        {
            return min(arr[mid], global_min);
        }

        if (arr[mid] == arr[low] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

        if (arr[low] <= arr[mid])
        {
            global_min = min(global_min, arr[low]);
            low = mid + 1;
        }
        else
        {
            global_min = min(global_min, arr[mid]);
            high = mid - 1;
        }
    }
    return global_min;
}

int main()
{

    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements of the array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element" << endl;
    cin >> target;

    search_min_element(arr);
}