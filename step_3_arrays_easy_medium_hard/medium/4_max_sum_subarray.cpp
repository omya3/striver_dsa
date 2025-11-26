#include <iostream>
using namespace std;

int max_sum_subarray(vector<int> &arr)
{
    int max = INT_MIN;
    int sum = 0;
    int start = 0;
    int end = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum = sum + arr[i];

        if (sum > max)
        {
            max = sum;
            end = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    // for(int i = start; i<=end; i++){
    //     cout<<arr[i]<<" "
    // }
    return max;
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

    max_sum_subarray(arr);
}