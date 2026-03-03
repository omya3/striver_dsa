#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0;  // arrival index
        int j = 0;  // departure index
        int count = 0;
        int maxCount = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])   // a train arrives
            {
                count++;
                maxCount = max(maxCount, count);
                i++;
            }
            else                    // a train departs
            {
                count--;
                j++;
            }
        }
        return maxCount;
    }
};
