class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drink = numBottles;
        int empty = numBottles;
        while(empty){
            if(empty>=numExchange){
                empty -= numExchange;
                drink++;
                empty++;
                numExchange++;
            }
            else break;
        }
        return drink;

    }
};
