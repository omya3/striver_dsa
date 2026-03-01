class Solution {
  public:
    void maxHeapify(int arr[], int n, int i) {
        int largest = i;
        int left  = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

    void convertMinToMaxHeap(int arr[], int n) {
        // build max-heap from bottom (last non-leaf = n/2 - 1)
        for (int i = n/2 - 1; i >= 0; --i) {
            maxHeapify(arr, n, i);
        }
    }
};
