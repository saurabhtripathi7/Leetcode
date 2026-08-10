class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int i = 0;
        int maxArea = 0;
        while(i <= n){
            while(!st.empty() && (i==n || heights[st.top()] > heights[i])){
                int currHeight = heights[st.top()]; 
                st.pop();
                int width;
                if(st.empty()) width = i; // treat currIdx as prevSmaller
                else width = i-st.top()-1;;
                maxArea = max(maxArea, currHeight*width);
            }
            st.push(i);
            i++;
        }
        return maxArea;
    }
};