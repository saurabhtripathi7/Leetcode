class Solution {
public:
    int largestRectangleArea(vector<int> &histo) {
    stack<int> st;          // Stack to store the indices of histogram bars
    int maxA = 0;           // Variable to store the maximum area found
    int n = histo.size();   // Get the size of the histogram (number of bars)
    
    // Iterate through all bars (including an extra loop at the end for any remaining bars in the stack)
    for (int i = 0; i <= n; i++) {

        // Process when current bar is smaller than the bar on top of the stack 
        // OR when we've reached the end of the histogram (i == n)
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {

            int height = histo[st.top()]; // Get the height of the bar at the top of the stack
            st.pop();                     // Remove the index from the stack

            int width;
            // If the stack is empty, this bar can extend all the way back to the start (width = i)
            if (st.empty())
                width = i;
            else
                // Otherwise, the width is the distance between the current index (i) and 
                // the index below the popped element in the stack (st.top()), minus one
                width = i - st.top() - 1;
            
            // Calculate the area (width * height) and update maxA if the new area is larger
            maxA = max(maxA, width * height);
        }
        
        // Push the current index onto the stack (to be processed later)
        st.push(i);
    }
    
    // Return the maximum area found
    return maxA;
}

};
