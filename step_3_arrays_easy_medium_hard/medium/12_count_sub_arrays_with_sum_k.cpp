#include <iostream>
#include <unordered_map>
using namespace std;

int num_subarrays(vector<int> &arr, int k)
{
    unordered_map<int, int> myUnorderedMap;
    myUnorderedMap[0] = 1;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (myUnorderedMap.count(sum - k) > 0)
        {
            count+=myUnorderedMap[sum-k];
        }
        if (myUnorderedMap.count(sum)>0)
        {
            myUnorderedMap[sum]++;
        }
        else
        {
            myUnorderedMap[sum] = 1;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    int k;
    cout << "Enter the value of k" << endl;
    cin >> k;

    vector<int> arr;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    count = num_subarrays(arr, k);
}