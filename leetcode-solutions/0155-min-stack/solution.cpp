class MinStack {
private:
    stack<long long> st;
    long long mini;  // Holds the current minimum element

public:
    MinStack() {}

    // Push operation
    void push(int val) {
        if (st.empty()) {
            // First element, initialize mini
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                // Push a modified value and update mini
                st.push(2LL * val - mini);
                mini = val;
            } else {
                // Normal push
                st.push(val);
            }
        }
    }

    // Pop operation
    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();
        
        if (topVal < mini) {
            // If the top is a modified value, recover the previous mini
            mini = 2LL * mini - topVal;
        }
    }

    // Top operation
    int top() {
        long long topVal = st.top();
        // If the top value is less than mini, it was modified
        return (topVal < mini) ? mini : topVal;
    }

    // GetMin operation, O(1) time and space
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
