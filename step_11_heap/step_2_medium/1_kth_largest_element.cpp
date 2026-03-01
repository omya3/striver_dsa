#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> &arr, int k)
{
    // min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : arr)
    {
        pq.push(x);
        if ((int)pq.size() > k)
            pq.pop();    // keep only k largest
    }
    return pq.top();      // k-th largest
}

int main()
{
    vector<int> arr = {11, 9, 8, 7, 3, 1};
    int K = 4;
    cout << kthLargest(arr, K) << "\n";  // 7
}
