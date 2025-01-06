class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        // Left-to-right pass
        int countLeft = 0, operationsLeft = 0;
        for (int i = 0; i < n; ++i) {
            answer[i] += operationsLeft;
            countLeft += (boxes[i] == '1'); // Count balls in the current box
            operationsLeft += countLeft;    // Accumulate operations
        }

        // Right-to-left pass
        int countRight = 0, operationsRight = 0;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += operationsRight;
            countRight += (boxes[i] == '1'); // Count balls in the current box
            operationsRight += countRight;   // Accumulate operations
        }

        return answer;
    }
};
