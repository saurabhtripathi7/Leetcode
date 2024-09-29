class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";  // Initial word
        while (word.size() < k) {
            string newWord = ""; 
            for (char c : word) {
                char nextChar = (c == 'z') ? 'a' : c + 1;  // Circular increment
                newWord += nextChar;
            }
            word += newWord;  // Append the newWord to original word
        }
        return word[k - 1];  // Return the k-th character (1-based index)
    }
};

