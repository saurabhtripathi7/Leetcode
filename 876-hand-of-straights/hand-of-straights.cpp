class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int, int>freq;
        for(int i = 0; i < n; ++i) freq[hand[i]]++;

        while(!freq.empty()){
            int start = freq.begin()->first;

            for(int x = start; x < start + groupSize; ++x){
                if(freq.find(x) == freq.end()) return false;

                freq[x]--;
                if(freq[x] == 0) freq.erase(x);
            }
        }
        return true;

    }
};