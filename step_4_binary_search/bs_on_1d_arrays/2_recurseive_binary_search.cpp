#include <iostream>
#include <vector>
using namespace std;

int recursive_bin_search(vector<int>& arr, int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return recursive_bin_search(arr, mid + 1, high, target);
    else
        return recursive_bin_search(arr, low, mid - 1, target);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter target value: ";
    cin >> target;

    int result = recursive_bin_search(arr, 0, n - 1, target);
    if (result == -1)
        cout << "Target not found." << endl;
    else
        cout << "Target found at index " << result << endl;

    return 0;
}
