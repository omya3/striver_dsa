#include <iostream>
using namespace std;

void swap(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int temp = arr1[n];
    arr1[n] = arr2[m];
    arr2[m] = temp;
    return;
}

void merge(vector<int> &arr1, vector<int> &arr2, int n, int m)
{

    int len = (n + m);

    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {

            if (left < n && right >= n)
            {
                swap(arr1, arr2, left, right - n); // left is in arr1, right is in arr2
            }
            else if (left >= n)
            {
                swap(arr2, arr2, left - n, right - n); // both left and right are in arr2
            }
            else
            {
                swap(arr1, arr1, left, right); // both left and right are in arr1
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{

    cout << "Enter the size of the array 1: " << endl;
    int n;
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of the array 2: " << endl;
    int m;
    cin >> m;
    vector<int> arr2(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    merge(arr1, arr2);
}