long long atMostK(vector<int> &arr, int k)
{

    if (k < 0)
        return -1;

    int left = 0;
    int n = arr.size();

    for (int right = 0; right < n; right++)
    {
        add(arr[right]);

        while (!valid(k))
        {
            remove(arr[left]);
            left++;
        }

        answer += (right - left + 1);
    }
    return answer;
}

long long exactK(vector<int> &arr, int k)
{

    exactlyK = atMost(K) - atMost(K - 1);
}

// example problems

class Solution
{
private:
    long long atMostK(vector<int> &arr, int k)
    {
        if (k < 0)
            return 0;

        int left = 0;
        int oddCount = 0;

        long long answer = 0;

        for (int right = 0; right < arr.size(); right++)
        {
            oddCount += (arr[right] % 2 != 0);

            while (oddCount > k)
            {
                oddCount -= (arr[left] % 2 != 0);
                left++;
            }

            answer += right - left + 1;
        }

        return answer;
    }

public:
    int countSubarrays(vector<int> &arr, int k)
    {
        return atMostK(arr, k) -
               atMostK(arr, k - 1);
    }
};