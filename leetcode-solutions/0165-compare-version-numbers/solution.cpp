class Solution {
public:

    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();
        int start1 = 0;
        int start2 = 0;
        while(start1 < n1 || start2 < n2){
            int num1 = 0;
            int num2 = 0;
            while(start1<n1 && version1[start1]!='.'){
                num1 = num1*10 + (version1[start1]-'0');
                start1++;
            }
            while(start2<n2 && version2[start2]!='.'){
                num2 = num2*10 + (version2[start2]-'0');
                start2++;
            }

            if(num1>num2){
                return 1;
            }
            if(num1<num2){
                return -1;
            }

            if(start1<n1 && version1[start1]=='.')
            start1++;
            if(start2<n2 && version2[start2]=='.')
            start2++;
        }
        return 0;
    }
};
