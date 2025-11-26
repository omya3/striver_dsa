#include <iostream>

using namespace std;

void union_of_arrays(int arr1[], int m, int arr2[], int n)
{
    vector<int> x;

    int i = 0;
    int j = 0;

    while (i < m && j < n) {
        // Skip duplicates in arr1
        while (i > 0 && i < m && arr1[i] == arr1[i - 1]) i++;
        // Skip duplicates in arr2
        while (j > 0 && j < n && arr2[j] == arr2[j - 1]) j++;

        if (i >= m || j >= n) break;

        if (arr1[i] < arr2[j]) {
            if (x.empty() || x.back() != arr1[i])
                x.push_back(arr1[i]);
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (x.empty() || x.back() != arr2[j])
                x.push_back(arr2[j]);
            j++;
        } else { // Elements are equal
            if (x.empty() || x.back() != arr1[i])
                x.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements of arr1
    while (i < m) {
        if (x.empty() || x.back() != arr1[i])
            x.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements of arr2
    while (j < n) {
        if (x.empty() || x.back() != arr2[j])
            x.push_back(arr2[j]);
        j++;
    }

    // Print result
    cout << "Union: ";
    for (int val : x)
        cout << val << " ";
    cout << endl;
}

int main()
{

    cout << "Enter the size of the first array: " << endl;
    int m;
    cin >> m;
    int arr1[m];
    cout << "Enter the elements of the first array: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: " << endl;
    int n;
    cin >> n;
    int arr2[n];
    cout << "Enter the elements of the second array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    union_of_arrays(arr1, m, arr2, n);
}