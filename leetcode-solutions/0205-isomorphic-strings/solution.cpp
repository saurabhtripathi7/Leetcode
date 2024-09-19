class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map<char, char> map1, map2;
        
        for(int i = 0; i < s.length(); ++i) {
            char c1 = s[i], c2 = t[i];
            
            // Check if there's already a mapping for s[i] in map1
            if(map1.count(c1)) {
                if(map1[c1] != c2) return false;  // Mapping mismatch
            } else {
                map1[c1] = c2;
            }

            // Check if there's already a mapping for t[i] in map2
            if(map2.count(c2)) {
                if(map2[c2] != c1) return false;  // Mapping mismatch
            } else {
                map2[c2] = c1;
            }
        }
        
        return true;
    }
};

