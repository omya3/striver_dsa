#include <iostream>
using namespace std;

bool search_element(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return true;
        }

        if (arr[mid] == arr[low] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
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

    search_element(arr, target);

}