#include <bits/stdc++.h>
using namespace std;

class Job {
public:
    int id;
    int profit;
    int deadline;
};

bool comp(const Job &a, const Job &b) {
    return a.profit > b.profit;           // sort profit descending
}

class Solution {
public:
    // DSU: parent[t] = latest available slot <= t
    int findParent(vector<int> &parent, int t) {
        if (parent[t] == t) return t;
        return parent[t] = findParent(parent, parent[t]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<Job> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i].id = i;
            arr[i].profit = profit[i];
            arr[i].deadline = deadline[i];
        }

        sort(arr.begin(), arr.end(), comp);

        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }

        // DSU parent array for slots [0..maxDeadline]
        // parent[t] = largest free slot <= t; 0 means no slot
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; ++i)
            parent[i] = i;

        int totalProfit = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int d = arr[i].deadline;
            if (d > maxDeadline) d = maxDeadline;

            int available = findParent(parent, d);
            if (available > 0) {
                // schedule job in slot "available"
                cnt++;
                totalProfit += arr[i].profit;
                // mark this slot as used: next free slot <= available-1
                parent[available] = findParent(parent, available - 1);
            }
        }

        return {cnt, totalProfit};
    }
};
