#include <iostream>
using namespace std;

int find_total_trapped_water(vector<int> &height)
{
    int n = height.size();
    int Lmax = 0, Rmax = 0, total = 0;
    int lt = 0;
    int rt = n - 1;

    while (lt < rt)
    {
        if (height[lt] <= height[rt])
        {
            if (height[lt] < Lmax)
            {
                total += (Lmax - height[lt]);
            }
            else
            {
                Lmax = height[lt];
            }
            lt = lt + 1;
        }
        else
        {
            if (height[rt] < Rmax)
            {
                total += (Rmax - height[rt]);
            }
            else
            {
                Rmax = height[rt];
            }
            rt = rt - 1;
        }
    }
    return total;
}

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int total_water = find_total_trapped_water(height);
        return total_water;
    }
};