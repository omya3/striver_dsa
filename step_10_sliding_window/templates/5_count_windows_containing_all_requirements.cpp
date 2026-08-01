// method 1

long long countContainingRequirements(vector<int> &arr)
{
    int left = 0;
    int answer = 0;

    for (int right = 0; right < n; right++)
    {
        add(arr[right]);

        while (valid())
        {
            answer += (n - right);
            remove(left);
            left++;
        }
    }
    return answer;
}

// method 2
long long countContainingRequirements(vector<int> &arr)
{
    int left = 0;
    int answer = 0;

    for (int right = 0; right < n; right++)
    {
        add(arr[right]);

        while (valid())
        {

            remove(left);
            left++;
        }
        answer += left;
    }
    return answer;
}

// 