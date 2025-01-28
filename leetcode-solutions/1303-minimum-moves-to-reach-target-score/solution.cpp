class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(maxDoubles == 0) return target - 1;

        int cnt = 0;

        while(maxDoubles != 0 && target != 1){
            if(target % 2 == 1){
                target -= 1;
                cnt += 1;
            }
            target /= 2;
            cnt++;
            maxDoubles--;
        }
        return cnt + (target-1);


    }
};
