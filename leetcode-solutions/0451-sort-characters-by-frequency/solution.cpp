class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Create a map to store the frequency of each character
        unordered_map<char, int> myMap;

        // Step 2: Populate the frequency map by counting occurrences of each
        // character in the string
        for (char a : s) {
            myMap[a]++; // Increment the count for character 'a'
        }

        // Step 3: Initialize an empty result string
        string res;

        // Step 4: Process the frequency map until it is empty
        while (!myMap.empty()) {
            char ch = '\0'; // Variable to store the character with the highest
                            // frequency
            int count = 0;  // Variable to store the highest frequency found

            // Step 5: Find the character with the maximum frequency
            for (auto b : myMap) {
                if (b.second > count) { // If current character's frequency greater than 'count'
                    count = b.second;   // Update 'count' with the new highest frequency
                    ch = b.first; // Update 'ch' with the new character having the highest frequency
                }
            }

            // Step 6: Append the character 'ch' 'count' times to the result string
            res.append(count, ch);

            // Step 7: Remove the character 'ch' from the frequency map
            myMap.erase(ch);
        }

        // Step 8: Return the result string which is sorted by character frequency in descending order
        return res;
    }
};
