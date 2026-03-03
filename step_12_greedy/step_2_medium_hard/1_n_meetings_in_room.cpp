#include <iostream>
using namespace std;

class Data
{

public:
    int start = 0;
    int end = 0;
    int pos = 0;
};

bool cmpEnd(const Data &a, const Data &b)
{
    return a.end < b.end;
}

int arrange_meetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<Data> arr(n);

    for (int i = 0; i < n; ++i)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1; // or i, depending on problem
    }

    sort(arr.begin(), arr.end(), cmpEnd);

    int meeting_count = 1;

    int lastEnd = arr[0].end; // end time of last selected meeting

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start > lastEnd) // strictly after last selected
        {
            meeting_count++;
            lastEnd = arr[i].end;
        }
    }
    return meeting_count;
}

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        return arrange_meetings(start, end);
    }
};