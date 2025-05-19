class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        //we need to search for each char of "t" in "s"
        //therefore move both when chars match, else move i fwd to see if curr char of t matches in future or not
        //the last char which does not match ---> till end of string = will be appended after "s"

        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return t.size() - j;

    }
};
