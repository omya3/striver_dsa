class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begn(), wordList.end());
        st.erase(beginWord);

        while (!q.empty())
        {
            string curr_word = q.front().first;
            int curr_dist = q.front().second;

            q.pop();

            int s_len = curr_word.size();

            for (int i = 0; i < s_len; i++)
            {
                string neigh_word = curr_word;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c != curr_word[i])
                    {
                        neigh_word[i] = char(c);

                        if (neigh_word == endWord)
                        {
                            return curr_dist + 1;
                        }
                        if (st.find(neigh_word) != st.end())
                        {
                            st.erase(neigh_word);
                            q.push({neigh_word, curr_dist + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};