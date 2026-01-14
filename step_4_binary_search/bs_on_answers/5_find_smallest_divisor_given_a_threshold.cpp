#include <iostream>
using namespace std;

tuple<int, int> find_range(vector<int> &bloomDay)
{
    int n = bloomDay.size();
    int min_days = INT_MAX;
    int max_days = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] < min_days)
        {
            min_days = bloomDay[i];
        }
        if (bloomDay[i] > max_days)
        {
            max_days = bloomDay[i];
        }
    }
    return make_tuple(min_days, max_days);
}

bool check_divisor(vector<int> arr, int divisor, int limit)
{
    int n = arr.size();
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        val += ceil((double)arr[i] / (double)divisor);
    }
    if (val <= limit)
    {
        return true;
    }
    return false;
}

int find_smallest_divisor(vector<int> &arr, int limit)
{
    int n = arr.size();
    int min_lim, max_lim;
    tie(min_lim, max_lim) = find_range(arr);
    int left = 1;
    int right = max_lim;
    int ans;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (check_divisor(arr, mid, limit))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements of the array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int limit;
    cout << "Enter the value of limit";
    cin >> limit;

    int smallest_divisor = find_smallest_divisor(arr, limit);
}