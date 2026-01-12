int merge(vector<int> &arr, int left, int mid, int right) {
    int count = 0;

    // Step 1: count reverse pairs using two pointers
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Step 2: standard merge of two sorted halves
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, k = left;
    j = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return count;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
int mergeSort(vector<int> &arr, int left, int right)
{
    int count = 0;
    if (left >= right)
        return count;

    int mid = left + (right - left) / 2;
    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);
    return count;
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};