class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int extra = 0;
        for(char ch:moves){
            if(ch =='U'){
                y++;
            }else if(ch =='D'){
                y--;
            }else if(ch=='L'){
                x++;
            }else if(ch=='R'){
                x--;
            }else{
                extra++;
            }
        }
        return abs(x) + abs(y) + extra;
    }
};