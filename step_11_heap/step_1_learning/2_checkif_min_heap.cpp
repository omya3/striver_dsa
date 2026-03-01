class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // index of last internal node
        for (int i = 0; i <= (n - 2) / 2; ++i) {
            int left  = 2 * i + 1;
            int right = 2 * i + 2;

            // if left child exists and is greater, not a max-heap
            if (left < n && arr[i] < arr[left])
                return false;

            // if right child exists and is greater, not a max-heap
            if (right < n && arr[i] < arr[right])
                return false;
        }
        return true;
    }
};
