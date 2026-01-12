#include <iostream>
using namespace std;

vector<int> math_method(vector<int> &arr)
{
    long long n = arr.size();
    long long Sn = (n * (n + 1)) / 2;
    long long Sn2 = (n * (n + 1) * (2 * n + 1)) / 6;
    long long Sa = 0;
    long long Sa2 = 0;

    for (int i = 0; i < n; i++)
    {
        Sa += arr[i];
        Sa2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = Sa - Sn;
    long long val2 = Sa2 - Sn2;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = val2 - x;
    return {(int)x, (int)y};
}

vector<int> xor_method(vector<int> &arr)
{ int val = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        val ^= arr[i];
        val ^= (i+1);
    }

    // now find which bit is set from the right most end;
    int nth_bit = 0;
    while (1)
    {
        if ((val & (1 << nth_bit)) != 0)
        {
            break;
        }
        nth_bit++;
    }

    int one_set = 0;
    int zero_set = 0;

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & (1 << nth_bit)) != 0)
        {
            one_set ^= arr[i];
        }
        else
        {
            zero_set ^= arr[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if ((i & (1 << nth_bit)) != 0)
        {
            one_set ^= (i);
        }
        else
        {
            zero_set ^= (i);
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == one_set)
        {
            count++;
        }
    }

    if (count == 2)
    {
        return {one_set, zero_set};
    }
    return {zero_set, one_set};
}

int main()
{
    cout << "Enter the size of the array 1: " << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> result1 = math_method(arr);
    vector<int> result2 = xor_method(arr);
}