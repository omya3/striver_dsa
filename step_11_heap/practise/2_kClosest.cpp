class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>> maxHeap;

        for (auto pairs : points)
        {
            maxHeap.push({pow(pairs[0], 2) + pow(pairs[1], 2), pairs});

            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        vector<vector<int>> output;

        while (!maxHeap.empty())
        {
            output.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return output;
    }
};

// suggestions
// Avoid pow() for integer squaring because it returns a floating-point value.
// Store the point index rather than copying an entire vector into the heap.

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<long long, int>> maxHeap;

        for (int i = 0; i < points.size(); i++)
        {
            long long x = points[i][0];
            long long y = points[i][1];
            long long distance = x * x + y * y;

            maxHeap.push({distance, i});

            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        vector<vector<int>> answer;

        while (!maxHeap.empty())
        {
            answer.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return answer;
    }
};