// The central model is:
// add(a[r]);
// remove(a[l]);
// valid();
// record_answer();

// Used when every window must have exactkly k elements

int left = 0;

for (int right = 0; right < n; right++)
{
    add(a[right]);

    if (r - l + 1 > k)
        remove(a[l++]);

    if (r - l + 1 == k)
        record_answer();
}

// example

void sl_wind_sum(vector<int> &arr, int k)
{

    int left = 0;
    long long sum = 0;

    for (int right = 0; right < n; right++)
    {
        sun += arr[left];

        if (right - left + 1 > k)
        {
            sum -= arr[left];
            left++;
        }

        if (right - left + 1 == k)
        {
            cout << sum << " ";
        }
    }
    return;
}

int sl_wind_max_sum(vector<int> &arr, int k)
{

    int left = 0;
    long long sum = 0;
    long long max_sum = INT_MIN;

    for (int right = 0; right < n; right++)
    {
        sun += arr[left];

        if (right - left + 1 > k)
        {
            sum -= arr[left];
            left++;
        }

        if (right - left + 1 == k)
        {
            max_sum = max(sum, max_sum);
        }
    }
    return max_sum;
}