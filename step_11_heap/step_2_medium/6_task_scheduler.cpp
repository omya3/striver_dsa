class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        for (char c : tasks)
        {
            freq[c - 'A']++;
        }

        int maxFreq = 0;
        for (int f : freq)
            maxFreq = max(maxFreq, f);

        int countMax = 0;
        for (int f : freq)
            if (f == maxFreq)
                countMax++;

        int frame = (maxFreq - 1) * (n + 1) + countMax;
        return max((int)tasks.size(), frame);
    }
};

// foll is max heap based greedy idea

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        priority_queue<int> max_heap;

        int char_map[26] = {0};

        for (char ch : tasks)
        {
            char_map[ch - 'A'] += 1;
        }

        for (int it : char_map)
        {
            if (it > 0)
            {
                max_heap.push(it);
            }
        }

        int total_slot = 0;
        while (!max_heap.empty())
        {
            vector<int> temp;
            int curr_slots = 0;
            for (int i = 0; i <= n; i++)
            {

                if (!max_heap.empty())
                {
                    int count = max_heap.top();
                    max_heap.pop();
                    count -= 1;
                    if (count > 0)
                    {
                        temp.push_back(count);
                    }
                    curr_slots += 1;
                }
                else if (temp.empty())
                    break; // no tasks pending to do then stop
                else
                {
                    curr_slots += 1; // adding idle till ...n tasks are done
                }
            }

            if (!temp.empty())
            {
                for (int it : temp)
                {
                    max_heap.push(it);
                }
            }
            total_slot += curr_slots;
        }
        return total_slot;
    }
};