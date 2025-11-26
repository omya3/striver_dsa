#include <iostream>
using namespace std;

int iterative_bin_search(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    int mid;

    while (low <= high)
    {

        mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of the array";

    vector<int> arr;
    cout << "Enter the elements of the array";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    iterative_bin_search(arr);
}