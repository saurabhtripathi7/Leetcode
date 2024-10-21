class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // Initialize a vector to store the result of operations
        vector<string> ans;
        
        // Initialize an index to track the position in the target array
        int idx = 0; 

        // Loop through numbers from 1 to n
        for (int i = 1; i <= n && idx < target.size(); i++) {
            // Always "Push" the current number onto the array
            ans.push_back("Push");
            
            // If the current number (i) is not in the target array at index idx
            if (i != target[idx]) {
                // "Pop" the number since it's not needed
                ans.push_back("Pop");
            } else {
                // If it is in the target, move to the next number in the target
                idx++; 
            }
        }

        // Return the sequence of operations as a vector of strings
        return ans;
    }
};

