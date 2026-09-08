class Solution
{

private:
    int cutter(int ind, int n, vector<int> &price)
    {
        if (ind == 0)
        {
            return price[ind] * n;
        }

        int not_take = cutter(ind - 1, n, price);
        int take = INT_MIN;
        int rod_length = ind + 1;
        if (rod_length <= n)
        {
            take = price[ind] + cutter(ind, n - rod_length, price);
        }
        return max(take, not_take);
    }

public:
    int cutRod(vector<int> &price)
    {
        // code here
        int p_size = price.size();
        return cutter(p_size - 1, p_size, price);
    }
};