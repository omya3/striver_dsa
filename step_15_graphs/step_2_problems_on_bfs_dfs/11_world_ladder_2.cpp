class Solution
{
private:
    // Backtracking function to build paths from endWord back to beginWord
    void findPaths(string word, string beginWord, unordered_map<string, int> &steps,
                   vector<string> &currentPath, vector<vector<string>> &ans)
    {

        // Base case: If we tracked back to the beginWord, we found a valid shortest path
        if (word == beginWord)
        {
            reverse(currentPath.begin(), currentPath.end());
            ans.push_back(currentPath);
            reverse(currentPath.begin(), currentPath.end()); // Backtrack restore
            return;
        }

        int currStep = steps[word];
        string original = word;

        // Try changing every character of the current word
        for (int i = 0; i < word.size(); i++)
        {
            char originalChar = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;

                // A neighbor is only part of a shortest path if it was visited exactly 1 step prior
                if (steps.count(word) && steps[word] == currStep - 1)
                {
                    currentPath.push_back(word);
                    findPaths(word, beginWord, steps, currentPath, ans);
                    currentPath.pop_back(); // Backtrack
                }
            }
            word[i] = originalChar; // Restore character
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words_set(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        // If endWord isn't even in the dictionary, no transformation path can exist
        if (words_set.find(endWord) == words_set.end())
            return ans;

        // BFS Queue maps: tracks string and its shortest step distance from beginWord
        queue<string> q;
        unordered_map<string, int> steps;

        q.push(beginWord);
        steps[beginWord] = 1;
        words_set.erase(beginWord); // Remove to prevent looking backwards

        bool foundEnd = false;

        // PASS 1: Calculate the exact step layer for every word using simple string BFS
        while (!q.empty())
        {
            string word = q.front();
            q.pop();

            int currStep = steps[word];
            if (word == endWord)
                foundEnd = true;

            // Optional Optimization: If we found endWord, we don't need to process deeper levels
            if (foundEnd)
                continue;

            string original = word;
            for (int i = 0; i < word.size(); i++)
            {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;

                    if (words_set.count(word))
                    {
                        q.push(word);
                        steps[word] = currStep + 1;
                        words_set.erase(word); // Erase so other branches on the *same* level can't reuse it
                    }
                }
                word[i] = originalChar;
            }
        }

        // PASS 2: If a valid path reached endWord, backtrack to collect all paths
        if (steps.count(endWord))
        {
            vector<string> currentPath = {endWord};
            findPaths(endWord, beginWord, steps, currentPath, ans);
        }

        return ans;
    }
};
