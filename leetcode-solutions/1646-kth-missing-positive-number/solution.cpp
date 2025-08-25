class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0, e = arr.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                s = mid + 1;  // kth missing is to the right
            } else {
                e = mid - 1;  // kth missing is to the left
            }
        }

        // after loop: s = first index where missing >= k
        // answer is k more than numbers up to arr[e]
        return s + k;
    }
};

