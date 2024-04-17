class Solution {
public:
    string customSortString(string order, string s) {
        // creating a hashmap named memo
        unordered_map<char, int> memo; // element, freq
        string ans="";

        // populating the hashmap or counting the occurance of each char
        for(auto ch: s){
            memo[ch]++;
        }
        for(auto ch: order){
            // If character ch exists in string s, append it to the result string
            // Repeat until all occurrences of ch are appended

            while(memo[ch] != 0){
                ans+=ch;
                memo[ch]--;
            }
        }
        // for remaining elements in map 
        // Append remaining characters from string s that are not present in order
        for(auto val: memo){
        // If there are remaining occurrences of a character in s,
        // append them to the result string
        
            while(val.second != 0){
                ans += val.first;
                val.second--;
            }
        }
    return ans;

    }
};
