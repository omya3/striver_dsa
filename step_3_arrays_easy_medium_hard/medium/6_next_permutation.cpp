#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> get_next_permutation(vector<int> &arr)
{
    int index = -1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    for (int i = arr.size() - 1; i >= index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }

    reverse(arr.begin() + index + 1, arr.end());
    return arr;
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

    get_next_permutation(arr);
}