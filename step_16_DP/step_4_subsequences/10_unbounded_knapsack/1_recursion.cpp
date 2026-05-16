class Solution
{

private:
    int find_profit(int ind, vector<int> &val, vector<int> &wt, int capacity)
    {
        if (ind == 0)
        {
            return (capacity / wt[0]) * val[0];
        }

        int not_take = find_profit(ind - 1, val, wt, capacity);
        int take = 0;
        if (wt[ind] <= capacity)
        {
            take = val[ind] + find_profit(ind, val, wt, capacity - wt[ind]);
        }
        return max(not_take, take);
    }

public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        int n = val.size();
        return find_profit(n - 1, val, wt, capacity);
    }
};