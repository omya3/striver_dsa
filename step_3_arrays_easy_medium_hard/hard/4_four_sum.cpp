#include <iostream>
using namespace std;

vector<vector<int>> find_four_sum_set(vector<int> &arr, int target)
{
    vector<vector<int>> list;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }
            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];

                if (sum > target)
                {
                    l--;
                }
                if (sum < target)
                {
                    k++;
                }
                if (sum == target)
                {
                    list.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
            }
        }
    }
    return list;
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
    vector<vector<int>> result = find_three_sum_set(arr);
}