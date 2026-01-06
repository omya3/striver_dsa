#include <iostream>
using namespace std;

int find_max_subarray_length(vector<int> &arr, int target)
{
    int n = arr.size();
    map<int, int> mpp;
    int xr = 0;
    mpp[xr] += 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];

        int search = target ^ xr;
        if (mpp.find(search) != mpp.end())
        {
            count += mpp[search];
        }

        mpp[xr] += 1;
    }
    return count;
}

int main()
{
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = find_max_subarray_length(arr);
}