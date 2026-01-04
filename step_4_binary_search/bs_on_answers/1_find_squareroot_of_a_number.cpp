#include <iostream>
using namespace std;

int find_root_log_way(int n)
{
    int low = 0;
    int high = n;
    long long mid;
    int ans;
    long long val;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        val = mid * mid;
        if (val <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the value of n";
    cin >> n;
    find_root_log_way(n);
}