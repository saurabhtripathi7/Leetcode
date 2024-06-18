class Solution {
public:
    void merge(vector<int>& arr, int s, int mid, int e) {
        int lenLeft = mid - s + 1;
        int lenRight = e - mid;

        // create left and right arrays for copying
        vector<int> left(lenLeft);
        vector<int> right(lenRight);

        // copying values from original array to left and right arrays
        for (int i = 0; i < lenLeft; ++i) {
            left[i] = arr[s + i];
        }
        for (int i = 0; i < lenRight; ++i) {
            right[i] = arr[mid + 1 + i];
        }

        // merge the left and right arrays back into the original array
        int leftIndex = 0, rightIndex = 0, mainIndex = s;

        while (leftIndex < lenLeft && rightIndex < lenRight) {
            if (left[leftIndex] <= right[rightIndex]) {
                arr[mainIndex++] = left[leftIndex++];
            } else {
                arr[mainIndex++] = right[rightIndex++];
            }
        }

        // copy remaining elements of left array
        while (leftIndex < lenLeft) {
            arr[mainIndex++] = left[leftIndex++];
        }

        // copy remaining elements of right array
        while (rightIndex < lenRight) {
            arr[mainIndex++] = right[rightIndex++];
        }
    }

    void mergeSort(vector<int>& arr, int s, int e) {
        if (s >= e) return;

        int mid = s + (e - s) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        mergeSort(nums, 0, size - 1);
        return nums;
    }
};
