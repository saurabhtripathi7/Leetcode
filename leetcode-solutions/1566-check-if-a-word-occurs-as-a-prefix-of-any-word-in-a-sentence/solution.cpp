#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        string word;
        int cnt = 1; // Start counting from 1

        while (s >> word) {
            if (word.find(searchWord) == 0) { // Check if the word starts with searchWord
                return cnt; // Return the one-based index
            }
            cnt++;
        }
        return -1; // Return -1 if no word matches
    }
};

