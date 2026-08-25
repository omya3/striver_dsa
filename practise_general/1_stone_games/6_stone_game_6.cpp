class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {

        int n = aliceValues.size();

        vector<pair<int, int>> combined_val;

        for (int i = 0; i < n; i++)
        {
            combined_val.push_back({aliceValues[i] + bobValues[i], i});
        }

        sort(combined_val.begin(), combined_val.end(), [](const auto &a, const auto &b)
             { return a.first > b.first; });

        int alice_val = 0;
        int bob_val = 0;

        for (auto it : combined_val)
        {
            cout << it.first << " " << it.second << endl;
        }

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                alice_val += aliceValues[combined_val[i].second];
            }
            else
            {
                bob_val += bobValues[combined_val[i].second];
            }
        }

        cout << alice_val << endl;
        cout << bob_val;

        if (alice_val > bob_val)
        {
            return 1;
        }
        else if (alice_val < bob_val)
        {
            return -1;
        }
        return 0;
    }
};