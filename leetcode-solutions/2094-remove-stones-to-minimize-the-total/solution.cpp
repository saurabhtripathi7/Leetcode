class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Use a max-heap (priority queue) to always remove from the largest pile
        priority_queue<int> maxH(piles.begin(), piles.end());
        
        // Apply the operation k times
        while (k--) {
            int top = maxH.top();
            maxH.pop();
            
            // Remove half of the top pile (floor division happens automatically with integer division)
            int reduced = top - top / 2;
            
            // Push the remaining pile back into the heap
            maxH.push(reduced);
        }
        
        // Sum up the remaining stones in the heap
        int remainingSum = 0;
        while (!maxH.empty()) {
            remainingSum += maxH.top();
            maxH.pop();
        }
        
        return remainingSum;
    }
};

