class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        vector<string> answer; // To store the final result of uncommon words
        unordered_map<string, int> word_count; // Map to keep track of the frequency of each word
        string word = ""; // Temporary string to build each word
        
        // Process the first sentence
        for (char ch : s1)
        {
            if (ch == ' ') // If a space is encountered, it indicates the end of a word
            {
                word_count[word]++; // Increment the count for the current word
                word = ""; // Reset the word string for the next word
            }
            else
            {
                word += ch; // Append the current character to the word
            }
        }
        // If there's any remaining word after the loop, add it to the map
        if (!word.empty()) 
        {
            word_count[word]++;
        }

        // Process the second sentence
        word = ""; // Reset the word string for the second sentence
        for (char ch : s2)
        {
            if (ch == ' ') // If a space is encountered, it indicates the end of a word
            {
                word_count[word]++; // Increment the count for the current word
                word = ""; // Reset the word string for the next word
            }
            else
            {
                word += ch; // Append the current character to the word
            }
        }
        // If there's any remaining word after the loop, add it to the map
        // last word wont have space at the end
        if (!word.empty()) 
        {
            word_count[word]++;
        }

        // Collect uncommon words
        for (auto i : word_count)
        {
            if (i.second == 1) // If a word appears exactly once, it's uncommon
            {
                answer.push_back(i.first); // Add the uncommon word to the result vector
            }
        }

        return answer; // Return the list of uncommon words
    }
};

