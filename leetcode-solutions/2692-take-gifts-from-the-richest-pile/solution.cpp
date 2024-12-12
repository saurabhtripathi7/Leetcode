class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(begin(gifts), end(gifts));

        while(k--){
            int top = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(floor(sqrt(top)));
        }
        long long total = 0;
        while (!maxHeap.empty()) {
            total += maxHeap.top();
            maxHeap.pop();
        }

        return total;
    }
};
