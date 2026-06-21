class Solution {
public:
    void countingSort(vector<int>& nums){
        int n = nums.size();
        int maxElem = *max_element(nums.begin(), nums.end());
        vector<int>count(maxElem+1);

        for(auto num : nums) count[num]++;

        int idx = 0;
        for(int val = 0; val < maxElem+1; ++val){ // val = org element (check if each from 0 to max existed org or not)
            while(count[val]--){ // if val existed in org array, take its freq and put it freq times
                nums[idx++] = val; // put org Elem back in the array
            }
        }

    }
    int maxIceCream(vector<int>& costs, int coins) {
        countingSort(costs);
        
        int ans = 0;
        for(int i = 0; i < costs.size(); ++i){
            if(coins >= costs[i]){
                ans++;
                coins -= costs[i];
            }
        }
        return ans;
    }
};