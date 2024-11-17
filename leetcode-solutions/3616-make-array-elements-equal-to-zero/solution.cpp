class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // Check both directions
                for (int direction : {1, -1}) {
                    vector<int> temp = nums;
                    int curr = i;

                    // Helper logic
                    while (curr >= 0 && curr < n) {
                        if (temp[curr] == 0) {
                            curr += direction;
                        } else if (temp[curr] > 0) {
                            temp[curr]--;
                            direction = -direction;
                            curr += direction;
                        }
                    }

                    // Check if all elements are 0
                    bool allZero = true;
                    for (int num : temp) {
                        if (num != 0) {
                            allZero = false;
                            break;
                        }
                    }

                    if (allZero) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
