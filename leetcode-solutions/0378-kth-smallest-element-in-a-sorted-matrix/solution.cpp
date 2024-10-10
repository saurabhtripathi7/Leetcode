class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        // Max heap to keep track of the smallest k elements
        std::priority_queue<int> maxH;

        // Iterate through each element in the matrix
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                maxH.push(matrix[i][j]); // Push the current element
                // If the heap size exceeds k, remove the largest element
                if (maxH.size() > k) {
                    maxH.pop();
                }
            }
        }

        // The top of the max heap is the k-th smallest element
        return maxH.top();
    }
};

static const auto fastIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
