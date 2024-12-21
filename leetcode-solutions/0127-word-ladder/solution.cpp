class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Step 1: Initialize a queue for BFS traversal
        // Each element in the queue stores the current word and the level of the transformation sequence
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // Start with the `beginWord` at level 1

        // Step 2: Create an unordered set for fast word lookups
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If the endWord is not in the word list, no transformation is possible
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        
        // Remove the beginWord from the set to avoid revisiting
        wordSet.erase(beginWord);

        // Step 3: Start BFS traversal
        while (!q.empty()) {
            string currentWord = q.front().first; // Extract the current word
            int steps = q.front().second;         // Extract the current level
            q.pop();                              // Remove the front of the queue

            // If the current word matches the endWord, return the level
            if (currentWord == endWord) return steps;

            // Step 4: Try all possible one-character transformations
            for (int i = 0; i < currentWord.size(); ++i) {
                char originalChar = currentWord[i]; // Store the original character

                // Replace the current character with every letter from 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    currentWord[i] = ch;

                    // If the transformed word exists in the word set
                    if (wordSet.find(currentWord) != wordSet.end()) {
                        // Add the new word and the updated level to the queue
                        q.push({currentWord, steps + 1});
                        // Remove the word from the set to mark it as visited
                        wordSet.erase(currentWord);
                    }
                }

                // Restore the original character for the next iteration
                currentWord[i] = originalChar;
            }
        }

        // Step 5: If the endWord was not found, return 0
        return 0;
    }
};

