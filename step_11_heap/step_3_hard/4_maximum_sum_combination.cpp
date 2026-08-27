class Solution
{
public:
    vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k)
    {
        // code here

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> visited;

        pq.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});

        vector<int> output;

        while (k-- > 0 and !pq.empty())
        {

            auto [max, pair] = pq.top();
            pq.pop();
            // cout<<max<<endl;

            output.push_back(max);

            int i = pair.first;
            int j = pair.second;
            // cout<<i<<" "<<j<<endl;

            if ((i + 1) < a.size() and visited.find({i + 1, j}) == visited.end())
            {
                // cout<<"first push"<<a[i+1]+b[j]<<endl;
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if ((j + 1) < b.size() and visited.find({i, j + 1}) == visited.end())
            {
                // cout<<"second push"<<a[i+1]+b[j]<<endl;
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return output;
    }
};