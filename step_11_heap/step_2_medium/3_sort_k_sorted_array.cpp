class Solution
{
public:
    bool isKSortedArray(vector<int> &arr, int k)
    {
        int n = arr.size();

        // Vector to store pairs of {element, original_index}
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++)
        {
            vec[i] = {arr[i], i};
        }

        // Sort the vector based on element values
        // This reveals the true target position for every element
        sort(vec.begin(), vec.end());

        // Check if any element is further than k distance from its original position
        for (int sorted_index = 0; sorted_index < n; sorted_index++)
        {
            int original_index = vec[sorted_index].second;

            if (abs(original_index - sorted_index) > k)
            {
                return false;
            }
        }

        return true;
    }
};
