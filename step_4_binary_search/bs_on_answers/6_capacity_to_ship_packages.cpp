#include <iostream>
using namespace std;

tuple<int, int> find_min_and_sum(vector<int> &weights)
{
    int n = weights.size();
    int min_weight = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (weights[i] < min_weight)
        {
            min_weight = weights[i];
        }
        sum += weights[i];
    }
    return make_tuple(min_weight, sum);
}

int is_capacity_suff(vector<int> weights, int days_limit, int capacity)
{
    int n = weights.size();
    int days = 1;
    int sum_weight = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum_weight + weights[i] > capacity)
        {
            sum_weight = weights[i];
            days += 1;
        }
        else
        {
            sum_weight += weights[i];
        }
    }
    if (days <= days_limit)
        return true;
    return false;
}

int find_least_capacity(vector<int> &arr, int days_limit)
{
    int n = arr.size();
    int min_weight, sum;
    tie(min_weight, sum) = find_min_and_sum(arr);
    int left = min_weight;
    int right = sum;
    int mid;
    int ans;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (is_capacity_suff(arr, days_limit, mid))
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

    int total_days;
    cout << "Enter the value of total days";
    cin >> total_days;

    int least_capacity = find_least_capacity(arr, total_days);
}