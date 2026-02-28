#include <bits/stdc++.h>
using namespace std;

// ---------- MIN side ----------

vector<int> findNse(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nse(n, n); // next smaller index, default n
    stack<int> st;         // indices

    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])  // >= (strict on left)
        {
            st.pop();
        }
        if (!st.empty())
        {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

vector<int> findPsee(vector<int> &nums)
{
    int n = nums.size();
    vector<int> psee(n, -1); // previous smaller index, default -1
    stack<int> st;           // indices

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && nums[st.top()] > nums[i])   // > (strict on right)
        {
            st.pop();
        }
        if (!st.empty())
        {
            psee[i] = st.top();
        }
        st.push(i);
    }
    return psee;
}

long long sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse = findNse(arr);
    vector<int> psee = findPsee(arr);

    long long total = 0;

    for (int i = 0; i < n; ++i)
    {
        long long left  = i - psee[i];
        long long right = nse[i] - i;
        long long contrib = left * right * (long long)arr[i];
        total += contrib;
    }
    return total;
}

// ---------- MAX side ----------

vector<int> findNge(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n, n); // next greater index, default n
    stack<int> st;         // indices

    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])  // <=
        {
            st.pop();
        }
        if (!st.empty())
        {
            nge[i] = st.top();
        }
        st.push(i);
    }
    return nge;
}

vector<int> findPgee(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pgee(n, -1); // previous greater index, default -1
    stack<int> st;           // indices

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && nums[st.top()] < nums[i])   // <
        {
            st.pop();
        }
        if (!st.empty())
        {
            pgee[i] = st.top();
        }
        st.push(i);
    }
    return pgee;
}

long long sumSubarrayMaxs(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge = findNge(arr);
    vector<int> pgee = findPgee(arr);

    long long total = 0;

    for (int i = 0; i < n; ++i)
    {
        long long left  = i - pgee[i];
        long long right = nge[i] - i;
        long long contrib = left * right * (long long)arr[i];
        total += contrib;
    }
    return total;
}

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long total_min = sumSubarrayMins(nums);
        long long total_max = sumSubarrayMaxs(nums);
        return total_max - total_min;
    }
};
