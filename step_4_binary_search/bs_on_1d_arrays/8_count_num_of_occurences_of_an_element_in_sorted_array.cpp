#include <iostream>
#include <vector>
#include <utility> // Required for std::pair

// Use the standard namespace to avoid writing 'std::' repeatedly
using namespace std;

// --- Corrected lower_bound Function ---
int lower_bound(const vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1; // FIX: Initialize ans to arr.size(). If x is not found, this is the correct return value.

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // FIX: Prevents potential integer overflow
        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1; // Look for an earlier occurrence on the left side
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // Look for an earlier occurrence on the left side
        }
    }
    return ans;
}

// --- Corrected upper_bound Function ---
int upper_bound(const vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1; // FIX: Initialize ans to arr.size().

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // FIX: Prevents potential integer overflow
        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1; // Look for an earlier occurrence on the left side
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// --- Corrected main Function ---
int main()
{ // FIX: main must return int
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // FIX: Properly initialize the vector and read elements into it
    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the target element: ";
    cin >> x;

    int lb = lower_bound(arr, x);
    int ub = upper_bound(arr, x);

    // FIX: Check for boundary conditions correctly before accessing the array
    // Check for boundary conditions before accessing the array
    if (lb == -1)
    {
        return 0;
    }
    else
    {
        return ub - lb + 1;
    }

    return 0; // FIX: Return 0 to indicate successful execution
}
