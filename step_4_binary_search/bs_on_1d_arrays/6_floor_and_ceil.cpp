#include <iostream>
using namespace std;

int floor(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    int mid;
    int ans = arr.size();

    while (low <= high)
    {

        mid = (low + high) / 2;

        if (arr[mid] <= target)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int ceil(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    int mid;
    int ans = arr.size();

    while (low <= high)
    {

        mid = (low + high) / 2;

        if (arr[mid] >= target)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array";
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements of the array";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element for which we want to find floor and ceil";
    cin >> x;

    floor(arr, x);
    ceil(arr, x);
}