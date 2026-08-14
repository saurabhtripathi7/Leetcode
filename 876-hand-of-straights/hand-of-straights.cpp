class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int, int>freq;
        for(int i = 0; i < n; ++i) freq[hand[i]]++;

        while(!freq.empty()){
            int currentCard = freq.begin()->first;
            // Check each consecutive sequence of groupSize cards
            for (int i = 0; i < groupSize; i++) {
                // If a card is missing or has exhausted its occurrences
                if (freq[currentCard + i] == 0) return false;

                freq[currentCard + i]--;
                // Remove the card value if its occurrences are exhausted
                if (freq[currentCard + i] < 1) freq.erase(currentCard + i);
            }
        }
        return true;

    }
};