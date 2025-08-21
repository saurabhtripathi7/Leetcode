class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0; // start with 0 for XOR
        for (char c : s) ans ^= c;  // ans = 0^a^b^c^d 
        for (char c : t) ans ^= c;  // ans = 0^a^b^c^d^a^b^c^d^e
        return ans; // leftover char is the extra one (e)
    }
};

