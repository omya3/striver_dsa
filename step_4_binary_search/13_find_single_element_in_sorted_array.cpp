#include <iostream>
using namespace std;

int search_single_element(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid;

    if(low==high){
        return arr[low];
    }
    
    if (arr[low] != arr[low + 1])
    {
        return arr[low];
    }

    if (arr[high] != arr[high - 1])
    {
        return arr[high];
    }

    low += 1;
    high -= 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
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

    search_single_element(arr);
}