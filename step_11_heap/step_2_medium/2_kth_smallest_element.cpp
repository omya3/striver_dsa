#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k)
{
    // max-heap of size k
    priority_queue<int> pq;

    for (int x : arr)
    {
        pq.push(x);
        if ((int)pq.size() > k)
            pq.pop();    // remove current largest, keep k smallest overall
    }
    return pq.top();      // top is k-th smallest
}

int main()
{
    vector<int> arr = {11, 9, 8, 7, 3, 1};
    int K = 4;
    cout << kthSmallest(arr, K) << "\n";  // 8 (sorted: 1,3,7,8,9,11)
}
