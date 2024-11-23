class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {

        long long cost = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]){
                long long prev_cost = 0;
                long long next_cost = 0;
                
                int start_idx = s[i] - 'a';
                int end_idx = t[i] - 'a';
                
                if(start_idx < end_idx){
                    for(int j = start_idx; j < end_idx; j++){
                        next_cost += nextCost[j];
                    }
                    while(start_idx != end_idx){
                        prev_cost += previousCost[start_idx];
                        start_idx = (start_idx - 1 + 26) % 26; 
                    }
                }
                else{
                    for(int j = start_idx; j > end_idx; j--){
                        prev_cost += previousCost[j];
                    }
                    while(start_idx != end_idx){
                        next_cost += nextCost[start_idx];
                        start_idx = (start_idx + 1) % 26; 
                    }
                }
                cost += min(next_cost, prev_cost);
            }
        }
        return cost;
    }
};
