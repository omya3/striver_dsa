class Solution
{

private:
    int get_lis(int curr_ind, int prev_ind, int n, vector<int> &arr)
    {
        if (curr_ind == n)
        {
            return 0;
        }

        int len = 0 + get_lis(curr_ind + 1, prev_ind, n, arr);

        if (prev_ind == -1 || arr[curr_ind] > arr[prev_ind])
        {
            len = max(len, 1 + get_lis(curr_ind + 1, curr_ind, n, arr));
        }
        return len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        return get_lis(0, -1, nums.size(), nums);
    }

};
