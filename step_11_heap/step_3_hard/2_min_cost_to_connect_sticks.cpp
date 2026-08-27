class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        int cost = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        while (pq.size() > 1)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            cost += (first + second);
            pq.push(first + second);
        }
        return cost;
    }
};