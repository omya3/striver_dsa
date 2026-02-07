#include <iostream>
using namespace std;

void find_all_sums(int ind, int sum, int n, vector<int> &nums, vector<int> &sums)
{
    if (ind == n)
    {
        sums.push_back(sum);
        return;
    }
    find_all_sums(ind + 1, sum + nums[ind], n, nums, sums);
    find_all_sums(ind + 1, sum, n, nums, sums);
}

class Solution
{
public:
    vector<int> subsetSums(vector<int> &nums)
    {
        // your code goes here
        vector<int> sums;
        find_all_sums(0, 0, nums.size(), nums, sums);
        return sums;
    }
};