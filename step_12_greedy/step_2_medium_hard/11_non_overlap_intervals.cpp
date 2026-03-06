bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];                // sort by end time
}

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), cmp);

        int cnt = 1;                    // we always keep the first interval
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= lastEndTime)
            {
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }
        return n - cnt;                 // remove all others
    }
};
