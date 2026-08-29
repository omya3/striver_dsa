#include <queue>
#include <vector>

class MedianFinder
{
public:
    // pq_max stores the smaller half of numbers (Max-Heap)
    std::priority_queue<int> pq_max;
    // pq_min stores the larger half of numbers (Min-Heap)
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq_min;

    MedianFinder() {}

    void addNum(int num)
    {
        // Step 1: Add to max heap
        pq_max.push(num);

        // Step 2: Balancing step—move the largest element of the lower half to the upper half
        pq_min.push(pq_max.top());
        pq_max.pop();

        // Step 3: Maintain size property (pq_max can have at most 1 more element than pq_min)
        if (pq_max.size() < pq_min.size())
        {
            pq_max.push(pq_min.top());
            pq_min.pop();
        }
    }

    double findMedian()
    {
        // If odd number of elements, pq_max always holds the extra element
        if (pq_max.size() > pq_min.size())
        {
            return pq_max.top();
        }

        // If even number of elements, take the average (use 2.0 to prevent integer division)
        return (pq_max.top() + pq_min.top()) / 2.0;
    }
};
