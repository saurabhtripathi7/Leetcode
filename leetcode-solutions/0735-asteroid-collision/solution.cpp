class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> st;  // Using a vector as a stack.

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                // Positive asteroids just get pushed to the stack.
                st.push_back(nums[i]);
            } else {
                // Handle collisions with negative asteroids.
                while (!st.empty() && st.back() > 0 && st.back() < abs(nums[i])) {
                    // Pop all smaller positive asteroids that collide with the current negative one.
                    st.pop_back();
                }

                if (!st.empty() && st.back() == abs(nums[i])) {
                    // If the current asteroid has the same size as the last positive one, both get destroyed.
                    st.pop_back();
                } 
                else if (st.empty() || st.back() < 0) {
                    // If the stack is empty or the top asteroid is negative, add the current asteroid.
                    st.push_back(nums[i]);
                }
                // If the top asteroid is positive and larger, the negative asteroid gets destroyed.
            }
        }

        return st;  // The stack now contains the remaining asteroids after all collisions.
    }
};

