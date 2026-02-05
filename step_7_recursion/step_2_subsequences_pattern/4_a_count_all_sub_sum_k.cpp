#include <iostream>
using namespace std;

int find_sub_sum(int i, vector<int> arr, int curr_sum, int target, int n)
{
    if (i == n)
    {
        if (curr_sum == target)
            return 1;
        else
            return 0;
    }

    int l = find_sub_sum(i + 1, arr, curr_sum + arr[i], target, n);
    int r = find_sub_sum(i + 1, arr, curr_sum, target, n);
    return l + r;
}

int main()
{
}