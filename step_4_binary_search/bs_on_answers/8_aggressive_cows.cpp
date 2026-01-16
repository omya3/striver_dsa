#include <iostream>
using namespace std;

bool check_if_arrangement_possible(vector<int> &arr, int mid, int cows)
{
    int last = arr[0];
    int n = arr.size();
    int placed_cows = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - last >= mid)
        {
            placed_cows++;
            last = arr[i];
        }
    }
    if (placed_cows >= cows)
        return true;
    return false;
}

int find_min_dist_which_is_max(vector<int> &arr, int cows)
{

    int n = arr.size();
    sort(arr.begin(), arr.end());
    int left = 1;
    int right = (arr[n - 1] - arr[0]);

    while (left <= right)
    {

        int mid = left + (right - left) / 2;
        if (check_if_arrangement_possible(arr, mid, cows))
    }
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

    int cows;
    cout << "Enter the number of cows";
    cin >> cows;

    int least_capacity = find_min_dist_which_is_max(arr, cows);
}