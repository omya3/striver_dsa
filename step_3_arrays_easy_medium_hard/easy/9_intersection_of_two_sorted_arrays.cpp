#include <iostream>
#include <vector>
using namespace std;

void intersection(int arr1[], int m, int arr2[], int n)
{
    cout << "in doit" << endl;
    int i = 0, j = 0;
    vector<int> intersect;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            // Elements are equal
            intersect.emplace_back(arr1[i]);
            i++;
            j++;
        }
    }
    cout << "Following is the intersection of the sorted arrays" << endl;
    for (int x : intersect)
        cout << x << " ";
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

    if (m < n)
    {
        cout << "call1" << endl;
        intersection(arr1, m, arr2, n);
    }
    else
    {
        cout << "call2" << endl;
        intersection(arr2, n, arr1, m);
    }
    return 0;
}
