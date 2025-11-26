#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int find_lonest_subarray_with_sum_k(int arr[], int n, int k)
{

    map<long long, int> hash_map; // Complexity of whole code O(nlogn)

    // unordered_map<long long , int> hash_map; complexity O(n^2) in worst case

    long long sum = 0;
    int start_index = 0;
    int max_len = 0;
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            max_len = max(max_len, i + 1);
        }
        if (hash_map.find(sum - k) != hash_map.end())
        {
            len = i - hash_map[sum - k];
            max_len = max(max_len, len);
        }
        if (hash_map.find(sum) == hash_map.end())
        {
            hash_map[sum] = i; // edge case condition [2,0,0,0,3] k=3
        }
    }
    return max_len;
}
}

int main()
{

    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the sum (k) " << endl;
    cin >> k;

    find_lonest_subarray_with_sum_k(arr, n, k);
}