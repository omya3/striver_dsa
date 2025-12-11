#include <iostream>
using namespace std;

bool search_min_element(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    int global_min = INT_MAX;
    int global_min_index = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < global_min)
            {
                global_min_index = low;
                global_min = arr[low];
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < global_min)
            {
                global_min = arr[low];
                global_min_index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (global_min > arr[mid])
            {
                global_min = arr[mid];
                global_min_index = mid;
            }
            high = mid - 1;
        }
    }
    return global_min_index;
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