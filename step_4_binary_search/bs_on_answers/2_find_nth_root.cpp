#include <iostream>
using namespace std;

long long power(long long base, int exp, long long limit)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            result *= base;
            if (result > limit)
                return limit + 1; // early stop to avoid overflow
        }
        base *= base;
        if (base > limit)
            base = limit + 1;
        exp >>= 1;
    }
    return result;
}

int nthRoot(int n, int m)
{
    if (m == 0)
        return 0;
    if (m == 1)
        return 1;
    // Code here
    int low = 1;
    int high = m;
    long long mid;
    int ans = -1;
    long long val;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        val = power(mid, n, m);
        ;
        if (val == m)
        {
            return mid;
        }
        else if (val < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the value of n";
    cin >> n;

    int m;
    cout << "Enter the value of m";
    cin >> m;

    nthRoot(n, m);
}