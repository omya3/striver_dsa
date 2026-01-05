#include <iostream>
using namespace std;

vector<int> find_majority(vector<int> &arr)
{
    vector<int> list = {};
    int n = arr.size();
    int ele1 = INT_MIN, ele2 = INT_MIN;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && arr[i] != ele2)
        {
            count1 = 1;
            ele1 = arr[i];
        }
        else if (count2 == 0 && arr[i] != ele1)
        {
            count2 = 1;
            ele2 = arr[i];
        }
        else if (arr[i] == ele2)
        {
            count2++;
        }
        else if (arr[i] == ele1)
        {
            count1++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
        {
            count1++;
        }
        if (arr[i] == ele2)
        {
            count2++;
        }
    }

    int min_req = (n / 3) + 1;
    if (count1 >= min_req)
    {
        list.push_back(ele1);
    }
    if (count2 >= min_req)
    {
        list.push_back(ele2);
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
    // vector<int> v = {0, 0, 0};
    vector<int> result = find_majority(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
}