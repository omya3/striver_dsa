int shortestSlidingWindow(vector<int> &arr)
{
    int n = arr.size();
    int left = 0;
    int answer = INT_MAX;

    for (int right = 0; right < n; right++)
    {
        add(arr[right]);

        while (valid())
        {
            answer = min(answer, right - left + 1);

            remove(arr[left]);
            left++;
        }
    }

    return answer == INT_MAX ? 0 : answer;
}

// example min substr containing all chars from given str in parent str.

string min_win(string s, string p)
{

    vector<int> hash(256, 0);
}