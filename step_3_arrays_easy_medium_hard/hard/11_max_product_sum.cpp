#include <iostream>
using namespace std;

int max_prod_subarray(vector<int> &arr)
{
    int pre = 1;
    int suf = 1;
    int n = arr.size();
    int max_prod=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;

        pre *= arr[i];
        suf *= arr[n - i - 1];
        max_prod = max(max_prod, max(pre, suf));
    }
    return max_prod;
}

int main()
{
    cout << "Enter the size of the array 1: " << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, arr.size() - 1);
}