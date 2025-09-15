class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();
        int result = 0;
        int temp = 0;
        for(int i = 0;i<n;i++){
            if(brokenLetters.find(text[i])!=string::npos){
                temp++;
            }
            if(text[i]==' ')
            {
                
                if(temp==0)
                {
                    result++;
                }
                temp = 0;
            }
        }
        if(temp==0)
        result++;
        return result;
    }
};
