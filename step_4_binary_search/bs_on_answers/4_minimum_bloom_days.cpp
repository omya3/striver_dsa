#include <iostream>
#include <tuple>
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

bool is_bloomDay_valid(vector<int> bloomDay, int day, int m, int k)
{
    int n = bloomDay.size();
    int count = 0;
    int bouquets = 0;
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= day)
        {
            count++;
        }
        else
        {
            bouquets += (count / k);
            count = 0;
        }
    }
    if (count > 0)
    {
        bouquets += (count / k);
    }
    if (bouquets >= m)
    {
        return true;
    }
    return false;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    long long val = m * 1ll * k * 1ll;
    if (val > n)
    {
        return -1;
    }
    int min_days, max_days;
    tie(min_days, max_days) = find_range(bloomDay);
    int left = min_days;
    int right = max_days;
    int mid;
    bool valid;
    int ans = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        valid = is_bloomDay_valid(bloomDay, mid, m, k);
        if (valid)
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

    int m;
    cout << "Enter the value of m";
    cin >> m;

    int k;
    cout << "Enter the value of k";
    cin >> k;

    minDays(arr, m, k);
}