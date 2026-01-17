#include <iostream>
using namespace std;

int find_kth_element(vector<int> &arr1, vector<int> &arr2, int n1, int n2, int k)
{

    if (n1 > n2)
    {
        return find_kth_element(arr2, arr1, n2, n1, k);
    }

    int left = k;
    int n = n1 + n2;

    int low = max(k - n2, 0);
    int high = min(k, n1);

    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}

int main()
{

    int n;
    cout << "Enter the size of the array 1" << endl;
    cin >> n;

    vector<int> arr1;
    cout << "Enter the elements of the array 1" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter the size of the array 2" << endl;
    cin >> m;

    vector<int> arr2;
    cout << "Enter the elements of the array 2" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    int k;
    cout << "Enter the value of k";
    cin >> k;

    int n1 = arr1.size();
    int n2 = arr2.size();

    int x = find_kth_element(arr1, arr2, n1, n2, k);
}