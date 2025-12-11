#include <iostream>
using namespace std;

int find_the_peak(vector<int> &arr)
{

    int low = 0;
    int high = arr.size() - 1;
    int mid;

    if (low == high)
    {
        return low;
    }

    if (arr[low] > arr[low + 1])
    {
        return low;
    }

    if (arr[high] > arr[high - 1])
    {
        return high;
    }

    low++;
    high--;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if ((arr[mid - 1] < arr[mid]) && (arr[mid] > arr[mid + 1]))
        {
            return mid;
        }

        if (arr[mid] > arr[mid + 1])
        {
            high = mid - 1;
        }

        if (arr[mid] > arr[mid - 1])
        {
            low = mid + 1;
        }

        if ((arr[mid] < arr[mid + 1]) && (arr[mid] < arr[mid - 1]))
        {
            low = mid + 1;
        }
    }

    return -1;
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

    find_the_peak(arr);
}