class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        int drink = numBottles;
        while(empty/numExchange){
            drink += (empty/numExchange);
            empty  = empty % numExchange + empty / numExchange;
        }
        return drink;
    }
};
