class KthLargest
{
private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

public:
    // Initializer list sets up 'k' and builds the heap in O(N) time
    KthLargest(int k, std::vector<int> &nums) : k(k), min_heap(nums.begin(), nums.end())
    {
        // Shrink the heap down to only hold the k largest elements
        while (min_heap.size() > k)
        {
            min_heap.pop();
        }
    }

    int add(int val)
    {
        // Optimization: If heap is full, only push if val is larger than the kth largest
        if (min_heap.size() < k)
        {
            min_heap.push(val);
        }
        else if (val > min_heap.top())
        {
            min_heap.push(val);
            min_heap.pop(); // Remove old kth largest
        }

        return min_heap.top();
    }
};
