#include <iostream>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        int n = bills.size();
        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
            {
                five += 1;
                continue;
            }
            if (bills[i] == 10)
            {
                if (five)
                {
                    five -= 1;
                    ten += 1;
                    continue;
                }
                else
                {
                    return false;
                }
            }
            if (bills[i] == 20)
            {
                if (five && ten)
                {
                    five -= 1;
                    ten -= 1;
                    continue;
                }
                else if (five >= 3)
                {
                    five -= 3;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};